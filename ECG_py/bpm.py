# --- START OF FILE bpm.py ---
import numpy as np
from scipy.signal import butter, lfilter, filtfilt, lfilter_zi
from read import read_ecg
from clean import clean_ecg
from DWT import wavelet_denoise_ecg
import matplotlib.pyplot as plt

# 字体设置，支持中文显示
plt.rcParams['font.sans-serif'] = ['SimHei', 'Microsoft YaHei', 'WenQuanYi Micro Hei']
plt.rcParams['axes.unicode_minus'] = False


class PanTompkinsBPM:
    def __init__(self, ecg: read_ecg):
        """
        Pan-Tompkins BPM检测器

        参数:
        - ecg: read_ecg对象
        """
        self.ecg = ecg.copy()
        self.fs = self.ecg.fs
        self.win_len = int(round(0.150 * self.fs))  # 积分窗口长度 (150ms)

        # 设计滤波器系数
        self._design_filters()

        # 重置状态
        self._reset_state()

    def _design_filters(self):
        """设计所有滤波器系数"""
        # 1. 带通滤波器 (5-15 Hz)
        nyquist = self.fs / 2
        self.b_bp, self.a_bp = butter(2, [5 / nyquist, 15 / nyquist], btype='band')

        # 2. 5点微分器系数
        self.b_d = np.array([1, 2, 0, -2, -1]) / 8
        self.a_d = np.array([1])

        # 3. 滑动积分器系数
        self.b_ma = np.ones(self.win_len) / self.win_len
        self.a_ma = np.array([1])

    def _reset_state(self):
        """重置所有状态变量"""
        # 滤波器初始状态 (使用 lfilter_zi 避免初始阶跃响应)
        self.zi_d = lfilter_zi(self.b_d, self.a_d) * 0.0
        self.zi_ma = lfilter_zi(self.b_ma, self.a_ma) * 0.0

        # 阈值和水平变量
        self.SIG_LEV = 0.0
        self.NOISE_LEV = 0.0
        self.THR_SIG = 0.0
        self.THR_NOISE = 0.0

        # 运行时的动态心率相关 (用于算法内部回溯搜索判断)
        self.samples_since_last_qrs = 0
        self.rr_buffer = np.zeros(8)
        self.rr_ptr = 0

        # 第一段数据标记
        self.first_run = True

        # R峰位置存储
        self.r_peaks = []

    def _auto_learn_thresholds(self, ecg_m):
        """自动学习阈值"""
        max_val = np.max(ecg_m)
        if max_val == 0:
            max_val = 1e-6

        self.THR_SIG = max_val / 3
        self.THR_NOISE = np.mean(ecg_m) / 2
        self.SIG_LEV = self.THR_SIG
        self.NOISE_LEV = self.THR_NOISE

    def detect(self):
        """
        检测R峰并计算BPM

        返回:
        - r_peaks: R峰位置索引
        - bpm: 心率
        """
        ecg_signal = self.ecg.raw_ecg
        N = len(ecg_signal)

        # ========== 形态学处理 ==========
        # 1. 带通滤波 (5-15 Hz，filtfilt不产生相位移)
        ecg_f = filtfilt(self.b_bp, self.a_bp, ecg_signal)

        # 2. 5点微分
        ecg_d, self.zi_d = lfilter(self.b_d, self.a_d, ecg_f, zi=self.zi_d)

        # 3. 平方
        ecg_s = ecg_d ** 2

        # 4. 滑动积分
        ecg_m, self.zi_ma = lfilter(self.b_ma, self.a_ma, ecg_s, zi=self.zi_ma)

        # ========== 状态初始化 ==========
        self.r_peaks = []
        candidate_peaks = []
        last_qrs_m_idx = 0
        search_back_count = 0

        # 绝对物理不应期 (300ms) - 任何低于此间隔的峰都不可能是独立的心跳
        refractory_period = int(round(0.300 * self.fs))

        # 默认从第2个点开始自主扫描
        start_scan_idx = 2

        # ====== [新增核心] 少样本学习机制：利用前x个 .atr 标注进行向导预热 ======
        if hasattr(self.ecg, 'atr_peaks') and self.ecg.atr_peaks is not None and len(self.ecg.atr_peaks) > 1:

            # 1. 截取固定的“教练期”样本，最多使用前 10 个峰
            train_count = min(len(self.ecg.atr_peaks), 10)
            atr_peaks_train = self.ecg.atr_peaks[:train_count]

            # 2. 提取抗干扰的初始 RR 基准 (中位数)
            rr_intervals = np.diff(atr_peaks_train) / self.fs
            valid_rr = rr_intervals[(rr_intervals >= 0.3) & (rr_intervals <= 2.0)]
            if len(valid_rr) > 0:
                median_rr = np.median(valid_rr)
                # 用中位数填满整个 rr_buffer，提供一个绝对平稳的初始心率参考
                self.rr_buffer[:] = median_rr
                self.rr_ptr = 0

            # 3. 精准标定初始幅值门槛
            for i in range(len(atr_peaks_train)):
                p = atr_peaks_train[i]
                search_end = min(p + self.win_len, N)
                if p < search_end:
                    true_peak_val = np.max(ecg_m[p:search_end])

                    if i == 0:  # 绝对初始化
                        self.SIG_LEV = true_peak_val
                        self.NOISE_LEV = np.mean(ecg_m[max(0, p - self.win_len):p]) if p > 0 else true_peak_val * 0.1
                    else:  # 自适应学习
                        self.SIG_LEV = 0.125 * true_peak_val + 0.875 * self.SIG_LEV
                        prev_p = atr_peaks_train[i - 1]
                        midpoint = prev_p + (p - prev_p) // 2
                        noise_start = midpoint
                        noise_end = min(midpoint + int(0.05 * self.fs), p)
                        if noise_end > noise_start:
                            noise_val = np.mean(ecg_m[noise_start:noise_end])
                            self.NOISE_LEV = 0.125 * noise_val + 0.875 * self.NOISE_LEV

            self.THR_SIG = self.NOISE_LEV + 0.25 * (self.SIG_LEV - self.NOISE_LEV)
            self.THR_NOISE = 0.5 * self.THR_SIG

            # 4. 算法正式接管前的状态预设
            self.r_peaks.extend(atr_peaks_train)

            last_qrs_m_idx = atr_peaks_train[-1]
            start_scan_idx = min(N - 1, atr_peaks_train[-1] + self.win_len)
            self.samples_since_last_qrs = start_scan_idx - last_qrs_m_idx

            self.first_run = False
        # =========================================================================

        # ========== 第一段数据自动量程学习 (无 .atr 时的默认兜底) ==========
        if self.first_run:
            learn_len = min(len(ecg_m), int(2.0 * self.fs))
            self._auto_learn_thresholds(ecg_m[:learn_len])
            self.first_run = False

        # ========== 决策规则 (算法完全自主运行，从 start_scan_idx 扫描至结尾) ==========
        for i in range(start_scan_idx, N - 1):
            self.samples_since_last_qrs += 1

            if ecg_m[i] > ecg_m[i - 1] and ecg_m[i] >= ecg_m[i + 1]:
                current_peak = ecg_m[i]

                # 实时获取当前基准 RR 间期 (动态更新)
                valid_rr = self.rr_buffer[self.rr_buffer > 0]
                if len(valid_rr) > 0:
                    mean_rr_samples = int(np.mean(valid_rr) * self.fs)
                else:
                    mean_rr_samples = int(self.fs)  # 默认兜底 1 秒 (60 BPM)

                # --- 漏检复检 (Search-back) 逻辑 ---
                if self.samples_since_last_qrs > int(1.66 * mean_rr_samples) and search_back_count < 3:
                    if len(candidate_peaks) > 0:
                        best_cand_idx, best_cand_val = max(candidate_peaks, key=lambda x: x[1])
                        thr_search = self.THR_SIG * 0.5

                        if best_cand_val > thr_search:
                            search_range = 1
                            s_range = max(0, best_cand_idx - int(self.win_len * search_range))
                            e_range = best_cand_idx

                            if e_range > s_range:
                                actual_peak_idx = np.argmax(np.abs(ecg_f[s_range:e_range])) + s_range

                                if len(self.r_peaks) == 0 or (actual_peak_idx - self.r_peaks[-1]) > refractory_period:
                                    self.r_peaks.append(actual_peak_idx)

                                    rr_sec = (best_cand_idx - last_qrs_m_idx) / self.fs
                                    if 0.3 <= rr_sec <= 2.0:
                                        self.rr_buffer[self.rr_ptr] = rr_sec
                                        self.rr_ptr = (self.rr_ptr + 1) % 8
                                    last_qrs_m_idx = best_cand_idx

                                    self.SIG_LEV = 0.25 * best_cand_val + 0.75 * self.SIG_LEV
                                    self.THR_SIG = self.NOISE_LEV + 0.25 * (self.SIG_LEV - self.NOISE_LEV)
                                    self.THR_NOISE = 0.5 * self.THR_SIG

                                    self.samples_since_last_qrs = i - best_cand_idx
                                    candidate_peaks.clear()
                                    search_back_count = 0
                                else:
                                    candidate_peaks.clear()
                                    search_back_count += 1
                        else:
                            search_back_count += 1
                            candidate_peaks.clear()

                # --- 正常局部最大值检测 ---
                # 只有度过了 300ms 的绝对物理不应期才考虑做标记
                if self.samples_since_last_qrs > refractory_period:

                    if current_peak > self.THR_SIG:
                        is_t_wave = False

                        # 动态 T 波防波堤 (Dynamic T-Wave Window)
                        # 当心率变慢(mean_rr变长)时，T波会更晚出现，此时将鉴别窗口拓展到 75% 的 RR 间期
                        # 当心率较快时，保障最低 360ms 的经典安全鉴别期
                        t_wave_window = max(int(round(0.360 * self.fs)), int(0.75 * mean_rr_samples))

                        # 在动态窗口内发生的波峰，面临更严苛的考核（防T波误判同时放行早搏）
                        if self.samples_since_last_qrs < t_wave_window:
                            if current_peak < 0.5 * self.SIG_LEV:
                                is_t_wave = True

                        if not is_t_wave:
                            search_range = 1
                            search_start = max(0, i - int(self.win_len * search_range))
                            search_end = i

                            if search_end > search_start:
                                actual_peak_idx = np.argmax(np.abs(ecg_f[search_start:search_end])) + search_start

                                if len(self.r_peaks) == 0 or (actual_peak_idx - self.r_peaks[-1]) > refractory_period:
                                    self.SIG_LEV = 0.125 * current_peak + 0.875 * self.SIG_LEV

                                    rr_sec = self.samples_since_last_qrs / self.fs
                                    if 0.3 <= rr_sec <= 2.0:
                                        self.rr_buffer[self.rr_ptr] = rr_sec
                                        self.rr_ptr = (self.rr_ptr + 1) % 8

                                    self.r_peaks.append(actual_peak_idx)
                                    last_qrs_m_idx = i
                                    self.samples_since_last_qrs = 0
                                    candidate_peaks.clear()
                                    search_back_count = 0
                                else:
                                    self.NOISE_LEV = 0.125 * current_peak + 0.875 * self.NOISE_LEV
                                    candidate_peaks.append((i, current_peak))
                            else:
                                self.NOISE_LEV = 0.125 * current_peak + 0.875 * self.NOISE_LEV
                                candidate_peaks.append((i, current_peak))
                        else:
                            self.NOISE_LEV = 0.125 * current_peak + 0.875 * self.NOISE_LEV
                            candidate_peaks.append((i, current_peak))

                    elif current_peak > self.THR_NOISE:
                        self.NOISE_LEV = 0.125 * current_peak + 0.875 * self.NOISE_LEV
                        candidate_peaks.append((i, current_peak))

                    self.THR_SIG = self.NOISE_LEV + 0.25 * (self.SIG_LEV - self.NOISE_LEV)
                    self.THR_NOISE = 0.5 * self.THR_SIG

        # ========== 心率计算 ==========
        if len(self.r_peaks) > 1:
            rr_intervals_all = np.diff(self.r_peaks) / self.fs
            if len(rr_intervals_all) > 0:
                bpm = 60 / np.mean(rr_intervals_all)
            else:
                bpm = 0
        else:
            bpm = 0

        self.bpm = bpm

        return self.r_peaks, bpm

    def get_ecg_with_peaks(self):
        """返回带有R峰标记的ECG对象"""
        return self.ecg

    def plot_result(self, start_time=0, end_time=10):
        """绘制检测结果"""
        # 获取时间范围
        start_idx = int(start_time * self.fs)
        end_idx = int(end_time * self.fs)

        time = self.ecg.tm[start_idx:end_idx]
        signal = self.ecg.raw_ecg[start_idx:end_idx]

        # 筛选该时间范围内的R峰
        peaks_in_range = [p for p in self.r_peaks if start_idx <= p < end_idx]
        peaks_time = self.ecg.tm[peaks_in_range]
        peaks_value = self.ecg.raw_ecg[peaks_in_range]

        plt.figure(figsize=(14, 6))
        plt.plot(time, signal, 'b', linewidth=0.8, label='ECG信号')
        plt.plot(peaks_time, peaks_value, 'ro', markersize=6,
                 label=f'R峰 (心率: {self.bpm:.1f} BPM)')
        plt.xlabel('时间 (秒)')
        plt.ylabel('幅值 (mV)')
        plt.title('ECG R峰检测结果')
        plt.legend()
        plt.grid(True)
        plt.xlim(start_time, end_time)
        plt.tight_layout()
        plt.show()


# demo
if __name__ == "__main__":
    ecg = read_ecg()
    ecg_clean = clean_ecg(ecg).apply_filter()
    ecg_DWT = wavelet_denoise_ecg(ecg_clean).denoise()

    # 可视化结果
    detector = PanTompkinsBPM(ecg_DWT)
    r_peaks, bpm = detector.detect()
    print(f"检测到 {len(r_peaks)} 个R峰")
    print(f"心率: {bpm:.1f} BPM")

    # 绘图
    detector.plot_result(start_time=0, end_time=20)