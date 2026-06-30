import numpy as np
import matplotlib.pyplot as plt
from read import read_ecg
from clean import clean_ecg
import pywt

class wavelet_denoise_ecg:
    def __init__(self, ecg : read_ecg,  wavelet='db8', level=5):
        """
        小波去噪类

        参数:
        - ecg: ECG信号 
        - fs: 采样频率 (Hz)
        - wavelet: 小波基, 默认'db8'
        - level: 分解层数, 默认5
        """
        self.ecg = ecg.copy()
        self.fs = self.ecg.fs
        self.wavelet = wavelet
        self.level = level
        self.tm = self.ecg.tm
        self.denoised_signal = None
        self.coeffs = None
        self.decomposition = None
        
    def denoise(self, k=0.15, method='hard') -> read_ecg:
        """
        小波去噪主函数
        
        参数:
        - k: 阈值系数,默认0.25
        - method: 阈值方法，'soft'(软阈值) 或 'hard'(硬阈值)
        
        返回:
        - denoised_signal: 去噪后的信号
        """
        # 小波分解
        self.coeffs = pywt.wavedec(self.ecg.raw_ecg, wavelet=self.wavelet, level=self.level)
        
        # 复制系数用于去噪
        coeffs_denoised = list(self.coeffs)
        
        # 对各层细节系数进行阈值处理
        for level in range(1, self.level + 1):
            # 获取当前层的细节系数
            detail_coeffs = coeffs_denoised[level]
            
            # 计算噪声标准差 (使用median absolute deviation)
            sigma = np.median(np.abs(detail_coeffs)) / 0.6745
            
            # 计算阈值
            thr = k * sigma * np.sqrt(2 * np.log(len(detail_coeffs)))
            
            # 应用阈值
            if method == 'soft':
                # 软阈值
                coeffs_denoised[level] = self._soft_threshold(detail_coeffs, thr)
            elif method == 'hard':
                # 硬阈值
                coeffs_denoised[level] = self._hard_threshold(detail_coeffs, thr)
            else:
                raise ValueError("method must be 'soft' or 'hard'")
        # 重构信号
        self.denoised_signal = pywt.waverec(coeffs_denoised, self.wavelet)
        
        # 确保长度一致（由于边界处理可能长度略有不同）
        if len(self.denoised_signal) > len(self.ecg.raw_ecg):
            self.denoised_signal = self.denoised_signal[:len(self.ecg.raw_ecg)]
        elif len(self.denoised_signal) < len(self.ecg.raw_ecg):
            self.denoised_signal = np.pad(self.denoised_signal, 
                                         (0, len(self.ecg.raw_ecg) - len(self.denoised_signal)), 
                                         'edge')
            
        self.ecg.raw_ecg = self.denoised_signal
        return self.ecg
    
    def _soft_threshold(self, coeffs, threshold):
        """软阈值函数"""
        return np.sign(coeffs) * np.maximum(np.abs(coeffs) - threshold, 0)
    
    def _hard_threshold(self, coeffs, threshold):
        """硬阈值函数"""
        return coeffs * (np.abs(coeffs) > threshold)
   
# demo
if __name__ == "__main__":
    ecg = read_ecg()
    ecg_clean = clean_ecg(ecg).apply_filter()
    ecg_DWT = wavelet_denoise_ecg(ecg_clean).denoise()

    def plot_ecg_signals(raw_ecg, filtered_ecg, Fs, title="ECG Signal"):
        """
        绘制ECG信号
        """
        time = np.arange(len(raw_ecg)) / Fs

        plt.figure(figsize=(12, 6))

        plt.subplot(2, 1, 1)
        plt.plot(time, raw_ecg, 'b-', linewidth=0.5)
        plt.title(f'{title} - Raw ECG')
        plt.xlabel('Time (s)')
        plt.ylabel('Amplitude')
        plt.grid(True)

        plt.subplot(2, 1, 2)
        plt.plot(time, filtered_ecg, 'r-', linewidth=0.5)
        plt.title(f'{title} - Filtered ECG')
        plt.xlabel('Time (s)')
        plt.ylabel('Amplitude')
        plt.grid(True)

        plt.tight_layout()
        plt.show()


    # 绘制信号
    plot_ecg_signals(ecg.filtered_ecg, ecg_DWT.raw_ecg, ecg_DWT.fs)
