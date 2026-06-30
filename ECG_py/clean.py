import numpy as np
from scipy.signal import ellip, iirnotch, filtfilt,butter,cheby1,cheby2
import matplotlib.pyplot as plt
from read import read_ecg

class clean_ecg:
    def __init__(self, ecg: read_ecg):
        self.ecg = ecg.copy()
        self.Fs = self.ecg.fs
        self.bandpass_config = {
            'type': 'ellip',  
            'fc_low': 0.5, 
            'fc_high': 40, 
            'order': 4,
            # 椭圆滤波器参数
            'rp': 0.5,      # 通带最大衰减 (ellip, cheby1)
            'rs': 40,       # 阻带最小衰减 (ellip, cheby2)
            # 切比雪夫II型专用参数
            'rs_cheby2': 40, # 切比雪夫II型阻带衰减
        }
        self.notch_filter_config = {'f0': 50, 'Q': 2}

    def _filter_bandpass(self):
        """
        支持类型:
        - 'butter': 巴特沃斯滤波器(最平滑的频率响应)
        - 'cheby1': 切比雪夫I型(通带等波纹,阻带平坦)
        - 'cheby2': 切比雪夫II型(通带平坦,阻带等波纹)
        - 'ellip': 椭圆滤波器（通带和阻带均为等波纹）
        """
        config = self.bandpass_config
        filter_type = config['type']
        fc_low = config['fc_low']
        fc_high = config['fc_high']
        order = config['order']
        nyquist = self.Fs / 2
        low = fc_low / nyquist
        high = fc_high / nyquist
        Wn = [low, high]

        if filter_type == 'butter':
            b, a = butter(order, Wn, btype='band')
            
        elif filter_type == 'cheby1':
            rp = config.get('rp', 0.5)
            b, a = cheby1(order, rp, Wn, btype='band')
            
        elif filter_type == 'cheby2':
            rs = config.get('rs_cheby2', 40)
            b, a = cheby2(order, rs, Wn, btype='band')
            
        elif filter_type == 'ellip':
            rp = config.get('rp', 0.5)
            rs = config.get('rs', 40)
            b, a = ellip(order, rp, rs, Wn, btype='band')

        return b, a

    def _notch_filter(self):
        """
        设计IIR陷波滤波器用于去除工频干扰

        参数:
        - Fs: 采样频率 (Hz)
        - f0: 陷波中心频率 (Hz) - 通常是50Hz或60Hz
        - Q: 品质因数 (控制陷波宽度)

        返回:
        - b, a: 滤波器系数
        """
        config = self.notch_filter_config
        f0 = self.notch_filter_config['f0']
        Q = self.notch_filter_config['Q']
        w0 = f0 / (self.Fs / 2)

        b, a = iirnotch(w0, Q)
        return b, a

    def set_config(self, name, **args):
        """
        设置滤波器配置参数
        示例:
        >>> cleaner.set_config('bandpass', type='butter', fc_low=0.5, fc_high=35, order=4)
        >>> cleaner.set_config('bandpass', type='cheby1', fc_low=0.5, fc_high=35, rp=0.5)
        >>> cleaner.set_config('bandpass', type='cheby2', fc_low=0.5, fc_high=35, rs_cheby2=40)
        >>> cleaner.set_config('bandpass', type='ellip', fc_low=0.5, fc_high=35, rp=0.5, rs=40)
        >>> cleaner.set_config('iirnotch', f0=60, Q=50)
        """
        if name == 'bandpass':
            for key, value in args.items():
                if key in self.bandpass_config:
                    self.bandpass_config[key] = value
        elif name == 'iirnotch':
            for key, value in args.items():
                if key in self.notch_filter_config:
                    self.notch_filter_config[key] = value
        else:
            raise ValueError(f"name must be 'ellip' or 'iirnotch', got {name}")

    def apply_filter(self):
        bb, ab = self._filter_bandpass()
        b, a = self._notch_filter()
        self.ecg.raw_ecg = filtfilt(b, a, filtfilt(bb, ab, self.ecg.raw_ecg))
        self.print_attr()
        return self.ecg

    def print_attr(self):
        config = self.bandpass_config
        print(f"\n滤波器参数:")
        print(f"  带通类型: {config['type']}")
        print(f"  带通: order={config['order']}, "
              f"fc=[{config['fc_low']}, {config['fc_high']}]Hz")
        
        # 根据滤波器类型显示不同参数
        if config['type'] == 'ellip':
            print(f"        Rp={config['rp']}dB (通带波纹), Rs={config['rs']}dB (阻带衰减)")
        elif config['type'] == 'cheby1':
            print(f"        Rp={config['rp']}dB (通带波纹)")
        elif config['type'] == 'cheby2':
            print(f"        Rs={config['rs_cheby2']}dB (阻带衰减)")
            
        print(f"  陷波: f0={self.notch_filter_config['f0']}Hz, Q={self.notch_filter_config['Q']}")
        print(f"  采样率: {self.Fs}Hz")
        print(f"  滤波完成，输出信号长度: {len(self.ecg.raw_ecg)}")


# demo
if __name__ == '__main__':
    ecg = read_ecg()
    ecg_clean = clean_ecg(ecg).apply_filter()
    # 可视化结果

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
    plot_ecg_signals(ecg.raw_ecg, ecg_clean.raw_ecg, ecg_clean.fs)
