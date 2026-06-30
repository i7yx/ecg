# evaluate.py - 修复版（时域归一化余弦相似度）
import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import welch
from scipy.integrate import trapezoid
import pywt

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei', 'SimHei']
plt.rcParams['axes.unicode_minus'] = False

class DenoiseEvaluator:
    """去噪效果评估器 - 精简折线图版"""
    
    def __init__(self, fs):
        self.fs = fs
    
    def _get_layer_info(self, coeffs, level):
        """获取各层信息"""
        layers = []
        
        layers.append({
            'name': f'A{level}',
            'index': 0,
            'is_approx': True,
            'freq_low': 0,
            'freq_high': self.fs / (2 ** (level + 1))
        })
        
        for i in range(1, level + 1):
            actual_layer = level - i + 1
            freq_low = self.fs / (2 ** (actual_layer + 1))
            freq_high = self.fs / (2 ** actual_layer)
            layers.append({
                'name': f'D{actual_layer}',
                'index': i,
                'actual_layer': actual_layer,
                'freq_low': freq_low,
                'freq_high': freq_high
            })
        
        return layers
    
    def compute_time_domain_similarity(self, signal1, signal2):
        """
        时域波形相似度计算（归一化后计算余弦相似度）
        
        参数:
        - signal1: 参考信号（如滤波后信号）
        - signal2: 待评估信号（如小波去噪后信号）
        
        返回:
        - cosine_similarity: 余弦相似度（1表示完全相同）
        - similarity_score: 相似度评分（0-100）
        """
        # 取相同长度
        min_len = min(len(signal1), len(signal2))
        s1 = signal1[:min_len]
        s2 = signal2[:min_len]
        
        # ========== 归一化（去除幅值影响，保留波形形状） ==========
        # 方法：减去均值后除以标准差（Z-score 标准化）
        s1_norm = (s1 - np.mean(s1)) / (np.std(s1) + 1e-10)
        s2_norm = (s2 - np.mean(s2)) / (np.std(s2) + 1e-10)
        
        # ========== 计算余弦相似度 ==========
        dot_product = np.sum(s1_norm * s2_norm)
        norm1 = np.sqrt(np.sum(s1_norm ** 2))
        norm2 = np.sqrt(np.sum(s2_norm ** 2))
        cosine_similarity = dot_product / (norm1 * norm2 + 1e-10)
        
        # 限制在 [-1, 1] 范围内
        cosine_similarity = np.clip(cosine_similarity, -1, 1)
        
        # 相似度评分（0-100）
        similarity_score = (cosine_similarity + 1) / 2 * 100
        
        # 波形失真度（0-100，越小越好）
        distortion_score = 100 - similarity_score
        
        return {
            'cosine_similarity': cosine_similarity,
            'similarity_score': similarity_score,
            'distortion_score': distortion_score
        }
    
    def compute_spectral_comparison(self, original, denoised):
        """
        频域分析：能量比值折线图 + 频谱能量指标
        """
        f, psd_orig = welch(original, self.fs, nperseg=1024)
        _, psd_den = welch(denoised, self.fs, nperseg=1024)
        
        ratio = psd_den / (psd_orig + 1e-10)
        
        # 计算频段能量指标
        ecg_idx = (f >= 0.5) & (f <= 40)
        energy_orig_ecg = trapezoid(psd_orig[ecg_idx], f[ecg_idx])
        energy_den_ecg = trapezoid(psd_den[ecg_idx], f[ecg_idx])
        ecg_energy_ratio = energy_den_ecg / energy_orig_ecg if energy_orig_ecg > 0 else 0
        
        noise_idx = (f >= 40) & (f <= 100)
        energy_orig_noise = trapezoid(psd_orig[noise_idx], f[noise_idx])
        energy_den_noise = trapezoid(psd_den[noise_idx], f[noise_idx])
        noise_suppression = 10 * np.log10(energy_orig_noise / energy_den_noise) if energy_den_noise > 0 else 0
        
        metrics = {
            'ecg_energy_ratio': ecg_energy_ratio,
            'noise_suppression_db': noise_suppression,
        }
        
        # 创建折线图
        fig, ax = plt.subplots(figsize=(4, 3))
        
        ax.plot(f, ratio, 'g-', linewidth=1.2)
        ax.axhline(y=1, color='r', linestyle='--', linewidth=1)
        ax.axvspan(0.5, 40, alpha=0.15, color='blue', label='ECG频段')
        ax.axvspan(40, 100, alpha=0.15, color='gray', label='噪声频段')
        
        ax.set_xlabel('频率 (Hz)', fontsize=9)
        ax.set_ylabel('能量比值', fontsize=9)
        ax.set_title('频段能量比值', fontsize=10)
        ax.set_xlim(0, 100)
        ax.set_ylim(0, 1.5)
        ax.tick_params(labelsize=8)
        ax.grid(True, alpha=0.3)
        
        info_text = f'ECG保持: {ecg_energy_ratio*100:.0f}%\n噪声抑制: {noise_suppression:.0f}dB'
        ax.text(0.6, 0.05, info_text, transform=ax.transAxes, fontsize=6.5, 
                bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.7))
        
        plt.tight_layout()
        return fig, metrics
    
    def compute_wavelet_comparison(self, original, denoised, wavelet='db8', level=5, reference_signal=None):
        """
        小波域分析：分析 D 数字最大的层（最低频细节层）
        
        参数:
        - reference_signal: 参考信号（如滤波后的信号），用于计算时域失真度
        """
        coeffs_orig = pywt.wavedec(original, wavelet, level=level)
        coeffs_den = pywt.wavedec(denoised, wavelet, level=level)
        
        target_layer = level
        target_idx = 1
        
        layer_orig = coeffs_orig[target_idx]
        layer_den = coeffs_den[target_idx]
        
        # 能量保持率
        energy_orig = np.sum(layer_orig ** 2)
        energy_den = np.sum(layer_den ** 2)
        energy_ratio = energy_den / energy_orig if energy_orig > 0 else 0
        
        # 平均衰减率
        mean_orig = np.mean(np.abs(layer_orig))
        mean_den = np.mean(np.abs(layer_den))
        mean_attenuation = (mean_orig - mean_den) / mean_orig * 100 if mean_orig > 0 else 0
        
        # Top100衰减率
        n = min(100, len(layer_orig))
        sorted_orig = np.sort(np.abs(layer_orig))[::-1][:n]
        sorted_den = np.sort(np.abs(layer_den))[::-1][:n]
        top100_attenuation = np.mean((sorted_orig - sorted_den) / sorted_orig) * 100 if np.mean(sorted_orig) > 0 else 0
        
        # 严重衰减率
        decay_ratio = np.abs(layer_den) / (np.abs(layer_orig) + 1e-10)
        severe_decay = np.sum(decay_ratio < 0.5) / len(layer_orig) * 100
        
        # 完全置零率
        zero_ratio = np.sum(np.abs(layer_den) == 0) / len(layer_orig) * 100
        
        # ========== 时域波形相似度（如果提供了参考信号） ==========
        time_domain_metrics = {}
        if reference_signal is not None:
            time_domain_metrics = self.compute_time_domain_similarity(reference_signal, denoised)
        
        freq_low = self.fs / (2 ** (target_layer + 1))
        freq_high = self.fs / (2 ** target_layer)
        
        metrics = {
            f'd{target_layer}_energy_ratio': energy_ratio,
            f'd{target_layer}_mean_attenuation': mean_attenuation,
            f'd{target_layer}_top100_attenuation': top100_attenuation,
            f'd{target_layer}_severe_decay_ratio': severe_decay,
            f'd{target_layer}_zero_ratio': zero_ratio,
            'total_energy_ratio': energy_ratio,
        }
        
        # 合并时域指标
        metrics.update(time_domain_metrics)
        
        # 创建折线图
        fig, ax = plt.subplots(figsize=(5, 4))
        
        sorted_orig_all = np.sort(np.abs(layer_orig))[::-1]
        sorted_den_all = np.sort(np.abs(layer_den))[::-1]
        
        n_plot = min(100, len(sorted_orig_all))
        ax.plot(sorted_orig_all[:n_plot], 'b-', linewidth=1, label='原始信号')
        ax.plot(sorted_den_all[:n_plot], 'r-', linewidth=1, label='去噪信号')
        
        ax.set_xlabel('系数排序 (前100个最大系数)', fontsize=9)
        ax.set_ylabel('系数幅值', fontsize=9)
        ax.set_title(f'D{target_layer}层系数对比 ({freq_low:.1f}-{freq_high:.1f}Hz)', fontsize=9)
        ax.tick_params(labelsize=8)
        ax.legend(fontsize=7)
        ax.grid(True, alpha=0.3)
        
        info_text = f'能量保持: {energy_ratio*100:.1f}%\n'
        info_text += f'Top100衰减: {top100_attenuation:.1f}%'
        
        if time_domain_metrics:
            info_text += f'失真度: {time_domain_metrics.get("distortion_score", 0):.1f}%'
        
        ax.text(0.55, 0.05, info_text, transform=ax.transAxes, fontsize=7, 
                bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.7),
                verticalalignment='bottom')
        
        plt.tight_layout()
        return fig, metrics
    
    def compute_wavelet_coefficient_analysis(self, original, denoised, wavelet='db8', level=5):
        """详细分析小波系数的衰减情况"""
        coeffs_orig = pywt.wavedec(original, wavelet, level=level)
        coeffs_den = pywt.wavedec(denoised, wavelet, level=level)
        layers = self._get_layer_info(coeffs_orig, level)
        
        results = {}
        
        print("\n" + "=" * 100)
        print("小波系数衰减分析 (从低频到高频)")
        print("=" * 100)
        print(f"{'层数':<6} {'频段(Hz)':<22} {'能量保持':<10} {'Top100衰减':<12} {'严重衰减率':<12} {'置零率':<10}")
        print("-" * 100)
        
        for layer in layers:
            coeff_o = coeffs_orig[layer['index']]
            coeff_d = coeffs_den[layer['index']]
            
            energy_o = np.sum(coeff_o ** 2)
            energy_d = np.sum(coeff_d ** 2)
            energy_ratio = energy_d / energy_o * 100 if energy_o > 0 else 0
            
            n = min(100, len(coeff_o))
            sorted_o = np.sort(np.abs(coeff_o))[::-1][:n]
            sorted_d = np.sort(np.abs(coeff_d))[::-1][:n]
            top100_atten = np.mean((sorted_o - sorted_d) / sorted_o) * 100 if np.mean(sorted_o) > 0 else 0
            
            decay_ratio = np.abs(coeff_d) / (np.abs(coeff_o) + 1e-10)
            severe_decay = np.sum(decay_ratio < 0.5) / len(coeff_o) * 100
            zero_ratio = np.sum(np.abs(coeff_d) == 0) / len(coeff_o) * 100
            
            results[layer['name']] = {
                'energy_ratio': energy_ratio,
                'top100_attenuation': top100_atten,
                'severe_decay_ratio': severe_decay,
                'zero_ratio': zero_ratio,
            }
            
            freq_str = f"{layer['freq_low']:.1f}-{layer['freq_high']:.1f}"
            
            if layer['name'] == f'D{level}':
                marker = "⭐"
            elif layer['name'] == 'D1':
                marker = "🔴"
            else:
                marker = "  "
            
            print(f"{marker}{layer['name']:<5} {freq_str:<20} {energy_ratio:<9.1f}% {top100_atten:<11.1f}% {severe_decay:<11.1f}% {zero_ratio:<9.1f}%")
        
        print("-" * 100)
        
        max_d_layer = f'D{level}'
        max_d_results = results.get(max_d_layer, {})
        if max_d_results:
            print(f"\n⭐ {max_d_layer}层（D数字最大的层/最低频细节层）分析:")
            print(f"   • 能量保持率: {max_d_results.get('energy_ratio', 0):.1f}%")
            print(f"   • 前100大系数衰减: {max_d_results.get('top100_attenuation', 0):.1f}%")
            
            energy_keep = max_d_results.get('energy_ratio', 0)
            if energy_keep < 60:
                print(f"   ⚠️ 警告: 能量保持率过低 ({energy_keep:.1f}%)")
            elif energy_keep < 80:
                print(f"   ○ 注意: 能量保持率 {energy_keep:.1f}%")
            else:
                print(f"   ✓ QRS波能量保持良好 ({energy_keep:.1f}%)")
        
        return results
    
    def evaluate_all(self, original, denoised, reference_signal=None, wavelet='db8', level=5):
        """
        综合评估
        
        参数:
        - original: 原始信号
        - denoised: 小波去噪后信号
        - reference_signal: 参考信号（如带通滤波后的信号），用于计算时域失真度
        """
        spectral_fig, spectral_metrics = self.compute_spectral_comparison(original, denoised)
        wavelet_fig, wavelet_metrics = self.compute_wavelet_comparison(
            original, denoised, wavelet, level, reference_signal
        )
        
        metrics = {
            'ecg_energy_ratio': spectral_metrics.get('ecg_energy_ratio', 0),
            'noise_suppression_db': spectral_metrics.get('noise_suppression_db', 0),
            'total_energy_ratio': wavelet_metrics.get('total_energy_ratio', 0),
            'cosine_similarity': wavelet_metrics.get('cosine_similarity', 0),
            'similarity_score': wavelet_metrics.get('similarity_score', 0),
            'distortion_score': wavelet_metrics.get('distortion_score', 0),
        }
        
        return spectral_fig, wavelet_fig, metrics