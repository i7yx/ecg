import numpy as np
import wfdb 
import copy
import os

class read_ecg:
    def __init__(self, file_name = '../ECG_data//Person_01//rec_1', channels = [0, 1] ):
        """
        file_name example: ECG_data//ecg-id-database-1.0.0//Person_01//rec_1 (不要后缀)
        channels 默认双通道
        """
        self.index = os.path.basename(file_name) 
        self.read_ecg_wfdb(file_name = file_name, channels = channels)
        print(f"已经从 {file_name} 中读取到ECG信号")

    def read_ecg_wfdb(self, file_name, channels):
        """
        使用WFDB库读取ECG信号
        """
        self.record = wfdb.rdrecord(file_name, channels=channels)
        self.signal = self.record.p_signal
        self.fs = self.record.fs
        print(f"采样率: {self.fs} Hz")  # 添加这一行
        self.tm = np.arange(len(self.signal)) / self.fs
        self.raw_ecg = self.signal[:, 0]  # 第1通道（原始ECG）
        self.num_channels = len(channels)
        if self.num_channels > 1:
            self.filtered_ecg = self.signal[:, 1]  # 第2通道（滤波后的ECG）
        self.comments = self.record.comments

        # ====== [新增] 读取 .atr 标注文件 ======
        self.atr_peaks = None
        if os.path.exists(file_name + '.atr'):
            try:
                ann = wfdb.rdann(file_name, 'atr')

                # 标准的心跳符号白名单 (包含了正常、早搏、阻滞等所有真实心跳的R峰)
                # 过滤掉了 '+', '~', '"', 'x' 等非心跳标记
                # 将字节串解码为字符串
                valid_beat_symbols = {
                    'N', 'L', 'R', 'B', 'A', 'a', 'J', 'S', 'V',
                    'r', 'F', 'e', 'j', 'n', 'E', '/', 'f', 'Q', '?'
                }

                valid_peaks = []
                for i, sym in enumerate(ann.symbol):
                    # 关键修复：将字节串解码为字符串
                    sym_str = sym.decode('utf-8') if isinstance(sym, bytes) else sym

                    if sym_str in valid_beat_symbols:
                        valid_peaks.append(ann.sample[i])

                if valid_peaks:
                    self.atr_peaks = np.array(valid_peaks)
                    print(f"成功读取到.atr标注，共包含 {len(self.atr_peaks)} 个有效R峰")
                else:
                    print("警告: .atr文件中未找到任何标准心搏标记！")
            except Exception as e:
                print(f"读取.atr标注文件失败: {e}")
        # =======================================
        return
        
    def copy(self):
        """创建当前对象的深拷贝"""
        return copy.deepcopy(self)


#demo
if __name__ == "__main__":
    # ====== 在这里替换你的文件路径 ======
    file_path = "../ECG_data/ecg-id-database-1.0.0/Person_14/rec_3"  # 修改为你的文件路径，不含后缀
    # =================================

    import pandas as pd

    ecg_reader = read_ecg(file_name=file_path, channels=[0])

    if ecg_reader.atr_peaks is not None:
        script_dir = os.path.dirname(os.path.abspath(__file__))
        csv_path = os.path.join(script_dir, f"{ecg_reader.index}_r_peaks.csv")

        df = pd.DataFrame({
            'peak_index': ecg_reader.atr_peaks,
            'time_sec': ecg_reader.atr_peaks / ecg_reader.fs
        })

        df.to_csv(csv_path, index=False)
        print(f"已导出到: {csv_path}")
    else:
        print("未读取到 R 峰")
