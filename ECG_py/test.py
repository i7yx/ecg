import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import welch, coherence, butter, filtfilt, cheby1, ellip
from scipy.fft import fft, fftfreq
from read import read_ecg
from clean import clean_ecg
from DWT import wavelet_denoise_ecg

plt.rcParams['font.sans-serif'] = ['SimHei', 'Microsoft YaHei', 'WenQuanYi Micro Hei']
plt.rcParams['axes.unicode_minus'] = False


# ==========================================
# 频域评价指标计算类
# ==========================================
class FrequencyEvaluator:
    """频域评价器 - 用于对比不同滤波器的效果"""
    
    def __init__(self, original_signal, denoised_signal, fs):
        self.original = original_signal
        self.denoised = denoised_signal
        self.fs = fs
        self.residual = original_signal - denoised_signal
        
        # 计算功率谱密度
        self.f, self.Pxx_orig = welch(original_signal, fs, nperseg=fs*2)
        self.f, self.Pxx_den = welch(denoised_signal, fs, nperseg=fs*2)
        self.f, self.Pxx_res = welch(self.residual, fs, nperseg=fs*2)
        
    def compute_metrics(self):
        """计算所有频域评价指标"""
        metrics = {}
        
        # 定义频段
        freq_bands = {
            'very_low': (0.5, 5),      # 极低频（基线漂移）
            'p_t_wave': (5, 10),        # P波/T波频段
            'qrs': (10, 30),            # QRS波核心频段
            'high_freq': (30, 50),      # 高频细节
            'noise': (50, 100)          # 噪声频段
        }
        
        # 1. 各频段能量比（残差能量 / 原始能量）
        metrics['band_energy_ratio'] = {}
        for band_name, (low, high) in freq_bands.items():
            idx = np.where((self.f >= low) & (self.f <= high))[0]
            if len(idx) > 0:
                energy_orig = np.trapz(self.Pxx_orig[idx], self.f[idx])
                energy_res = np.trapz(self.Pxx_res[idx], self.f[idx])
                metrics['band_energy_ratio'][band_name] = (energy_res / energy_orig * 100) if energy_orig > 0 else 0
        
        # 2. 噪声抑制比 (NSR)
        noise_idx = np.where(self.f >= 45)[0]
        noise_orig = np.mean(self.Pxx_orig[noise_idx])
        noise_den = np.mean(self.Pxx_den[noise_idx])
        metrics['noise_suppression_ratio'] = 10 * np.log10(noise_orig / noise_den) if noise_den > 0 else 0
        
        # 3. 信噪比改善 (SNR Improvement)
        total_energy_orig = np.trapz(self.Pxx_orig, self.f)
        total_energy_den = np.trapz(self.Pxx_den, self.f)
        metrics['snr_improvement'] = 10 * np.log10(total_energy_orig / total_energy_den) if total_energy_den > 0 else 0
        
        # 4. 频谱失真度 (Spectral Distortion)
        # 计算去噪前后频谱的差异
        # 先归一化
        Pxx_orig_norm = self.Pxx_orig / np.max(self.Pxx_orig)
        Pxx_den_norm = self.Pxx_den / np.max(self.Pxx_den)
        metrics['spectral_distortion'] = np.sqrt(np.mean((10 * np.log10(Pxx_orig_norm + 1e-10) - 
                                                          10 * np.log10(Pxx_den_norm + 1e-10))**2))
        
        # 5. QRS 频段保持率
        qrs_energy_orig = metrics['band_energy_ratio'].get('qrs', 100)
        metrics['qrs_preservation'] = 100 - qrs_energy_orig
        
        # 6. 主频偏移 (Main Frequency Shift)
        main_freq_orig = self.f[np.argmax(self.Pxx_orig[5:]) + 5]
        main_freq_den = self.f[np.argmax(self.Pxx_den[5:]) + 5]
        metrics['main_freq_shift'] = abs(main_freq_orig - main_freq_den)
        
        # 7. 高频衰减率 (High Frequency Attenuation)
        high_freq_orig = metrics['band_energy_ratio'].get('high_freq', 0)
        metrics['high_freq_attenuation'] = high_freq_orig
        
        # 8. 整体评分 (0-100)
        score = 0
        # 噪声抑制得分 (权重 30%)
        nsr = min(30, max(0, metrics['noise_suppression_ratio'] / 2))
        score += nsr
        
        # QRS 保持得分 (权重 40%)
        qrs_score = 40 * (1 - min(1, metrics['band_energy_ratio'].get('qrs', 0) / 30))
        score += qrs_score
        
        # 频谱失真得分 (权重 30%)
        distortion_score = 30 * (1 - min(1, metrics['spectral_distortion'] / 10))
        score += distortion_score
        
        metrics['overall_score'] = score
        
        return metrics


# ==========================================
# 不同滤波器的频域对比分析
# ==========================================
class FilterComparison:
    """滤波器对比分析器"""
    
    def __init__(self, raw_ecg, fs):
        self.raw_ecg = raw_ecg
        self.fs = fs
        self.results = {}
        
    def add_filter_result(self, name, denoised_signal, params=None):
        """添加一个滤波器的结果"""
        evaluator = FrequencyEvaluator(self.raw_ecg, denoised_signal, self.fs)
        metrics = evaluator.compute_metrics()
        self.results[name] = {
            'signal': denoised_signal,
            'metrics': metrics,
            'params': params
        }
    
    def compare_all(self):
        """对比所有滤波器"""
        if not self.results:
            print("没有添加任何滤波器结果")
            return
        
        # 创建对比图表
        fig = plt.figure(figsize=(18, 12))
        
        # 1. 时域对比（前3秒）
        ax1 = plt.subplot(3, 3, 1)
        time = np.arange(min(3 * self.fs, len(self.raw_ecg))) / self.fs
        ax1.plot(time, self.raw_ecg[:len(time)], 'k-', label='原始信号', linewidth=1, alpha=0.7)
        for name, result in self.results.items():
            ax1.plot(time, result['signal'][:len(time)], 
                    label=name, linewidth=0.8, alpha=0.8)
        ax1.set_title('时域波形对比 (前3秒)')
        ax1.set_xlabel('时间 (秒)')
        ax1.set_ylabel('幅值 (mV)')
        ax1.legend(loc='upper right', fontsize=8)
        ax1.grid(True, alpha=0.3)
        
        # 2. 功率谱密度对比
        ax2 = plt.subplot(3, 3, 2)
        evaluator = FrequencyEvaluator(self.raw_ecg, self.raw_ecg, self.fs)
        ax2.semilogy(evaluator.f, evaluator.Pxx_orig, 'k-', label='原始信号', linewidth=1.5)
        for name, result in self.results.items():
            eval_tmp = FrequencyEvaluator(self.raw_ecg, result['signal'], self.fs)
            ax2.semilogy(eval_tmp.f, eval_tmp.Pxx_den, label=name, linewidth=1, alpha=0.8)
        ax2.set_title('功率谱密度对比')
        ax2.set_xlabel('频率 (Hz)')
        ax2.set_ylabel('功率谱密度')
        ax2.set_xlim(0, 100)
        ax2.legend(loc='upper right', fontsize=8)
        ax2.grid(True, alpha=0.3)
        
        # 3. 各频段残差能量占比（柱状图）
        ax3 = plt.subplot(3, 3, 3)
        bands = ['very_low', 'p_t_wave', 'qrs', 'high_freq', 'noise']
        band_labels = ['极低频\n(0.5-5Hz)', 'P/T波\n(5-10Hz)', 'QRS波\n(10-30Hz)', 
                       '高频\n(30-50Hz)', '噪声\n(50-100Hz)']
        
        x = np.arange(len(bands))
        width = 0.8 / len(self.results)
        colors = plt.cm.Set3(np.linspace(0, 1, len(self.results)))
        
        for i, (name, result) in enumerate(self.results.items()):
            ratios = [result['metrics']['band_energy_ratio'].get(band, 0) for band in bands]
            ax3.bar(x + i * width, ratios, width, label=name, color=colors[i], alpha=0.7)
        
        ax3.set_title('各频段残差能量占比 (越低越好)')