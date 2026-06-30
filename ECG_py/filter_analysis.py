"""
滤波器特性分析工具
直接使用已有的 clean.py 和 DWT.py 模块
分析带通+陷波滤波器(IIR)与小波变换滤波器(DWT)的幅频/相频特性
输出: R² 和线性回归斜率 (0.5-40Hz)
"""
import numpy as np
import matplotlib.pyplot as plt
from scipy import signal
from scipy.signal import freqz
import pywt
import warnings

warnings.filterwarnings('ignore')

# 导入您的模块
from clean import clean_ecg
from DWT import wavelet_denoise_ecg
from read import read_ecg

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei', 'SimHei', 'DejaVu Sans']
plt.rcParams['axes.unicode_minus'] = False


class FilterAnalyzer:
    """滤波器特性分析器 - 直接使用您已有的滤波器类"""

    def __init__(self, fs=500):
        self.fs = fs
        self.f_nyquist = fs / 2

        # 存储滤波器系数
        self.iir_b = None
        self.iir_a = None
        self.notch_b = None
        self.notch_a = None
        self.iir_combined_b = None
        self.iir_combined_a = None

    def extract_iir_coefficients(self):
        """从 clean_ecg 类中提取 IIR 滤波器的系数"""

        # 创建一个临时的 ECG 对象
        class MockECG:
            def __init__(self, fs=500):
                self.fs = fs
                self.raw_ecg = np.zeros(1000)
                self.tm = np.arange(1000) / fs
                self.num_channels = 1
                self.comments = []

            def copy(self):
                return self

        test_ecg = MockECG(self.fs)
        cleaner = clean_ecg(test_ecg)

        # 获取带通滤波器系数
        bb, ab = cleaner._filter_bandpass()
        self.iir_b = bb
        self.iir_a = ab

        # 获取陷波滤波器系数
        b_notch, a_notch = cleaner._notch_filter()
        self.notch_b = b_notch
        self.notch_a = a_notch

        # 级联滤波器
        self.iir_combined_b = signal.convolve(bb, b_notch)
        self.iir_combined_a = signal.convolve(ab, a_notch)

        print(f"\nIIR 滤波器配置:")
        print(f"  带通: {cleaner.bandpass_config['type']}, "
              f"阶数={cleaner.bandpass_config['order']}, "
              f"通带={cleaner.bandpass_config['fc_low']}-{cleaner.bandpass_config['fc_high']}Hz")
        print(f"  陷波: {cleaner.notch_filter_config['f0']}Hz, Q={cleaner.notch_filter_config['Q']}")

        return self.iir_combined_b, self.iir_combined_a

    def compute_iir_bandpass_response(self, freqs):
        """计算 IIR 带通滤波器的频率响应"""
        if self.iir_b is None:
            self.extract_iir_coefficients()
        w, h = signal.freqz(self.iir_b, self.iir_a, worN=freqs, fs=self.fs)
        return w, h

    def compute_iir_notch_response(self, freqs):
        """计算陷波滤波器的频率响应"""
        if self.notch_b is None:
            self.extract_iir_coefficients()
        w, h = signal.freqz(self.notch_b, self.notch_a, worN=freqs, fs=self.fs)
        return w, h

    def compute_iir_combined_response(self, freqs):
        """计算 IIR 级联滤波器的频率响应"""
        if self.iir_combined_b is None:
            self.extract_iir_coefficients()
        w, h = signal.freqz(self.iir_combined_b, self.iir_combined_a, worN=freqs, fs=self.fs)
        return w, h

    def compute_dwt_response(self, freqs):
        """
        通过扫频法测量 DWT 滤波器的频率响应
        """
        responses = []
        print("正在计算 DWT 频率响应 (扫频法)...")

        # 获取 DWT 配置
        test_ecg = self._create_test_ecg()
        denoiser = wavelet_denoise_ecg(test_ecg)
        wavelet_name = denoiser.wavelet
        level = denoiser.level
        print(f"  DWT 配置: 小波基={wavelet_name}, 分解层数={level}, 阈值系数k=0.15, 软阈值")

        for i, f in enumerate(freqs):
            if f < 0.1 or f > self.fs / 2:
                responses.append(0 + 0j)
                continue

            # 生成单频信号
            t = np.arange(3000) / self.fs
            x = np.sin(2 * np.pi * f * t)

            # 应用 DWT 去噪
            ecg_obj = self._create_test_ecg()
            ecg_obj.raw_ecg = x.copy()
            denoiser = wavelet_denoise_ecg(ecg_obj, wavelet=wavelet_name, level=level)
            ecg_dwt = denoiser.denoise(k=0.15, method='soft')
            y = ecg_dwt.raw_ecg

            # 计算响应
            steady_start = len(y) // 3
            x_steady = x[steady_start:]
            y_steady = y[steady_start:]

            gain = np.std(y_steady) / (np.std(x_steady) + 1e-10)

            corr = np.correlate(y_steady, x_steady, mode='full')
            lag = np.argmax(corr) - (len(y_steady) - 1)
            phase = -2 * np.pi * f * lag / self.fs
            phase = np.arctan2(np.sin(phase), np.cos(phase))

            responses.append(gain * np.exp(1j * phase))

            if (i + 1) % 200 == 0:
                print(f"    进度: {i + 1}/{len(freqs)}")

        return np.array(freqs), np.array(responses)

    def _create_test_ecg(self):
        """创建测试用 ECG 对象"""

        class TestECG:
            def __init__(self, fs=500):
                self.fs = fs
                self.raw_ecg = None
                self.tm = None
                self.num_channels = 1
                self.comments = []

            def copy(self):
                new = TestECG(self.fs)
                new.raw_ecg = self.raw_ecg.copy() if self.raw_ecg is not None else None
                return new

        return TestECG(self.fs)

    def linear_regression_analysis(self, freqs, magnitudes, phases):
        """
        对通带 (0.5-40Hz) 进行线性回归分析

        返回:
        - mag_slope: 幅频曲线斜率 (dB/Hz)
        - mag_r2: 幅频曲线 R²
        - phase_slope: 相频曲线斜率 (°/Hz)
        - phase_r2: 相频曲线 R²
        - group_delay_ms: 群延迟 (ms)
        """
        # 只分析通带
        mask = (freqs >= 0.5) & (freqs <= 40)
        f_pass = freqs[mask]
        mag_pass = magnitudes[mask]
        phase_pass = phases[mask]

        if len(f_pass) < 5:
            return 0, 0, 0, 0, 0

        # 幅频: 转换为 dB
        mag_db = 20 * np.log10(np.abs(mag_pass) + 1e-10)

        # 幅频线性回归
        coeffs_mag = np.polyfit(f_pass, mag_db, 1)
        mag_slope = coeffs_mag[0]  # dB/Hz
        mag_fit = np.polyval(coeffs_mag, f_pass)

        ss_res_mag = np.sum((mag_db - mag_fit) ** 2)
        ss_tot_mag = np.sum((mag_db - np.mean(mag_db)) ** 2)
        mag_r2 = 1 - (ss_res_mag / ss_tot_mag) if ss_tot_mag > 0 else 0

        # 相频: 解包裹
        phase_deg = np.unwrap(phase_pass) * 180 / np.pi

        # 相频线性回归
        coeffs_phase = np.polyfit(f_pass, phase_deg, 1)
        phase_slope = coeffs_phase[0]  # °/Hz
        phase_fit = np.polyval(coeffs_phase, f_pass)

        ss_res_phase = np.sum((phase_deg - phase_fit) ** 2)
        ss_tot_phase = np.sum((phase_deg - np.mean(phase_deg)) ** 2)
        phase_r2 = 1 - (ss_res_phase / ss_tot_phase) if ss_tot_phase > 0 else 0

        # 群延迟 (ms) = -dφ/df * 1000 / 360
        group_delay_ms = -phase_slope / 360 * 1000

        return mag_slope, mag_r2, phase_slope, phase_r2, group_delay_ms


def plot_and_analyze(analyzer):
    """
    绘制特性曲线并进行回归分析
    """
    # 频率点 (线性等间距，便于回归)
    freqs = np.linspace(0.1, 100, 2000)

    print("\n" + "=" * 70)
    print("计算各滤波器频率响应...")
    print("=" * 70)

    # 计算各滤波器响应
    w_band, h_band = analyzer.compute_iir_bandpass_response(freqs)
    w_notch, h_notch = analyzer.compute_iir_notch_response(freqs)
    w_comb, h_comb = analyzer.compute_iir_combined_response(freqs)
    w_dwt, h_dwt = analyzer.compute_dwt_response(np.logspace(np.log10(0.5), np.log10(60), 500))

    # 插值 DWT 到相同频率点
    from scipy.interpolate import interp1d
    interp_mag = interp1d(w_dwt, np.abs(h_dwt), kind='linear', fill_value=0, bounds_error=False)
    interp_phase = interp1d(w_dwt, np.angle(h_dwt), kind='linear', fill_value=0, bounds_error=False)
    h_dwt_interp = interp_mag(w_comb) * np.exp(1j * interp_phase(w_comb))

    # ========== 打印回归分析结果 ==========
    print("\n" + "=" * 70)
    print("线性回归分析结果 (通带: 0.5-40Hz)")
    print("=" * 70)

    results = {}

    # 1. IIR 带通滤波器
    print("\n【1. IIR 带通滤波器】")
    mag_slope, mag_r2, phase_slope, phase_r2, gd = analyzer.linear_regression_analysis(
        w_band, np.abs(h_band), np.angle(h_band))
    print(f"  幅频特性: 斜率 = {mag_slope:.6f} dB/Hz, R² = {mag_r2:.10f}")
    print(f"  相频特性: 斜率 = {phase_slope:.4f} °/Hz, R² = {phase_r2:.10f}")
    print(f"  群延迟: {gd:.2f} ms")
    results['iir_band'] = (mag_slope, mag_r2, phase_slope, phase_r2, gd)

    # 2. IIR 级联滤波器
    print("\n【2. IIR 级联滤波器 (带通+陷波)】")
    mag_slope, mag_r2, phase_slope, phase_r2, gd = analyzer.linear_regression_analysis(
        w_comb, np.abs(h_comb), np.angle(h_comb))
    print(f"  幅频特性: 斜率 = {mag_slope:.6f} dB/Hz, R² = {mag_r2:.10f}")
    print(f"  相频特性: 斜率 = {phase_slope:.4f} °/Hz, R² = {phase_r2:.10f}")
    print(f"  群延迟: {gd:.2f} ms")
    results['iir_comb'] = (mag_slope, mag_r2, phase_slope, phase_r2, gd)

    # 3. DWT 滤波器
    print("\n【3. DWT 小波去噪】")
    mag_slope, mag_r2, phase_slope, phase_r2, gd = analyzer.linear_regression_analysis(
        w_comb, np.abs(h_dwt_interp), np.angle(h_dwt_interp))
    print(f"  幅频特性: 斜率 = {mag_slope:.6f} dB/Hz, R² = {mag_r2:.10f}")
    print(f"  相频特性: 斜率 = {phase_slope:.4f} °/Hz, R² = {phase_r2:.10f}")
    print(f"  群延迟: {gd:.2f} ms")
    results['dwt'] = (mag_slope, mag_r2, phase_slope, phase_r2, gd)

    # 4. 50Hz 陷波深度
    idx_50 = np.argmin(np.abs(w_comb - 50))
    notch_depth = 20 * np.log10(np.abs(h_comb[idx_50]) + 1e-10)
    print(f"\n【4. 特殊特性】")
    print(f"  50Hz 陷波深度: {notch_depth:.1f} dB")

    # ========== 绘制图形 ==========
    fig, axes = plt.subplots(2, 2, figsize=(14, 10))

    # 通带掩码
    mask_pass = (w_comb >= 0.5) & (w_comb <= 40)
    f_pass = w_comb[mask_pass]

    # 子图1: 通带幅频特性 (dB) 及回归线
    ax1 = axes[0, 0]
    mag_band_db = 20 * np.log10(np.abs(h_band[mask_pass]) + 1e-10)
    mag_comb_db = 20 * np.log10(np.abs(h_comb[mask_pass]) + 1e-10)
    mag_dwt_db = 20 * np.log10(np.abs(h_dwt_interp[mask_pass]) + 1e-10)

    ax1.plot(f_pass, mag_band_db, 'b-', linewidth=1.5, label='IIR带通')
    ax1.plot(f_pass, mag_comb_db, 'r-', linewidth=1.5, label='IIR级联')
    ax1.plot(f_pass, mag_dwt_db, 'm--', linewidth=1.5, label='DWT')

    # 添加回归线
    coeffs_band = np.polyfit(f_pass, mag_band_db, 1)
    coeffs_comb = np.polyfit(f_pass, mag_comb_db, 1)
    coeffs_dwt = np.polyfit(f_pass, mag_dwt_db, 1)

    ax1.plot(f_pass, np.polyval(coeffs_band, f_pass), 'b--', alpha=0.5,
             label=f'IIR带通拟合 (R²={results["iir_band"][1]:.4f})')
    ax1.plot(f_pass, np.polyval(coeffs_comb, f_pass), 'r--', alpha=0.5,
             label=f'IIR级联拟合 (R²={results["iir_comb"][1]:.4f})')
    ax1.plot(f_pass, np.polyval(coeffs_dwt, f_pass), 'm:', alpha=0.5,
             label=f'DWT拟合 (R²={results["dwt"][1]:.4f})')

    ax1.set_xlabel('频率 (Hz)')
    ax1.set_ylabel('幅度 (dB)')
    ax1.set_title('通带幅频特性及线性回归 (0.5-40Hz)')
    ax1.legend(loc='upper right', fontsize=9)
    ax1.grid(True, alpha=0.3)
    ax1.set_xlim([0.5, 40])

    # 子图2: 通带相频特性及回归线
    ax2 = axes[0, 1]
    phase_band = np.unwrap(np.angle(h_band[mask_pass])) * 180 / np.pi
    phase_comb = np.unwrap(np.angle(h_comb[mask_pass])) * 180 / np.pi
    phase_dwt = np.unwrap(np.angle(h_dwt_interp[mask_pass])) * 180 / np.pi

    ax2.plot(f_pass, phase_band, 'b-', linewidth=1.5, label='IIR带通')
    ax2.plot(f_pass, phase_comb, 'r-', linewidth=1.5, label='IIR级联')
    ax2.plot(f_pass, phase_dwt, 'm--', linewidth=1.5, label='DWT')

    # 添加回归线
    coeffs_band_p = np.polyfit(f_pass, phase_band, 1)
    coeffs_comb_p = np.polyfit(f_pass, phase_comb, 1)
    coeffs_dwt_p = np.polyfit(f_pass, phase_dwt, 1)

    ax2.plot(f_pass, np.polyval(coeffs_band_p, f_pass), 'b--', alpha=0.5,
             label=f'IIR带通拟合 (R²={results["iir_band"][3]:.6f})')
    ax2.plot(f_pass, np.polyval(coeffs_comb_p, f_pass), 'r--', alpha=0.5,
             label=f'IIR级联拟合 (R²={results["iir_comb"][3]:.6f})')
    ax2.plot(f_pass, np.polyval(coeffs_dwt_p, f_pass), 'm:', alpha=0.5,
             label=f'DWT拟合 (R²={results["dwt"][3]:.6f})')

    ax2.set_xlabel('频率 (Hz)')
    ax2.set_ylabel('相位 (度)')
    ax2.set_title('通带相频特性及线性回归 (0.5-40Hz)')
    ax2.legend(loc='upper right', fontsize=9)
    ax2.grid(True, alpha=0.3)
    ax2.set_xlim([0.5, 40])

    # 子图3: 完整幅频特性 (对数坐标)
    ax3 = axes[1, 0]
    ax3.semilogx(w_band, 20 * np.log10(np.abs(h_band) + 1e-10), 'b-', linewidth=1, label='IIR带通', alpha=0.7)
    ax3.semilogx(w_notch, 20 * np.log10(np.abs(h_notch) + 1e-10), 'g-', linewidth=1, label='陷波', alpha=0.7)
    ax3.semilogx(w_comb, 20 * np.log10(np.abs(h_comb) + 1e-10), 'r-', linewidth=1.5, label='IIR级联')
    ax3.semilogx(w_dwt, 20 * np.log10(np.abs(h_dwt) + 1e-10), 'm--', linewidth=1.5, label='DWT')
    ax3.axvspan(0.5, 40, alpha=0.2, color='gray', label='通带')
    ax3.axvline(50, color='orange', linestyle='--', alpha=0.7, label='50Hz陷波')
    ax3.set_xlabel('频率 (Hz)')
    ax3.set_ylabel('幅度 (dB)')
    ax3.set_title('完整幅频特性 (对数坐标)')
    ax3.legend(loc='lower left', fontsize=9)
    ax3.grid(True, alpha=0.3)
    ax3.set_xlim([0.1, 100])
    ax3.set_ylim([-80, 10])

    # 子图4: 完整相频特性
    ax4 = axes[1, 1]
    ax4.semilogx(w_band, np.angle(h_band, deg=True), 'b-', linewidth=1, label='IIR带通', alpha=0.7)
    ax4.semilogx(w_comb, np.angle(h_comb, deg=True), 'r-', linewidth=1.5, label='IIR级联')
    ax4.semilogx(w_dwt, np.angle(h_dwt, deg=True), 'm--', linewidth=1.5, label='DWT')
    ax4.axvspan(0.5, 40, alpha=0.2, color='gray', label='通带')
    ax4.axvline(50, color='orange', linestyle='--', alpha=0.7, label='50Hz陷波')
    ax4.set_xlabel('频率 (Hz)')
    ax4.set_ylabel('相位 (度)')
    ax4.set_title('完整相频特性')
    ax4.legend(loc='upper right', fontsize=9)
    ax4.grid(True, alpha=0.3)
    ax4.set_xlim([0.1, 100])

    plt.tight_layout()
    plt.savefig('filter_analysis.png', dpi=150, bbox_inches='tight')
    plt.show()

    print("\n图表已保存: filter_analysis.png")

    return results


def demonstrate_on_real_ecg():
    """使用真实 ECG 信号演示滤波效果"""
    print("\n" + "=" * 70)
    print("ECG 信号滤波效果演示")
    print("=" * 70)

    try:
        file_path = "../ECG_data/ecg-id-database-1.0.0/Person_01/rec_1"
        ecg = read_ecg(file_name=file_path, channels=[0])

        duration = 10
        samples = int(duration * ecg.fs)
        raw_signal = ecg.raw_ecg[:samples]

        print(f"  采样率: {ecg.fs} Hz, 分析时长: {duration} 秒")

        # IIR 滤波
        print("\n[1/2] 应用 IIR 带通+陷波滤波...")
        ecg_copy = ecg.copy()
        ecg_copy.raw_ecg = raw_signal.copy()
        cleaner = clean_ecg(ecg_copy)
        ecg_iir = cleaner.apply_filter()
        iir_signal = ecg_iir.raw_ecg

        # DWT 滤波
        print("[2/2] 应用 DWT 小波去噪...")
        denoiser = wavelet_denoise_ecg(ecg_iir)
        ecg_dwt = denoiser.denoise()
        dwt_signal = ecg_dwt.raw_ecg

        # 绘图
        t = np.arange(len(raw_signal)) / ecg.fs

        fig, axes = plt.subplots(3, 1, figsize=(14, 8))

        axes[0].plot(t, raw_signal, 'b-', linewidth=0.8)
        axes[0].set_ylabel('幅度')
        axes[0].set_title('原始 ECG 信号')
        axes[0].set_xlim([0, duration])
        axes[0].grid(True, alpha=0.3)

        axes[1].plot(t, iir_signal, 'r-', linewidth=0.8)
        axes[1].set_ylabel('幅度')
        axes[1].set_title('IIR 滤波后 (带通+陷波)')
        axes[1].set_xlim([0, duration])
        axes[1].grid(True, alpha=0.3)

        axes[2].plot(t, dwt_signal, 'g-', linewidth=0.8)
        axes[2].set_ylabel('幅度')
        axes[2].set_xlabel('时间 (s)')
        axes[2].set_title('DWT 小波去噪后')
        axes[2].set_xlim([0, duration])
        axes[2].grid(True, alpha=0.3)

        plt.tight_layout()
        plt.savefig('ecg_filter_demo.png', dpi=150, bbox_inches='tight')
        plt.show()

        print("\nECG 滤波效果图已保存: ecg_filter_demo.png")

    except Exception as e:
        print(f"ECG 演示跳过: {e}")


def main():
    """主函数"""
    print("=" * 70)
    print("滤波器特性分析工具")
    print("分析范围: 0.5-40Hz (心电图有效频带)")
    print("输出: 幅频/相频曲线的线性回归斜率 和 R²")
    print("=" * 70)

    # 创建分析器
    analyzer = FilterAnalyzer(fs=500)

    # 提取滤波器系数
    analyzer.extract_iir_coefficients()

    # 分析并绘图
    results = plot_and_analyze(analyzer)

    # ECG 演示
    demonstrate_on_real_ecg()

    print("\n" + "=" * 70)
    print("分析完成! 生成的文件:")
    print("  - filter_analysis.png: 频率响应分析图")
    print("  - ecg_filter_demo.png: ECG 滤波效果图")
    print("=" * 70)


if __name__ == "__main__":
    main()