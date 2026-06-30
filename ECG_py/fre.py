import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft, fftfreq
from read import read_ecg
from clean import clean_ecg
from DWT import wavelet_denoise_ecg
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei', 'SimHei']
plt.rcParams['axes.unicode_minus'] = False
# 加载数据
ecg = read_ecg()
ecg_clean = clean_ecg(ecg).apply_filter()
ecg_dwt = wavelet_denoise_ecg(ecg_clean).denoise(method='soft', k=0.15)

original = ecg.raw_ecg
denoised = ecg_dwt.raw_ecg
fs = ecg.fs

# 计算频谱


def get_spectrum(signal, fs):
    n = len(signal)
    fft_result = fft(signal)
    freqs = fftfreq(n, 1/fs)[:n//2]
    magnitude = np.abs(fft_result[:n//2])
    return freqs, magnitude


freqs_orig, mag_orig = get_spectrum(original, fs)
freqs_den, mag_den = get_spectrum(denoised, fs)

# 绘制
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 8))

ax1.plot(freqs_orig, mag_orig, 'r-', linewidth=1)
ax1.set_title('原始信号频谱')
ax1.set_xlabel('频率 (Hz)')
ax1.set_ylabel('幅值')
ax1.set_xlim(0.5, 60)
ax1.grid(True, alpha=0.3)

ax2.plot(freqs_den, mag_den, 'g-', linewidth=1)
ax2.set_title('小波去噪信号频谱')
ax2.set_xlabel('频率 (Hz)')
ax2.set_ylabel('幅值')
ax2.set_xlim(0.5, 60)
ax2.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()
