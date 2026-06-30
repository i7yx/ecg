import matplotlib.pyplot as plt
import os
import sys
import warnings
import io
import contextlib
import numpy as np
from PySide6.QtCore import Qt, QThread, Signal, QPointF, QRectF, QObject
from PySide6.QtGui import (QPainter, QPen, QColor, QPainterPath, QPixmap, QFont,
                           QPolygonF, QLinearGradient, QImage)
from PySide6.QtWidgets import (QApplication, QMainWindow, QWidget, QVBoxLayout,
                               QHBoxLayout, QLabel, QPushButton, QComboBox,
                               QFileDialog, QScrollArea, QFrame, QGridLayout,
                               QTextEdit, QDoubleSpinBox, QStackedWidget)
from evaluate import DenoiseEvaluator
from hrv import hrv_report
from bpm import PanTompkinsBPM
from DWT import wavelet_denoise_ecg
from clean import clean_ecg
from read import read_ecg
from matplotlib.backends.backend_agg import FigureCanvasAgg
import matplotlib
matplotlib.use('Agg')
def get_asset_path(relative_path):
    # __file__ 在 Nuitka 编译后能准确指回 exe/dist 目录所在的物理路径
    base_path = os.path.dirname(os.path.abspath(__file__))
    return os.path.join(base_path, relative_path).replace('\\', '/')
# 设置 matplotlib 中文字体
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei', 'SimHei', 'DejaVu Sans']
plt.rcParams['axes.unicode_minus'] = False

warnings.filterwarnings('ignore', module='neurokit2')
warnings.filterwarnings('ignore', module='scipy')
warnings.filterwarnings('ignore', category=RuntimeWarning)
warnings.filterwarnings('ignore', message='.*DFA_alpha2.*')
warnings.filterwarnings(
    'ignore', message='.*invalid value encountered in scalar divide.*')
warnings.filterwarnings('ignore', message='.*Glyph.*missing.*')  # 忽略字体警告
# ==========================================
# 全局主题配置 (Ultra Clean Medical Theme)
# ==========================================
COLORS = {
    "bg_main": "#F5F8F7",
    "bg_card": "#FFFFFF",
    "text_main": "#1F2A2E",
    "text_sub": "#7E8B90",
    "border": "#E7EEEE",
    "primary": "#18C29C",
    "neon_main": "#57F2D0",
    "neon_sub": "#7CFFE4",
    "success": "#31D0AA",
    "wave_bg_top": "#003B3B",
    "wave_bg_bot": "#022F2F",
    "console_bg": "#011A1A",
    "r_peak": "#8B0000"
}

arrow_path = get_asset_path('icon/arrow.png')
# ==========================================
# 默认参数配置
# ==========================================
DEFAULT_IIR_CONFIG = {
    'band_type': 'ellip',
    'fc_low': 0.5,
    'fc_high': 40,
    'order': 4,
    'notch': 50,
    'rp': 0.5,
    'rs': 40,
}

DEFAULT_DWT_CONFIG = {
    'wave': 'db8',
    'lvl': 5,
    'k': 0.15,
    'method': 'soft',
}

# ==========================================
# 辅助工具：终端日志重定向
# ==========================================


class EmittingStream(QObject):
    text_written = Signal(str)

    def __init__(self, text_written_signal):
        super().__init__()
        self.text_written.connect(text_written_signal)

    def write(self, text):
        if text.strip():
            self.text_written.emit(str(text))

    def flush(self):
        pass


# ==========================================
# 自定义 UI 组件
# ==========================================


class SoftCard(QFrame):
    """带柔和圆角与边框的极简白卡片"""

    def __init__(self, parent=None):
        super().__init__(parent)
        self.setStyleSheet(f"""
            SoftCard {{
                background-color: {COLORS['bg_card']};
                border-radius: 20px;
                border: 1px solid {COLORS['border']};
            }}
        """)


class _RingDial(QWidget):
    """极致精细的纯手工绘制直线医疗滑杆组件"""
    valueChanged = Signal(int)

    def __init__(self, min_v, max_v, default_v):
        super().__init__()
        self.setFixedSize(120, 40)
        self._min = min_v
        self._max = max_v
        self._val = default_v
        self._default_v = default_v
        self._is_dragging = False

    def value(self):
        return self._val

    def setValue(self, val):
        val = max(self._min, min(self._max, val))
        if val != self._val:
            self._val = val
            self.update()
            self.valueChanged.emit(self._val)

    def reset_to_default(self):
        self.setValue(self._default_v)

    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self._is_dragging = True
            self._update_val_from_pos(event.position())

    def mouseMoveEvent(self, event):
        if self._is_dragging:
            self._update_val_from_pos(event.position())

    def mouseReleaseEvent(self, event):
        self._is_dragging = False
        self.update()

    def _update_val_from_pos(self, pos):
        margin = 8
        x = pos.x()
        p = (x - margin) / (self.width() - margin * 2)
        p = max(0.0, min(1.0, p))
        new_val = int(round(self._min + p * (self._max - self._min)))
        self.setValue(new_val)

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)

        w, h = self.width(), self.height()
        margin = 8
        line_y = h / 2
        start_x = margin
        end_x = w - margin

        p = ((self._val - self._min) / (self._max - self._min)
             ) if self._max > self._min else 0
        current_x = start_x + p * (end_x - start_x)

        pen_bg = QPen(QColor(COLORS['border']), 2, Qt.SolidLine, Qt.RoundCap)
        painter.setPen(pen_bg)
        painter.drawLine(QPointF(start_x, line_y), QPointF(end_x, line_y))

        pen_fg = QPen(QColor(COLORS['primary']),
                      2.5, Qt.SolidLine, Qt.RoundCap)
        painter.setPen(pen_fg)
        painter.drawLine(QPointF(start_x, line_y), QPointF(current_x, line_y))

        handle_color = QColor(
            COLORS['success']) if self._is_dragging else QColor(COLORS['primary'])
        painter.setBrush(QColor("#FFFFFF"))
        painter.setPen(QPen(handle_color, 1.5))
        handle_radius = 5 if not self._is_dragging else 6.5
        painter.drawEllipse(QPointF(current_x, line_y),
                            handle_radius, handle_radius)

        if self._is_dragging:
            painter.setPen(QPen(QColor(COLORS['primary']), 1))
            painter.setBrush(QColor(COLORS['bg_card']))
            value_text = str(self._val)
            font = painter.font()
            font.setPointSize(8)
            painter.setFont(font)
            text_rect = QRectF(current_x - 15, line_y - 22, 30, 16)
            painter.drawRoundedRect(text_rect, 4, 4)
            painter.setPen(QPen(QColor(COLORS['primary'])))
            painter.drawText(text_rect, Qt.AlignCenter, value_text)


class MinimalSlider(QWidget):
    def __init__(self, name, min_v, max_v, default_v, multiplier=1.0, is_float=False):
        super().__init__()
        self.mult = multiplier
        self.is_float = is_float
        self.default_v = default_v

        layout = QHBoxLayout(self)
        layout.setContentsMargins(0, 4, 0, 4)
        layout.setSpacing(12)

        self.dial = _RingDial(min_v, max_v, default_v)
        self.dial.valueChanged.connect(lambda v: self._on_change(v))

        text_layout = QVBoxLayout()
        text_layout.setAlignment(Qt.AlignVCenter)
        text_layout.setSpacing(2)

        self.lbl_name = QLabel(name)
        self.lbl_name.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-weight: 500; font-size: 11px;")
        self.lbl_val = QLabel(self._format_val(default_v * multiplier))
        self.lbl_val.setStyleSheet(
            f"color: {COLORS['primary']}; font-weight: 600; font-size: 14px; font-family: 'Inter', sans-serif;")

        text_layout.addWidget(self.lbl_name)
        text_layout.addWidget(self.lbl_val)

        layout.addWidget(self.dial)
        layout.addLayout(text_layout)
        layout.addStretch()

    def _format_val(self, v):
        return f"{v:.2f}" if self.is_float else f"{int(v)}"

    def _on_change(self, v):
        self.lbl_val.setText(self._format_val(v * self.mult))

    def get_value(self):
        return self.dial.value() * self.mult

    def reset_to_default(self):
        self.dial.reset_to_default()


class ConfigurableComboBox(QComboBox):
    def __init__(self, default_text):
        super().__init__()
        self.default_text = default_text

    def reset_to_default(self):
        index = self.findText(self.default_text)
        if index >= 0:
            self.setCurrentIndex(index)


# ==========================================
# 医疗监护仪波形引擎
# ==========================================


class MedicalECGCanvas(QWidget):
    time_range_changed = Signal(float, float)

    def __init__(self, is_main=False):
        super().__init__()
        self.setMinimumHeight(160)
        self.is_main = is_main

        self.signal = None
        self.fs = 500
        self.peaks = None

        self.t_start = 0.0
        self.t_window = 5.0
        self.max_t = 0.0

        self.last_x = 0
        self.is_panning = False
        self.setMouseTracking(True)
        self.crosshair_pos = None

    def set_data(self, signal, fs, peaks=None):
        self.signal = signal
        self.fs = fs
        self.peaks = peaks
        self.max_t = len(signal) / fs if signal is not None else 0

        self.t_start = 0.0
        self.t_window = min(5.0, self.max_t) if self.max_t > 0 else 5.0

        self.time_range_changed.emit(
            self.t_start, self.t_start + self.t_window)
        self.update()

    def wheelEvent(self, event):
        if self.signal is None:
            return
        zoom = 0.85 if event.angleDelta().y() > 0 else 1.15
        center = self.t_start + self.t_window / 2
        self.t_window = max(0.5, min(self.t_window * zoom, self.max_t))
        self.t_start = center - self.t_window / 2
        self._constrain()
        self.time_range_changed.emit(
            self.t_start, self.t_start + self.t_window)
        self.update()

    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.is_panning = True
            self.last_x = event.position().x()

    def mouseMoveEvent(self, event):
        self.crosshair_pos = event.position()
        if self.is_panning and self.signal is not None:
            dx = event.position().x() - self.last_x
            dt = (dx / self.width()) * self.t_window
            self.t_start -= dt
            self.last_x = event.position().x()
            self._constrain()
            self.time_range_changed.emit(
                self.t_start, self.t_start + self.t_window)
        self.update()

    def mouseReleaseEvent(self, event):
        self.is_panning = False

    def leaveEvent(self, event):
        self.crosshair_pos = None
        self.update()

    def _constrain(self):
        changed = False
        if self.t_start < 0:
            self.t_start = 0
            changed = True
        if self.t_start + self.t_window > self.max_t:
            self.t_start = max(0, self.max_t - self.t_window)
            changed = True
        if self.t_window > self.max_t and self.max_t > 0:
            self.t_window = self.max_t
            self.t_start = 0
            changed = True

        if changed:
            self.time_range_changed.emit(
                self.t_start, self.t_start + self.t_window)

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)

        rect = self.rect()
        path = QPainterPath()
        path.addRoundedRect(QRectF(rect), 12, 12)
        painter.setClipPath(path)

        bg_grad = QLinearGradient(0, 0, 0, self.height())
        bg_grad.setColorAt(0, QColor(COLORS['wave_bg_top']))
        bg_grad.setColorAt(1, QColor(COLORS['wave_bg_bot']))
        painter.fillRect(rect, bg_grad)

        pad_l, pad_r, pad_t, pad_b = 45, 30, 30, 25
        draw_w = self.width() - pad_l - pad_r
        draw_h = self.height() - pad_t - pad_b

        if self.signal is None:
            return

        s_idx = max(0, int(self.t_start * self.fs))
        e_idx = min(len(self.signal), int(
            (self.t_start + self.t_window) * self.fs))
        if s_idx >= e_idx:
            return

        view_sig = self.signal[s_idx:e_idx]
        min_y, max_y = np.min(view_sig), np.max(view_sig)
        range_y = max_y - min_y if max_y != min_y else 1

        painter.setPen(QColor(255, 255, 255, 200))
        painter.setFont(QFont("Inter", 9))
        painter.drawText(10, pad_t - 12.5, "mV")
        painter.drawText(self.width() - pad_r + 10, self.height() - 7.5, "s")

        if range_y != 0:
            y_ticks = 4
            for i in range(y_ticks + 1):
                val = max_y - i * (range_y / y_ticks)
                y_pos = pad_t + i * (draw_h / y_ticks)
                painter.setPen(QColor(255, 255, 255, 200))
                painter.drawText(7.5, int(y_pos + 4), f"{val:.2f}")
                painter.setPen(QPen(QColor(255, 255, 255, 20), 1))
                painter.drawLine(pad_l, int(y_pos), pad_l + draw_w, int(y_pos))

        x_ticks = 6
        for i in range(x_ticks + 1):
            t_val = self.t_start + i * (self.t_window / x_ticks)
            x_pos = pad_l + i * (draw_w / x_ticks)
            painter.setPen(QColor(255, 255, 255, 200))
            painter.drawText(
                int(x_pos - 12), self.height() - 8, f"{t_val:.1f}")
            painter.setPen(QPen(QColor(255, 255, 255, 20), 1))
            painter.drawLine(int(x_pos), pad_t, int(x_pos), pad_t + draw_h)

        painter.setClipRect(pad_l, pad_t, draw_w, draw_h)
        step_x = draw_w / len(view_sig)

        inner_pad = draw_h * 0.1
        eff_h = draw_h - 2 * inner_pad

        pts = QPolygonF()
        for i, val in enumerate(view_sig):
            x = pad_l + i * step_x
            y = pad_t + inner_pad + eff_h - ((val - min_y) / range_y) * eff_h
            pts.append(QPointF(x, y))

        base_color = QColor(COLORS['neon_main'])
        base_color.setAlpha(25)
        painter.setPen(QPen(base_color, 6, Qt.SolidLine,
                       Qt.RoundCap, Qt.RoundJoin))
        painter.drawPolyline(pts)
        base_color.setAlpha(80)
        painter.setPen(QPen(base_color, 2, Qt.SolidLine,
                       Qt.RoundCap, Qt.RoundJoin))
        painter.drawPolyline(pts)
        painter.setPen(QPen(QColor(255, 255, 255, 220), 1.2,
                       Qt.SolidLine, Qt.RoundCap, Qt.RoundJoin))
        painter.drawPolyline(pts)

        if self.peaks is not None and len(self.peaks) > 0:
            painter.setBrush(QColor(COLORS['r_peak']))
            painter.setPen(QPen(QColor(255, 255, 255, 150)))
            for p in self.peaks:
                if s_idx <= p < e_idx:
                    px = pad_l + (p - s_idx) * step_x
                    py = pad_t + inner_pad + eff_h - \
                        ((self.signal[p] - min_y) / range_y) * eff_h
                    painter.drawEllipse(QPointF(px, py), 3, 3)


class ECGCardWidget(SoftCard):
    def __init__(self, title, is_main=False):
        super().__init__()
        layout = QVBoxLayout(self)
        layout.setContentsMargins(12, 12, 12, 12)

        header = QHBoxLayout()

        title_container = QHBoxLayout()
        title_container.setSpacing(6)
        title_container.setContentsMargins(0, 0, 0, 0)

        dot_label = QLabel("●")
        dot_label.setStyleSheet(
            f"color: {COLORS['success']}; font-size: 15px; font-weight: bold;")

        self.lbl_title = QLabel(title)
        self.lbl_title.setStyleSheet(
            f"color: {COLORS['text_main']}; font-size: 18px; font-weight: 800; font-family: 'Microsoft YaHei';")

        title_container.addWidget(dot_label)
        title_container.addWidget(self.lbl_title)
        title_container.addStretch()

        header.addLayout(title_container)

        time_style = "color: #7E8B90; font-weight: bold; font-size: 15px; margin-bottom: 3px;"
        lbl_time1 = QLabel("时间")
        time_icon = QLabel()
        icon_path = os.path.join(os.getcwd(), 'ECG_py', 'icon', 'time.png')
        pixmap = QPixmap(icon_path)
        if not pixmap.isNull():
            scaled_pixmap = pixmap.scaled(
                16, 16, Qt.KeepAspectRatio, Qt.SmoothTransformation)
            time_icon.setPixmap(scaled_pixmap)

        lbl_time1.setStyleSheet(time_style)
        lbl_time2 = QLabel(" s -")
        lbl_time2.setStyleSheet(time_style)
        lbl_time3 = QLabel(" s ")
        lbl_time3.setStyleSheet(time_style)

        spin_style = f"""
            QDoubleSpinBox {{
                border: 1px solid {COLORS['border']};
                border-radius: 5px; padding: 2px;
                background: white; color: {COLORS['text_main']}; font-weight: bold;
                max-width: 65px; min-width: 55px;
            }}
        """
        self.spin_start = QDoubleSpinBox()
        self.spin_end = QDoubleSpinBox()
        for sp in (self.spin_start, self.spin_end):
            sp.setRange(0, 99999)
            sp.setDecimals(1)
            sp.setSingleStep(1.0)
            sp.setStyleSheet(spin_style)
            sp.setButtonSymbols(QDoubleSpinBox.NoButtons)
            sp.setFocusPolicy(Qt.StrongFocus)
            sp.setKeyboardTracking(False)

        self.spin_start.editingFinished.connect(lambda: self._on_spin_changed())
        self.spin_end.editingFinished.connect(lambda: self._on_spin_changed())

        header.addStretch()
        header.addWidget(lbl_time1)
        header.addWidget(time_icon)
        header.addWidget(self.spin_start)
        header.addWidget(lbl_time2)
        header.addWidget(self.spin_end)
        header.addWidget(lbl_time3)

        self.canvas = MedicalECGCanvas(is_main=is_main)
        self.canvas.time_range_changed.connect(lambda s, e: self._on_canvas_time_changed(s, e))

        layout.addLayout(header)
        layout.addWidget(self.canvas)

        self._updating = False

    def _on_canvas_time_changed(self, start, end):
        if self._updating:
            return
        self._updating = True
        self.spin_start.setValue(start)
        self.spin_end.setValue(end)
        self._updating = False

    def _on_spin_changed(self):
        if self._updating:
            return
        self._updating = True

        s = self.spin_start.value()
        e = self.spin_end.value()

        max_time = self.canvas.max_t if self.canvas.max_t > 0 else 99999

        if s < 0:
            s = 0
            self.spin_start.setValue(s)

        if e > max_time:
            e = max_time
            self.spin_end.setValue(e)

        if e <= s:
            self.spin_start.setValue(self.canvas.t_start)
            self.spin_end.setValue(self.canvas.t_start + self.canvas.t_window)
            self._updating = False
            return

        if self.canvas.signal is not None:
            self.canvas.t_start = s
            self.canvas.t_window = e - s
            self.canvas._constrain()
            self.canvas.update()

        self._updating = False


def fig_to_pixmap(fig, width=400, height=280):
    """将 matplotlib 图转换为 QPixmap"""
    try:
        # 设置图形尺寸
        fig.set_size_inches(width/100, height/100)

        canvas = FigureCanvasAgg(fig)
        canvas.draw()

        # 获取图像数据
        buf = canvas.buffer_rgba()
        w, h = canvas.get_width_height()

        # 转换为 QImage（注意使用 bytes()）
        img = QImage(bytes(buf), w, h, QImage.Format_RGBA8888)

        # 转换为 QPixmap
        pixmap = QPixmap.fromImage(img)

        # 关闭图形释放内存
        plt.close(fig)

        return pixmap
    except Exception as e:
        print(f"转换失败: {e}")
        return None


class ProcessingEngine(QThread):
    finished = Signal(dict)

    def __init__(self, file_path, iir_p, dwt_p):
        super().__init__()
        self.file_path = file_path
        self.iir_p = iir_p
        self.dwt_p = dwt_p

    def run(self):
        try:
            print(f"> 正在加载信号源: {os.path.basename(self.file_path)}...")
            ecg = read_ecg(file_name=self.file_path, channels=[0, 1])
            raw_sig = ecg.raw_ecg
            fs = ecg.fs
            num_channels = getattr(ecg, 'num_channels', 1)
            std_sig = getattr(ecg, 'filtered_ecg', raw_sig)

            print(f"> 应用高级 {self.iir_p['band_type']} 级联滤波器...")
            cleaner = clean_ecg(ecg)
            cleaner.set_config('bandpass', type=self.iir_p['band_type'],
                               fc_low=self.iir_p['fc_low'], fc_high=self.iir_p['fc_high'],
                               order=self.iir_p['order'], rp=self.iir_p['rp'], rs=self.iir_p['rs'])
            cleaner.set_config('iirnotch', f0=self.iir_p['notch'], Q=2)
            ecg_iir = cleaner.apply_filter()

            print(
                f"> 应用 DWT 小波变换去噪 (小波基: {self.dwt_p['wave']} | 分解层数: {self.dwt_p['lvl']})...")
            denoiser = wavelet_denoise_ecg(
                ecg_iir, wavelet=self.dwt_p['wave'], level=self.dwt_p['lvl'])
            ecg_dwt = denoiser.denoise(
                k=self.dwt_p['k'], method=self.dwt_p['method'])

            print("> 运行 Pan-Tompkins 算法检测 R 峰...")
            detector = PanTompkinsBPM(ecg_dwt)
            r_peaks, bpm = detector.detect()

            hrv_res = {}
            hrv_figs = []  # 改为列表
            if len(r_peaks) > 2:
                with warnings.catch_warnings():
                    warnings.simplefilter("ignore")
                    with contextlib.redirect_stderr(io.StringIO()):
                        hrv_analyzer = hrv_report(ecg_dwt, detector)
                        hrv_res, hrv_figs = hrv_analyzer.analyze_hrv(r_peaks, fs)  # 返回三个子图

                    comments = getattr(ecg, 'comments', [])
                    health_report = hrv_analyzer.generate_health_report(hrv_res, comments)
                    print(health_report)

            evaluator = DenoiseEvaluator(fs)
            spectral_fig, wavelet_fig, eval_metrics = evaluator.evaluate_all(
                raw_sig, ecg_dwt.raw_ecg,reference_signal=ecg_iir.raw_ecg,
                wavelet=self.dwt_p['wave'],
                level=self.dwt_p['lvl']
            )

            self.finished.emit({
                'raw': raw_sig, 'std': std_sig, 'iir': ecg_iir.raw_ecg, 'dwt': ecg_dwt.raw_ecg,
                'fs': fs, 'peaks': r_peaks, 'bpm': bpm, 'hrv': hrv_res,
                'eval_metrics': eval_metrics,
                'spectral_fig': spectral_fig,
                'wavelet_fig': wavelet_fig,
                'num_channels': num_channels,
                "fig_hrv":  hrv_figs
            })
            print("> 所有处理流水线执行完毕。")

        except Exception as e:
            print(f"[错误] 处理流水线崩溃: {str(e)}")


class MedicalDashboard(QMainWindow):
    log_signal = Signal(str)

    def __init__(self):
        super().__init__()
        self.setWindowTitle("ECG Analysis 第七组")
        self.resize(1400, 850)
        self.setStyleSheet(
            f"QMainWindow {{ background-color: {COLORS['bg_main']}; }}")

        self.last_res = None
        self.current_file = "ECG_data/ecg-id-database-1.0.0/Person_01/rec_1"
        self.num_channels = 2

        # 保存图表对象
        self.spectral_fig = None
        self.wavelet_fig = None
        self.fig_hrv = None

        self._init_ui()

    def _init_ui(self):
        central = QWidget()
        self.setCentralWidget(central)
        main_layout = QVBoxLayout(central)
        main_layout.setContentsMargins(0, 0, 0, 0)
        main_layout.setSpacing(0)

        # Header
        header = QFrame()
        header.setFixedHeight(52)
        header.setStyleSheet(
            f"background-color: {COLORS['bg_card']}; border-bottom: 1px solid {COLORS['border']};")
        h_layout = QHBoxLayout(header)
        h_layout.setContentsMargins(24, 0, 24, 0)

        # Logo 容器
        logo_container = QWidget()
        logo_layout = QHBoxLayout(logo_container)
        logo_layout.setContentsMargins(0, 0, 0, 0)
        logo_layout.setSpacing(10)

        icon_paths = [
            get_asset_path('icon/logo.png'),
            'icon/logo.png'
        ]

        icon_loaded = False
        for icon_path in icon_paths:
            if os.path.exists(icon_path):
                pixmap = QPixmap(icon_path)
                if not pixmap.isNull():
                    scaled_pixmap = pixmap.scaled(
                        28, 28, Qt.KeepAspectRatio, Qt.SmoothTransformation)
                    logo_icon = QLabel()
                    logo_icon.setPixmap(scaled_pixmap)
                    logo_layout.addWidget(logo_icon)
                    icon_loaded = True
                    break

        if not icon_loaded:
            heart_icon = QLabel("❤️")
            heart_icon.setStyleSheet("font-size: 22px; color: #E74C3C;")
            logo_layout.addWidget(heart_icon)

        lbl_logo = QLabel("ECG Analysis 7th Group")
        lbl_logo.setStyleSheet(f"""
            QLabel {{
                font-family: sans-serif; font-size: 21px; font-weight: 600;
                color: {COLORS['text_main']}; letter-spacing: 1.2px; background: transparent;
            }}
        """)
        logo_layout.addWidget(lbl_logo)
        logo_layout.addStretch()

        h_layout.addWidget(logo_container)
        h_layout.addStretch()
        main_layout.addWidget(header)

        content = QWidget()
        c_layout = QHBoxLayout(content)
        c_layout.setContentsMargins(20, 20, 20, 20)
        c_layout.setSpacing(20)

        # ================= 左侧: 参数面板 =================
        left_panel = QScrollArea()
        left_panel.setWidgetResizable(True)
        left_panel.setFrameShape(QFrame.NoFrame)
        left_panel.setStyleSheet("background: transparent;")

        left_widget = QWidget()
        l_vbox = QVBoxLayout(left_widget)
        l_vbox.setContentsMargins(0, 0, 0, 0)
        l_vbox.setSpacing(16)

        # 数据源卡片
        card_data = SoftCard()
        l1 = QVBoxLayout(card_data)
        l1.setContentsMargins(12, 6, 12, 12)
        l1.setSpacing(8)
        self.lbl_file = QLabel("等待加载")
        self.lbl_file.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: 11px; margin: 0px; margin-top: 0px;")
        btn_import = QPushButton("导入数据")
        btn_import.setStyleSheet(self._btn_style(False))
        btn_import.clicked.connect(lambda: self.import_data())

        self.btn_apply = QPushButton("智能分析")
        self.btn_apply.setStyleSheet(self._btn_style(True))
        self.btn_apply.clicked.connect(lambda: self.run_analysis())

        btn_reset_and_analyze = QPushButton("恢复默认配置")
        btn_reset_and_analyze.setStyleSheet(self._btn_style(False))
        btn_reset_and_analyze.clicked.connect(lambda: self.reset_and_analyze())

        time_layout = QHBoxLayout()
        self.lbl_time_info = QLabel("时间区间: 0.0 - 0.0 秒")
        self.lbl_time_info.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: 10px;")
        time_layout.addWidget(self.lbl_time_info)

        self.lbl_samples = QLabel("采样点数: --")
        self.lbl_samples.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: 10px;")
        self.lbl_fs = QLabel("采样率: --")
        self.lbl_fs.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: 10px;")

        l1.addWidget(QLabel("<b>数据源</b>"))
        l1.addWidget(self.lbl_file)
        l1.addWidget(btn_import)
        l1.addWidget(self.btn_apply)
        l1.addWidget(btn_reset_and_analyze)
        l1.addLayout(time_layout)
        l1.addWidget(self.lbl_samples)
        l1.addWidget(self.lbl_fs)
        l_vbox.addWidget(card_data)

        # IIR滤波器参数卡片
        card_iir = SoftCard()
        l2 = QVBoxLayout(card_iir)
        l2.setContentsMargins(12, 6, 12, 12)
        l2.setSpacing(6)
        l2.addWidget(QLabel("<b>IIR 滤波器参数</b>"))

        filter_type_layout = QHBoxLayout()
        filter_label = QLabel("带通类型:")
        filter_label.setStyleSheet(
            f"color: {COLORS['text_main']}; font-weight: bold; font-size: 15px;")
        filter_type_layout.addWidget(filter_label)
        self.cb_band_type = ConfigurableComboBox(
            DEFAULT_IIR_CONFIG['band_type'])
        self.cb_band_type.addItems(['ellip', 'butter', 'cheby1', 'cheby2'])
        self.cb_band_type.setCurrentText(DEFAULT_IIR_CONFIG['band_type'])
        self.cb_band_type.setStyleSheet(self._combo_style())
        filter_type_layout.addWidget(self.cb_band_type)
        l2.addLayout(filter_type_layout)

        self.sl_fc_low = MinimalSlider("高通截止频率 (Hz)", 1, 50, int(
            DEFAULT_IIR_CONFIG['fc_low'] / 0.1), 0.1, True)
        self.sl_fc_high = MinimalSlider(
            "低通截止频率 (Hz)", 20, 100, DEFAULT_IIR_CONFIG['fc_high'], 1)
        self.sl_order = MinimalSlider(
            "滤波器阶数", 2, 8, DEFAULT_IIR_CONFIG['order'], 1)
        self.sl_notch = MinimalSlider(
            "陷波频率 (Hz)", 50, 60, DEFAULT_IIR_CONFIG['notch'], 1)
        self.sl_rp = MinimalSlider("通带波纹 (dB)", 1, 50, int(
            DEFAULT_IIR_CONFIG['rp'] / 0.1), 0.1, True)
        self.sl_rs = MinimalSlider(
            "阻带衰减 (dB)", 20, 80, DEFAULT_IIR_CONFIG['rs'], 1)
        for w in [self.sl_fc_low, self.sl_fc_high, self.sl_order, self.sl_notch, self.sl_rp, self.sl_rs]:
            l2.addWidget(w)
        l_vbox.addWidget(card_iir)

        # DWT小波去噪卡片
        card_dwt = SoftCard()
        l3 = QVBoxLayout(card_dwt)
        l3.setContentsMargins(12, 6, 12, 12)
        l3.setSpacing(6)
        l3.addWidget(QLabel("<b>小波变换去噪 (DWT)</b>"))

        wavelet_layout = QHBoxLayout()
        wavelet_label = QLabel("小波基:")
        wavelet_label.setStyleSheet(
            f"color: {COLORS['text_main']}; font-weight: bold; font-size: 15px;")
        wavelet_layout.addWidget(wavelet_label)

        self.cb_wave = ConfigurableComboBox(DEFAULT_DWT_CONFIG['wave'])
        self.cb_wave.addItems(['db4', 'db6', 'db8', 'sym4', 'coif4'])
        self.cb_wave.setCurrentText(DEFAULT_DWT_CONFIG['wave'])
        self.cb_wave.setStyleSheet(self._combo_style())
        wavelet_layout.addWidget(self.cb_wave)
        l3.addLayout(wavelet_layout)

        method_layout = QHBoxLayout()
        method_label = QLabel("阈值方法:")
        method_label.setStyleSheet(
            f"color: {COLORS['text_main']}; font-weight: bold; font-size: 15px;")
        method_layout.addWidget(method_label)
        self.cb_method = ConfigurableComboBox(DEFAULT_DWT_CONFIG['method'])
        self.cb_method.addItems(['soft', 'hard'])
        self.cb_method.setCurrentText(DEFAULT_DWT_CONFIG['method'])
        self.cb_method.setStyleSheet(self._combo_style())
        method_layout.addWidget(self.cb_method)
        l3.addLayout(method_layout)

        self.sl_level = MinimalSlider(
            "分解层数", 1, 9, DEFAULT_DWT_CONFIG['lvl'], 1)
        self.sl_k = MinimalSlider("阈值系数 K", 5, 50, int(
            DEFAULT_DWT_CONFIG['k'] / 0.01), 0.01, True)
        l3.addWidget(self.sl_level)
        l3.addWidget(self.sl_k)
        l_vbox.addWidget(card_dwt)

        l_vbox.addStretch()
        left_panel.setWidget(left_widget)
        c_layout.addWidget(left_panel, 18)

        # ================= 中间: 波形区域 =================
        self.mid_panel = QWidget()
        self.m_vbox = QVBoxLayout(self.mid_panel)
        self.m_vbox.setContentsMargins(0, 0, 0, 0)
        self.m_vbox.setSpacing(12)

        self.card_raw = ECGCardWidget("原始信号")
        self.card_std = ECGCardWidget("标准滤波信号")
        self.card_iir = ECGCardWidget("滤波器滤波中间信号")
        self.card_dwt = ECGCardWidget("小波变换滤波最终信号", is_main=True)

        self.cv_raw = self.card_raw.canvas
        self.cv_std = self.card_std.canvas
        self.cv_iir = self.card_iir.canvas
        self.cv_dwt = self.card_dwt.canvas

        self.all_cards = [self.card_raw, self.card_std,
                          self.card_iir, self.card_dwt]
        for card in self.all_cards:
            self.m_vbox.addWidget(card)

        c_layout.addWidget(self.mid_panel, 48)

        # ================= 右侧: HRV 与终端 =================
        right_panel = QWidget()
        r_vbox = QVBoxLayout(right_panel)
        r_vbox.setContentsMargins(0, 0, 0, 0)
        r_vbox.setSpacing(12)

        # ========== 第一行：两个卡片并排 ==========
        first_row_layout = QHBoxLayout()
        first_row_layout.setSpacing(10)

        # 左侧：心率变异性卡片
        card_hrv = SoftCard()
        card_hrv.setFixedHeight(225)
        l_hrv = QVBoxLayout(card_hrv)
        l_hrv.setContentsMargins(10, 8, 10, 8)
        l_hrv.setSpacing(4)
        l_hrv.addWidget(QLabel("<b>心率变异性</b>"))

        # 心率大数字（居中）
        self.lbl_bpm = QLabel("---")
        self.lbl_bpm.setAlignment(Qt.AlignCenter)
        self.lbl_bpm.setStyleSheet(
            f"font-size: 42px; font-weight: 800; color: {COLORS['text_main']}; font-family: 'Inter';")
        l_hrv.addWidget(self.lbl_bpm)

        # 单位标签
        lbl_bpm_sub = QLabel("平均心率 (次/分)")
        lbl_bpm_sub.setAlignment(Qt.AlignCenter)
        lbl_bpm_sub.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: 10px;")
        l_hrv.addWidget(lbl_bpm_sub)

        # 分隔线
        line = QFrame()
        line.setFrameShape(QFrame.HLine)
        line.setStyleSheet(
            # 减少上边距
            f"background-color: {COLORS['border']}; max-height: 1px; margin-top: 1px; margin-bottom: 8px;")
        l_hrv.addWidget(line)

        # 其他指标（水平排列）
        metrics_layout = QHBoxLayout()
        metrics_layout.setSpacing(10)

        # SDNN
        sdnn_widget = QWidget()
        sdnn_layout = QVBoxLayout(sdnn_widget)
        sdnn_layout.setContentsMargins(0, 0, 0, 0)
        sdnn_layout.setSpacing(2)
        sdnn_label = QLabel("SDNN")
        sdnn_label.setAlignment(Qt.AlignCenter)
        sdnn_label.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: 9px;")
        self.lbl_sdnn = QLabel("--")
        self.lbl_sdnn.setAlignment(Qt.AlignCenter)
        self.lbl_sdnn.setStyleSheet(
            f"color: {COLORS['text_main']}; font-size: 14px; font-weight: 600;")
        sdnn_unit = QLabel("ms")
        sdnn_unit.setAlignment(Qt.AlignCenter)
        sdnn_unit.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: 8px;")
        sdnn_layout.addWidget(sdnn_label)
        sdnn_layout.addWidget(self.lbl_sdnn)
        sdnn_layout.addWidget(sdnn_unit)
        metrics_layout.addWidget(sdnn_widget)

        # RMSSD
        rmssd_widget = QWidget()
        rmssd_layout = QVBoxLayout(rmssd_widget)
        rmssd_layout.setContentsMargins(0, 0, 0, 0)
        rmssd_layout.setSpacing(2)
        rmssd_label = QLabel("RMSSD")
        rmssd_label.setAlignment(Qt.AlignCenter)
        rmssd_label.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: 9px;")
        self.lbl_rmssd = QLabel("--")
        self.lbl_rmssd.setAlignment(Qt.AlignCenter)
        self.lbl_rmssd.setStyleSheet(
            f"color: {COLORS['text_main']}; font-size: 14px; font-weight: 600;")
        rmssd_unit = QLabel("ms")
        rmssd_unit.setAlignment(Qt.AlignCenter)
        rmssd_unit.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: 8px;")
        rmssd_layout.addWidget(rmssd_label)
        rmssd_layout.addWidget(self.lbl_rmssd)
        rmssd_layout.addWidget(rmssd_unit)
        metrics_layout.addWidget(rmssd_widget)

        # LF/HF
        lfhf_widget = QWidget()
        lfhf_layout = QVBoxLayout(lfhf_widget)
        lfhf_layout.setContentsMargins(0, 0, 0, 0)
        lfhf_layout.setSpacing(2)
        lfhf_label = QLabel("LF/HF")
        lfhf_label.setAlignment(Qt.AlignCenter)
        lfhf_label.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: 9px;")
        self.lbl_lfhf = QLabel("--")
        self.lbl_lfhf.setAlignment(Qt.AlignCenter)
        self.lbl_lfhf.setStyleSheet(
            f"color: {COLORS['text_main']}; font-size: 14px; font-weight: 600;")
        lfhf_unit = QLabel("")
        lfhf_unit.setAlignment(Qt.AlignCenter)
        lfhf_unit.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: 8px;")
        lfhf_layout.addWidget(lfhf_label)
        lfhf_layout.addWidget(self.lbl_lfhf)
        lfhf_layout.addWidget(lfhf_unit)
        metrics_layout.addWidget(lfhf_widget)

        l_hrv.addLayout(metrics_layout)

        first_row_layout.addWidget(card_hrv, 1)

        # 右侧：去噪评价卡片
        card_eval = SoftCard()
        card_eval.setFixedHeight(225)
        l_eval = QVBoxLayout(card_eval)
        l_eval.setContentsMargins(10, 8, 10, 8)
        l_eval.setSpacing(4)

        # 标题
        title_label2 = QLabel("去噪评价指标")
        title_label2.setAlignment(Qt.AlignCenter)  # 添加这行，设置居中
        title_label2.setStyleSheet(
            f"color: {COLORS['primary']}; font-weight: bold; font-size: 18px;")
        l_eval.addWidget(title_label2)

        # 指标网格（2x2布局）
        eval_grid = QGridLayout()
        eval_grid.setSpacing(12)
        eval_grid.setHorizontalSpacing(15)

        # 添加四个指标
        self.lbl_cc = self._add_metric_card(
            eval_grid, 0, 0, "ECG保持率", "--", "%")
        self.lbl_prd = self._add_metric_card(
            eval_grid, 0, 1, "噪声抑制", "--", "dB")
        self.lbl_spec_dist = self._add_metric_card(
            eval_grid, 1, 0, "波形失真度", "--", "%")
        self.lbl_wavelet_ratio = self._add_metric_card(
            eval_grid, 1, 1, "小波保持", "--", "%")

        l_eval.addLayout(eval_grid)

        first_row_layout.addWidget(card_eval, 1)

        r_vbox.addLayout(first_row_layout)

        # ========== 图表显示标签页 ==========
        card_charts = SoftCard()
        l_charts = QVBoxLayout(card_charts)
        l_charts.setContentsMargins(6, 6, 6, 6)
        l_charts.setSpacing(6)

        # 标签页切换按钮
        tab_layout = QHBoxLayout()
        self.btn_spectral_tab = QPushButton("频谱对比")
        self.btn_wavelet_tab = QPushButton("小波变换")
        self.btn_hrv_tab = QPushButton("HRV看板")

        for btn in [self.btn_spectral_tab, self.btn_wavelet_tab, self.btn_hrv_tab]:
            btn.setStyleSheet(self._btn_style(False))
            btn.setCheckable(True)
            btn.setMaximumHeight(28)
            btn.setMinimumWidth(80)

        self.btn_spectral_tab.setChecked(True)

        tab_layout.addWidget(self.btn_spectral_tab)
        tab_layout.addWidget(self.btn_wavelet_tab)
        tab_layout.addWidget(self.btn_hrv_tab)
        tab_layout.addStretch()
        l_charts.addLayout(tab_layout)

        # 堆叠窗口
        self.chart_stack = QStackedWidget()
        self.chart_stack.setMinimumHeight(350)

        self.spectral_widget = QLabel("请先运行智能分析")
        self.spectral_widget.setAlignment(Qt.AlignCenter)
        self.spectral_widget.setStyleSheet("background-color: #1a1a2e; color: white; border-radius: 8px;")
        self.chart_stack.addWidget(self.spectral_widget)

        self.wavelet_widget = QLabel("请先运行智能分析")
        self.wavelet_widget.setAlignment(Qt.AlignCenter)
        self.wavelet_widget.setStyleSheet("background-color: #1a1a2e; color: white; border-radius: 8px;")
        self.chart_stack.addWidget(self.wavelet_widget)

        # ========== HRV 看板（支持翻页） ==========
        self.hrv_container = QWidget()
        hrv_container_layout = QVBoxLayout(self.hrv_container)
        hrv_container_layout.setContentsMargins(0, 0, 0, 0)

        # HRV 堆叠窗口
        self.hrv_stack = QStackedWidget()
        self.hrv_stack.setMinimumHeight(320)
        hrv_container_layout.addWidget(self.hrv_stack, 1)

        # 翻页控制栏
        nav_layout = QHBoxLayout()
        self.btn_hrv_prev = QPushButton("◀ 上一页")
        self.btn_hrv_next = QPushButton("下一页 ▶")
        self.btn_hrv_prev.setEnabled(False)
        self.btn_hrv_next.setEnabled(False)
        self.btn_hrv_prev.setStyleSheet(self._btn_style(False))
        self.btn_hrv_next.setStyleSheet(self._btn_style(False))
        self.btn_hrv_prev.setMaximumHeight(25)
        self.btn_hrv_next.setMaximumHeight(25)
        self.btn_hrv_prev.clicked.connect(lambda: self.hrv_prev_page())
        self.btn_hrv_next.clicked.connect(lambda: self.hrv_next_page())

        self.hrv_page_label = QLabel("第 0 / 0 页")
        self.hrv_page_label.setAlignment(Qt.AlignCenter)
        self.hrv_page_label.setStyleSheet(f"color: {COLORS['text_sub']}; font-size: 10px;")

        nav_layout.addWidget(self.btn_hrv_prev)
        nav_layout.addWidget(self.hrv_page_label)
        nav_layout.addWidget(self.btn_hrv_next)

        hrv_container_layout.addLayout(nav_layout)

        self.chart_stack.addWidget(self.hrv_container)

        l_charts.addWidget(self.chart_stack, 1)

        self.btn_spectral_tab.clicked.connect(lambda: self.chart_stack.setCurrentIndex(0))
        self.btn_wavelet_tab.clicked.connect(lambda: self.chart_stack.setCurrentIndex(1))
        self.btn_hrv_tab.clicked.connect(lambda: self.chart_stack.setCurrentIndex(2))

        r_vbox.addWidget(card_charts, 1)

        # ========== 终端日志卡片 ==========
        card_term = SoftCard()
        l_term = QVBoxLayout(card_term)
        l_term.setContentsMargins(6, 6, 6, 6)
        self.console = QTextEdit()
        self.console.setReadOnly(True)
        self.console.setMaximumHeight(150)  # 限制高度
        self.console.setStyleSheet(f"""
            background-color: {COLORS['console_bg']}; color: {COLORS['neon_main']}; 
            font-family: 'Consolas', 'Menlo', monospace; font-size: 11px;
            border-radius: 10px; padding: 8px;
        """)
        l_term.addWidget(self.console)
        r_vbox.addWidget(card_term)

        # ========== 导出与保存按钮（最底部） ==========
        btn_layout = QHBoxLayout()
        btn_save = QPushButton("保存数据")
        btn_export = QPushButton("导出报告")

        btn_save.setStyleSheet(self._btn_style(False))
        btn_export.setStyleSheet(self._btn_style(True))

        btn_save.clicked.connect(lambda: self.save_data())
        btn_export.clicked.connect(lambda: self.export_report())

        btn_layout.addWidget(btn_save)
        btn_layout.addWidget(btn_export)
        r_vbox.addLayout(btn_layout)

        c_layout.addWidget(right_panel, 34)
        main_layout.addWidget(content)

        # 日志重定向
        self.stdout_redirector = EmittingStream(self.log_signal)
        self.log_signal.connect(lambda text: self._append_console(text))
        sys.stdout = self.stdout_redirector
        self.centralWidget().installEventFilter(self)

    def _add_metric_card(self, grid, row, col, name, val, unit):
        """添加卡片式指标（用于去噪评价）"""
        w = QWidget()
        w.setStyleSheet(f"""
            QWidget {{
                background-color: {COLORS['bg_main']};
                border-radius: 8px;
            }}
        """)
        l = QVBoxLayout(w)
        l.setContentsMargins(8, 8, 8, 8)
        l.setSpacing(4)

        n = QLabel(name)
        n.setAlignment(Qt.AlignCenter)
        n.setStyleSheet(f"color: {COLORS['text_sub']}; font-size: 10px;")

        v = QLabel(val)
        v.setAlignment(Qt.AlignCenter)
        v.setStyleSheet(
            f"color: {COLORS['text_main']}; font-size: 18px; font-weight: 700; font-family: 'Inter';")

        u = QLabel(unit)
        u.setAlignment(Qt.AlignCenter)
        u.setStyleSheet(f"color: {COLORS['text_sub']}; font-size: 9px;")

        l.addWidget(n)
        l.addWidget(v)
        l.addWidget(u)

        grid.addWidget(w, row, col)
        return v

    def eventFilter(self, obj, event):
        if event.type() == event.Type.MouseButtonPress:
            focused = QApplication.focusWidget()
            if focused and isinstance(focused, QDoubleSpinBox):
                clicked_widget = QApplication.widgetAt(
                    event.globalPosition().toPoint())
                if clicked_widget != focused:
                    focused.clearFocus()
        return super().eventFilter(obj, event)

    def reset_and_analyze(self):
        if not hasattr(self, 'current_file'):
            print("[System] 请先导入数据文件")
            return

        print("\n" + "="*40)
        print("[System] 正在恢复默认设置...")

        self.cb_band_type.reset_to_default()
        self.sl_fc_low.reset_to_default()
        self.sl_fc_high.reset_to_default()
        self.sl_order.reset_to_default()
        self.sl_notch.reset_to_default()
        self.sl_rp.reset_to_default()
        self.sl_rs.reset_to_default()

        self.cb_wave.reset_to_default()
        self.cb_method.reset_to_default()
        self.sl_level.reset_to_default()
        self.sl_k.reset_to_default()

        print("[System] 参数已恢复为默认值")
        print(f"[System] 当前数据集: {os.path.basename(self.current_file)}")
        print("[System] 自动开始分析...")
        print("="*40 + "\n")

        self.run_analysis()

    def _btn_style(self, is_primary=False):
        bg = COLORS['primary'] if is_primary else "#F0F4F4"
        fg = "#FFFFFF" if is_primary else COLORS['text_main']
        hv = COLORS['success'] if is_primary else "#E0E8E8"
        return f"""
            QPushButton {{ background-color: {bg}; color: {fg}; border: none; border-radius: 10px; padding: 8px; font-weight: bold; font-size: 12px;}}
            QPushButton:hover {{ background-color: {hv}; }}
        """

    def _combo_style(self):
        if arrow_path and os.path.exists(arrow_path):
            return f"""
                QComboBox {{
                    border: 1px solid {COLORS['border']}; border-radius: 6px; padding: 4px 8px;
                    background: white; color: {COLORS['text_main']}; min-height: 18px; font-size: 12px;
                }}
                QComboBox::drop-down {{ border: none; width: 20px; subcontrol-position: right center; }}
                QComboBox::down-arrow {{ image: url({arrow_path}); width: 14px; height: 14px; }}
                QComboBox QAbstractItemView {{
                    background-color: white; border: 1px solid {COLORS['border']}; border-radius: 6px;
                    selection-background-color: {COLORS['primary']}; selection-color: white; outline: 0px;
                }}
                QComboBox QAbstractItemView::item {{ color: {COLORS['text_main']}; padding: 8px; min-height: 20px; }}
                QComboBox QAbstractItemView::item:hover {{ background-color: {COLORS['border']}; color: {COLORS['text_main']}; }}
            """
        else:
            return f"""
                QComboBox {{
                    border: 1px solid {COLORS['border']}; border-radius: 6px; padding: 4px 8px;
                    background: white; color: {COLORS['text_main']}; min-height: 18px; font-size: 12px;
                }}
                QComboBox::drop-down {{ border: none; width: 0px; }}
                QComboBox::down-arrow {{ width: 0px; height: 0px; }}
                QComboBox QAbstractItemView {{
                    background-color: white; border: 1px solid {COLORS['border']}; border-radius: 6px;
                    selection-background-color: {COLORS['primary']}; selection-color: white; outline: 0px;
                }}
                QComboBox QAbstractItemView::item {{ color: {COLORS['text_main']}; padding: 8px; min-height: 20px; }}
                QComboBox QAbstractItemView::item:hover {{ background-color: {COLORS['border']}; color: {COLORS['text_main']}; }}
            """

    def _add_metric(self, grid, index, name, val, value_size=18, label_size=11):
        row, col = index // 2, index % 2
        w = QWidget()
        l = QVBoxLayout(w)
        l.setContentsMargins(4, 4, 4, 4)

        n = QLabel(name)
        n.setStyleSheet(
            f"color: {COLORS['text_sub']}; font-size: {label_size}px;")

        v = QLabel(val)
        v.setAlignment(Qt.AlignCenter)
        v.setStyleSheet(
            f"color: {COLORS['text_main']}; font-size: {value_size}px; font-weight: 600; font-family: 'Inter';")

        l.addWidget(n)
        l.addWidget(v)
        grid.addWidget(w, row, col)
        return v

    def hrv_prev_page(self):
        """HRV 上一页"""
        if self.hrv_page_index > 0:
            self.hrv_page_index -= 1
            self.hrv_stack.setCurrentIndex(self.hrv_page_index)
            self.hrv_page_label.setText(f"第 {self.hrv_page_index + 1} / {len(self.hrv_pages)} 页")
            self.btn_hrv_prev.setEnabled(self.hrv_page_index > 0)
            self.btn_hrv_next.setEnabled(self.hrv_page_index < len(self.hrv_pages) - 1)

    def hrv_next_page(self):
        """HRV 下一页"""
        if self.hrv_page_index < len(self.hrv_pages) - 1:
            self.hrv_page_index += 1
            self.hrv_stack.setCurrentIndex(self.hrv_page_index)
            self.hrv_page_label.setText(f"第 {self.hrv_page_index + 1} / {len(self.hrv_pages)} 页")
            self.btn_hrv_prev.setEnabled(self.hrv_page_index > 0)
            self.btn_hrv_next.setEnabled(self.hrv_page_index < len(self.hrv_pages) - 1)

    def update_hrv_pages(self, hrv_figs, container_width, container_height):
        """更新 HRV 翻页内容"""
        # 清除原有页面
        while self.hrv_stack.count() > 0:
            widget = self.hrv_stack.widget(0)
            self.hrv_stack.removeWidget(widget)
            widget.deleteLater()
        
        self.hrv_pages = []
        
        if not hrv_figs:
            # 无数据时显示提示
            info_label = QLabel("HRV 分析需要至少3个R峰\n请确保信号有足够的心跳")
            info_label.setAlignment(Qt.AlignCenter)
            info_label.setStyleSheet("color: white; background-color: #1a1a2e; border-radius: 8px; padding: 20px;")
            self.hrv_stack.addWidget(info_label)
            self.hrv_pages.append(info_label)
        else:
            for i, fig in enumerate(hrv_figs):
                # 转换图表
                pixmap = fig_to_pixmap(fig, container_width, container_height)
                if pixmap:
                    scroll_area = QScrollArea()
                    scroll_area.setWidgetResizable(True)
                    img_label = QLabel()
                    img_label.setPixmap(pixmap)
                    img_label.setAlignment(Qt.AlignCenter)
                    img_label.setScaledContents(True)
                    scroll_area.setWidget(img_label)
                    self.hrv_stack.addWidget(scroll_area)
                    self.hrv_pages.append(scroll_area)
                plt.close(fig)
        
        # 重置翻页状态
        self.hrv_page_index = 0
        if len(self.hrv_pages) > 0:
            self.hrv_stack.setCurrentIndex(0)
            self.hrv_page_label.setText(f"第 1 / {len(self.hrv_pages)} 页")
            self.btn_hrv_prev.setEnabled(False)
            self.btn_hrv_next.setEnabled(len(self.hrv_pages) > 1)

    def _append_console(self, text):
        if hasattr(self, 'console'):
            if any(keyword in text for keyword in [
                'SDNN', 'RMSSD', 'LF/HF', '平均心率', 'System', '保存',
                'ECG频段能量保持率', '噪声抑制量', '频谱失真度', '小波域能量保持率'
            ]):
                cursor = self.console.textCursor()
                cursor.movePosition(cursor.MoveOperation.End)

                if self.console.document().lineCount() > 150:
                    cursor.movePosition(cursor.MoveOperation.Start)
                    cursor.movePosition(
                        cursor.MoveOperation.Down, cursor.MoveOperation.MoveAnchor, 30)
                    cursor.movePosition(
                        cursor.MoveOperation.End, cursor.MoveOperation.KeepAnchor)
                    cursor.removeSelectedText()

                cursor.insertText(text + '\n')
                self.console.setTextCursor(cursor)
                self.console.ensureCursorVisible()

    def import_data(self):
        path, _ = QFileDialog.getOpenFileName(self, "导入数据", "", "WFDB (*.dat)")
        if path:
            self.current_file = path.replace('.dat', '')
            self.lbl_file.setText(os.path.basename(self.current_file))
            print(f"[System] 已选择数据集: {os.path.basename(self.current_file)}")

    def run_analysis(self):
        if not hasattr(self, 'current_file'):
            print("[System] 请先导入数据文件")
            return
        self.btn_apply.setEnabled(False)
        self.btn_apply.setText("处理中...")
        print("\n" + "="*40)
        print("[System] 启动临床分析流水线...")

        iir_p = {
            'band_type': self.cb_band_type.currentText(), 'fc_low': self.sl_fc_low.get_value(),
            'fc_high': self.sl_fc_high.get_value(), 'order': int(self.sl_order.get_value()),
            'notch': int(self.sl_notch.get_value()), 'rp': self.sl_rp.get_value(),
            'rs': self.sl_rs.get_value(),
        }
        dwt_p = {
            'wave': self.cb_wave.currentText(), 'lvl': int(self.sl_level.get_value()),
            'k': self.sl_k.get_value(), 'method': self.cb_method.currentText()
        }

        self.thread = ProcessingEngine(self.current_file, iir_p, dwt_p)
        self.thread.finished.connect(lambda res: self._on_finish(res))
        self.thread.start()

    def _update_waveform_display(self, num_channels):
        if num_channels == 1:
            for i, card in enumerate(self.all_cards):
                card.setVisible(False if i == 1 else True)
        else:
            for card in self.all_cards:
                card.setVisible(True)

    def _on_finish(self, res):
        self.last_res = res
        self.btn_apply.setEnabled(True)
        self.btn_apply.setText("智能分析")

        if 'raw' not in res:
            return
        fs = res['fs']
        num_channels = res.get('num_channels', 2)

        self.num_channels = num_channels
        self._update_waveform_display(num_channels)

        total_time = len(res['raw']) / fs
        self.lbl_samples.setText(f"采样点数: {len(res['raw'])}")
        self.lbl_fs.setText(f"采样率: {res['fs']} Hz")
        self.lbl_time_info.setText(f"时间区间: 0.0 - {total_time:.2f} s")

        self.cv_raw.set_data(res['raw'], fs)
        if num_channels == 2:
            self.cv_std.set_data(res['std'], fs)
        self.cv_iir.set_data(res['iir'], fs)
        self.cv_dwt.set_data(res['dwt'], fs, res['peaks'])

        self.lbl_bpm.setText(f"{res['bpm']:.0f}")

        hrv = res['hrv']
        if hrv:
            self.lbl_sdnn.setText(f"{hrv.get('HRV_SDNN', 0):.1f}")
            self.lbl_rmssd.setText(f"{hrv.get('HRV_RMSSD', 0):.1f}")
            self.lbl_lfhf.setText(f"{hrv.get('HRV_LFHF', 0):.2f}")

        eval_metrics = res.get('eval_metrics', {})
        if eval_metrics:
            self.lbl_cc.setText(
                f"{eval_metrics.get('ecg_energy_ratio', 0)*100:.1f}%")
            self.lbl_prd.setText(
                f"{eval_metrics.get('noise_suppression_db', 0):.1f}")
            distortion = eval_metrics.get('distortion_score', 0)
            if distortion == 0:
                cosine_sim = eval_metrics.get('cosine_similarity', 0)
                distortion = (1 - cosine_sim) / 2 * 100
            self.lbl_spec_dist.setText(f"{distortion:.1f}%")
            self.lbl_wavelet_ratio.setText(
                f"{eval_metrics.get('total_energy_ratio', 0)*100:.1f}%")

        # 获取图表面板的实际尺寸（从 chart_stack 本身获取）
        container_width = self.chart_stack.width() - 20  # 减去一些边距
        container_height = self.chart_stack.height() - 20

        # 如果尺寸太小，使用默认值
        if container_width < 100:
            container_width = 400
        if container_height < 100:
            container_height = 300

        print(f"图表容器尺寸: {container_width} x {container_height}")

        # 更新频谱对比图
        spectral_fig = res.get('spectral_fig', None)
        if spectral_fig is not None:
            pixmap = fig_to_pixmap(
                spectral_fig, container_width, container_height)
            if pixmap:
                scroll_area = QScrollArea()
                scroll_area.setWidgetResizable(True)
                img_label = QLabel()
                img_label.setPixmap(pixmap)
                img_label.setAlignment(Qt.AlignCenter)
                img_label.setScaledContents(True)  # 添加这行，让图片自动缩放
                scroll_area.setWidget(img_label)

                old_widget = self.chart_stack.widget(0)
                self.chart_stack.removeWidget(old_widget)
                old_widget.deleteLater()
                self.chart_stack.insertWidget(0, scroll_area)

        # 更新小波变换图
        wavelet_fig = res.get('wavelet_fig', None)
        if wavelet_fig is not None:
            pixmap = fig_to_pixmap(
                wavelet_fig, container_width, container_height)
            if pixmap:
                scroll_area = QScrollArea()
                scroll_area.setWidgetResizable(True)
                img_label = QLabel()
                img_label.setPixmap(pixmap)
                img_label.setAlignment(Qt.AlignCenter)
                img_label.setScaledContents(True)
                scroll_area.setWidget(img_label)

                old_widget = self.chart_stack.widget(1)
                self.chart_stack.removeWidget(old_widget)
                old_widget.deleteLater()
                self.chart_stack.insertWidget(1, scroll_area)

        # 更新HRV看板
        # 更新 HRV 翻页
        hrv_figs = res.get('fig_hrv', None)
        if hrv_figs:
            print(f"获取到 {len(hrv_figs)} 个 HRV 子图")
            self.update_hrv_pages(hrv_figs, container_width, container_height)
        else:
            print("未获取到 HRV 子图")
            self.update_hrv_pages([], container_width, container_height)

    def export_report(self):
        if not self.last_res:
            return
        path, _ = QFileDialog.getSaveFileName(
            self, "导出报告", "心电分析报告.txt", "文本文件 (*.txt)")
        if path:
            try:
                with open(path, 'w', encoding='utf-8') as f:
                    f.write(self.console.toPlainText())
                print(f"[System] 报告已成功导出至: {path}")
            except Exception as e:
                print(f"[System] 导出失败: {str(e)}")

    def save_data(self):
        if not self.last_res:
            return
        path, _ = QFileDialog.getSaveFileName(
            self, "保存数据", "心电处理后数据.csv", "CSV文件 (*.csv)")
        if path:
            try:
                res = self.last_res
                time_arr = np.arange(len(res['raw'])) / res['fs']
                data_matrix = np.column_stack(
                    (time_arr, res['raw'], res['std'], res['iir'], res['dwt']))
                np.savetxt(path, data_matrix, delimiter=',',
                           header='时间(秒),原始信号,标准滤波,IIR滤波,小波去噪', comments='', fmt='%.4f')
                print(f"[System] 数据已成功保存至: {path}")
            except Exception as e:
                print(f"[System] 保存失败: {str(e)}")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    font = QFont("Microsoft YaHei", 10)
    font.setStyleHint(QFont.SansSerif)
    app.setFont(font)
    window = MedicalDashboard()
    window.show()
    sys.exit(app.exec())
