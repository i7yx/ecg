import neurokit2 as nk
import matplotlib.pyplot as plt
from read import read_ecg
from clean import clean_ecg
from DWT import wavelet_denoise_ecg
from bpm import PanTompkinsBPM
import re
import os
import io


class hrv_report():
    def __init__(self, ecg: read_ecg, detecor: PanTompkinsBPM):
        self.ecg = ecg
        self.detector = detecor

    def _apply_dark_theme(self, fig, axes):
        """将原始的 NeuroKit2 浅色图表一键转换为高端暗黑医疗监护主题"""
        fig.patch.set_alpha(0.0)  # 外层画布透明，方便后续精确裁切
        
        for ax in axes:
            ax.set_facecolor('#0a0a1a')  # 深黑色绘图区
            
            # 坐标轴线颜色和粗细
            for spine in ax.spines.values():
                spine.set_color('#3a3a5a')
                spine.set_linewidth(1.0)
                
            # 网格线设置（微弱虚线）
            ax.grid(True, alpha=0.15, color='white', linestyle=':')
            
            # 标签与标题颜色
            ax.xaxis.label.set_color('#e2e8f0')
            ax.yaxis.label.set_color('#e2e8f0')
            if ax.title:
                ax.title.set_color('white')
                ax.title.set_fontsize(11)
                ax.title.set_fontweight('bold')
                
            # 刻度和刻度文字颜色
            ax.tick_params(colors='#e2e8f0', which='both', labelsize=8)
            
            # 图例暗色化
            legend = ax.get_legend()
            if legend:
                legend.get_frame().set_facecolor('#1a1a2e')
                legend.get_frame().set_edgecolor('#3a3a5a')
                for text in legend.get_texts():
                    text.set_color('white')
                    text.set_fontsize(8)
            
            # 关键：将图表内所有的标注文本（如庞加莱图中的SD1/SD2数值、DFA中绘制的Alpha文本）也全部转换为白色/浅灰色
            for text in ax.texts:
                text.set_color('#e2e8f0')

    def analyze_hrv(self, r_peaks, fs):
        """
        返回三个拆分好的子图：distribution, psd, nonlinear_combined
        """
        if r_peaks is None or len(r_peaks) < 2:
            raise ValueError("提供的 R 波数量不足以进行 HRV 分析（至少需要2个R波）。")

        # 生成完整图表
        hrv_df = nk.hrv(r_peaks, sampling_rate=fs, show=True)
        fig = plt.gcf()
        axes = fig.get_axes()
        
        print(f"检测到 {len(axes)} 个 HRV 子图")
        
        # 核心步骤：一键暗化，使图片内部与外部背景高度统一，且高对比度清晰显示
        self._apply_dark_theme(fig, axes)
        
        # 拆分并获取三个子图
        figs = self._split_figure(fig, axes)
        
        plt.close(fig)
        
        hrv_results = hrv_df.to_dict(orient='records')[0]
        return hrv_results, figs

    def _split_figure(self, fig, axes):
        """拆分图表为三个子图"""
        figs = []
        
        # 保存原始可见性
        original_visibility = [ax.get_visible() for ax in axes]
        
        # 1. distribution 直方图 (索引 0)
        if len(axes) > 0:
            fig1 = self._capture_subfigure(fig, axes, [0], "RR间期分布直方图")
            figs.append(fig1)
            print("   - 已提取: distribution")
        
        # 2. PSD 频域图 (索引 1)
        if len(axes) > 1:
            fig2 = self._capture_subfigure(fig, axes, [1], "HRV功率谱密度")
            figs.append(fig2)
            print("   - 已提取: psd")
        
        # 3. nonlinear_combined (索引 2 及之后)
        if len(axes) > 2:
            nonlinear_indices = list(range(2, len(axes)))
            fig3 = self._capture_subfigure(fig, axes, nonlinear_indices, "HRV非线性指标组合")
            figs.append(fig3)
            print(f"   - 已提取: nonlinear_combined (包含 {len(nonlinear_indices)} 个子图)")
        
        # 恢复原始可见性
        for i, ax in enumerate(axes):
            ax.set_visible(original_visibility[i])
        
        return figs

    def _capture_subfigure(self, fig, axes, indices_to_keep, title):
        """截取指定索引的子图组合，返回新的 Figure 对象"""
        # 设置可见性
        for i, ax in enumerate(axes):
            ax.set_visible(i in indices_to_keep)
        
        # 创建临时缓冲区保存图片（开启透明通道，绝对避开不协调的白色背景）
        buf = io.BytesIO()
        fig.savefig(buf, format='png', dpi=150, bbox_inches='tight', transparent=True)
        buf.seek(0)
        
        # 从缓冲区读取图片
        import matplotlib.image as mpimg
        img = mpimg.imread(buf)
        buf.close()
        
        # 动态获取原图宽高比，保证新画布比例一致，绝对防止拉伸和信箱框空白
        img_h, img_w, _ = img.shape
        aspect_ratio = img_w / img_h
        
        # 建立比例完美的新画布，避免边缘不协调
        fig_width = 8.0
        fig_height = fig_width / aspect_ratio
        
        new_fig = plt.figure(figsize=(fig_width, fig_height), dpi=100)
        new_fig.set_facecolor('#1a1a2e')  # 背景色完美契合大屏 GUI 的医疗暗调卡片
        
        # 划分布局比例：上方保留 12% 绘制标题，其余空间完美平铺
        new_ax = new_fig.add_axes([0.05, 0.05, 0.9, 0.83])
        new_ax.set_facecolor('#1a1a2e')
        new_ax.imshow(img, aspect='equal')
        new_ax.axis('off')  # 隐藏外面包裹的坐标系，避免影响美观
        
        # 在最顶部绘制统一的白色大标题，高雅大气
        new_fig.suptitle(title, color='white', fontsize=12, fontweight='bold', y=0.94)
        
        return new_fig

    def print_report(self, report_dir="./report", image_dir="./image"):
        r_peaks, _ = self.detector.detect()
        fs = self.ecg.fs
        comments = self.ecg.comments if self.ecg.comments else []
        index = getattr(self.ecg, 'index', 'test_record')

        os.makedirs(image_dir, exist_ok=True)
        os.makedirs(report_dir, exist_ok=True)

        print("[3/5] 正在使用 NeuroKit2 进行全维度 HRV 分析...")
        hrv_results, figs = self.analyze_hrv(r_peaks, fs)
        
        # 保存三个子图
        sub_names = ["distribution", "psd", "nonlinear_combined"]
        for i, (fig, name) in enumerate(zip(figs, sub_names)):
            if i < len(figs):
                path = f"{image_dir}/{index}_hrv_{name}.png"
                fig.savefig(path, dpi=150, bbox_inches='tight')
                print(f"      -> HRV子图 [{name}] 已保存至: {path}")
                plt.close(fig)

        print("[4/5] 正在打印核心指标报告...")
        mean_nn = hrv_results.get('HRV_MeanNN', 0)
        mean_hr = (60000 / mean_nn) if mean_nn > 0 else 0

        print("=" * 45)
        print("         NeuroKit2 HRV 分析核心指标报告")
        print("=" * 45)

        print("【时域指标 (Time Domain)】")
        print(f"• 平均心率 (Mean HR):     {mean_hr:.2f} bpm")
        print(f"• 平均NN间期 (Mean NN):   {mean_nn:.2f} ms")
        print(f"• SDNN:                  {hrv_results.get('HRV_SDNN', 0):.2f} ms")
        print(f"• RMSSD:                 {hrv_results.get('HRV_RMSSD', 0):.2f} ms")
        print(f"• pNN50:                 {hrv_results.get('HRV_pNN50', 0):.2f} %")

        print("【频域指标 (Frequency Domain)】")
        print(f"• LF 相对功率 (低频占比):  {hrv_results.get('HRV_LFn', 0) * 100:.2f} %")
        print(f"• HF 相对功率 (高频占比):  {hrv_results.get('HRV_HFn', 0) * 100:.2f} %")
        print(f"• LF/HF 比例 (交感平衡):   {hrv_results.get('HRV_LFHF', 0):.4f}")

        print("【非线性指标 (Non-linear & DFA)】")
        print(f"• 庞加莱 SD1 (短期变异):   {hrv_results.get('HRV_SD1', 0):.2f} ms")
        print(f"• 庞加莱 SD2 (长期变异):   {hrv_results.get('HRV_SD2', 0):.2f} ms")
        print(f"• SD1/SD2 比例:          {hrv_results.get('HRV_SD1SD2', 0):.4f}")
        print(f"• DFA Alpha 1 (短程):    {hrv_results.get('HRV_DFA_alpha1', 0):.4f}")
        print(f"• DFA Alpha 2 (长程):    {hrv_results.get('HRV_DFA_alpha2', 0):.4f}")

        print("=" * 45)

        print("[5/5] 正在根据医学临床指南生成智能健康报告...")
        health_report_text = self.generate_health_report(hrv_results, comments)

        print("\n" + health_report_text)

        txt_save_path = f"{report_dir}/{index}_health_report.txt"
        with open(txt_save_path, "w", encoding="utf-8") as f:
            f.write(health_report_text)
        print(f"      -> 诊断报告文本已保存至: {txt_save_path}")

        print(f"\n✅ 所有处理步骤顺利完成！请在 {image_dir}/ 和 {report_dir}/ 目录下查收图表与诊断报告！")

    def generate_health_report(self, hrv_results, comments):
        """
        根据 HRV 指标和个人信息，生成通俗易懂的健康评估报告。
        """
        patient_info = self.parse_patient_info(comments)

        mean_nn = hrv_results.get('HRV_MeanNN', 0)
        mean_hr = (60000 / mean_nn) if mean_nn > 0 else 0
        sdnn = hrv_results.get('HRV_SDNN', 0)
        rmssd = hrv_results.get('HRV_RMSSD', 0)
        lf_hf = hrv_results.get('HRV_LFHF', 0)

        report = []
        report.append("\n综合心率变异性 (HRV) 健康评估报告")

        # --- 1. 动态生成个人基础信息板块 ---
        report.append(f"\n👤【患者基础信息】")
        report.append(f" • 年龄: {patient_info['age']} 岁" if patient_info['age'] != '未知' else "• 推测年龄: 未知")
        report.append(f" • 性别: {patient_info['sex']}")

        if patient_info['height'] != '未知':
            report.append(f" • 登记身高: {patient_info['height']}")
        if patient_info['weight'] != '未知':
            report.append(f" • 登记体重: {patient_info['weight']}")

        if patient_info['history']:
            report.append(f" • 档案备注: {', '.join(patient_info['history'])}")
        else:
            report.append(f" • 档案备注: 暂无明确记载")

        # --- 2. 基础心率评估 ---
        report.append(f"\n❤️【基础心率评估】(平均心率: {mean_hr:.1f} bpm)")

        if mean_hr < 50:
            report.append("[状态]: 偏低心率。可能与高体能水平、睡眠状态或迷走神经张力较高有关（需结合场景）。")

        elif 50 <= mean_hr < 60:
            report.append("[状态]: 略低于常见静息范围，但在健康人群中仍可能正常（尤其是运动人群）。")

        elif 60 <= mean_hr <= 100:
            report.append("[状态]: 位于常见静息心率范围内。")

        else:
            report.append("[状态]: 偏高心率。可能与活动、情绪激活、疲劳或恢复不足有关（需结合上下文）。")

        # --- 3. 整体心血管健康风险评估 (SDNN) ---
        report.append(f"\n🛡️【心率变异性（SDNN）】(SDNN: {sdnn:.1f} ms)")
        report.append("[说明]: 本指标为短时HRV估计，仅用于趋势参考，不等同24h临床SDNN。")

        if sdnn < 30:
            report.append("[状态]: 偏低。提示心率波动性降低，自主神经灵活性可能下降。")

        elif 30 <= sdnn < 70:
            report.append("[状态]: 中等范围。符合多数健康成年人的常见水平。")

        else:
            report.append("[状态]: 较高波动性。通常见于良好体能状态或较高迷走神经活动。")

        # --- 4. 疲劳与恢复状态评估 (RMSSD) ---
        report.append(f"\n🔋【副交感神经活动（RMSSD）】(RMSSD: {rmssd:.1f} ms)")
        report.append("[说明]: 反映短期迷走神经调节强度，是恢复状态的较稳定指标之一。")

        if rmssd < 20:
            report.append("[状态]: 偏低。可能反映恢复水平较低或压力负荷较高。")

        elif 20 <= rmssd < 40:
            report.append("[状态]: 中等水平。常见于一般日常状态。")

        else:
            report.append("[状态]: 较高。通常与良好恢复状态或较强副交感活动相关。")

        # --- 5. 情绪与精神压力评估 (LF/HF) ---
        import math

        report.append(f"\n⚖️【自主神经频域指标（LF/HF）】(LF/HF: {lf_hf:.2f})")
        report.append("[重要说明]: LF/HF在短时HRV中受呼吸与信号质量影响较大，仅作为辅助参考指标。")

        if math.isnan(lf_hf):
            report.append("[状态]: 无法计算（ECG信号长度不足或频域分析条件不满足）。")

        elif lf_hf < 0.5:
            report.append("[状态]: 偏低。可能提示副交感活动相对较高，但需结合呼吸频率判断。")

        elif 0.5 <= lf_hf <= 2.0:
            report.append("[状态]: 常见范围内。但该范围不等同严格‘平衡状态’。")

        else:
            report.append("[状态]: 偏高。可能与交感激活、压力状态或呼吸模式有关，但解释需谨慎。")

        report.append("\n免责声明：本报告由算法自动生成，仅供科学研究与日常健康参考。不能替代专业医师的临床诊断。\n")

        return "\n".join(report)

    def parse_patient_info(self, comments):
        """
        通过强化正则表达式，从 comments 中提取年龄、性别、身高、体重及病史信息。
        自适应兼容 MIT-BIH、PTB-XL、CPSC 等多种心电数据库的注释风格。
        """
        info = {
            "age": "未知",
            "sex": "未知",
            "height": "未知",
            "weight": "未知",
            "history": []
        }

        for line in comments:
            line = line.strip()
            if not line:
                continue

            # --- 1. 提取年龄 (Age) ---
            # 兼容格式: Age: 69, Age=69, age 69, 69yo, 69 yr, 69 years
            age_match = re.search(r'(?i)(?:age|yo|yr|years?)[\s:=]*(\d+)', line)
            if age_match:
                info["age"] = age_match.group(1)

            # --- 2. 提取性别 (Sex/Gender) ---
            # 兼容格式: Sex: M, Gender: Female, Sex=Male, 性别: 男
            sex_match = re.search(r'(?i)(?:sex|gender)[\s:=]*([MFW]|Male|Female|Man|Woman)', line)
            if sex_match:
                sex_str = sex_match.group(1).upper()
                info["sex"] = "男" if sex_str.startswith('M') else "女"

            # --- 3. 提取身高 (Height) ---
            # 兼容格式: Height: 175cm, height=1.75m, ht 175
            height_match = re.search(r'(?i)(?:height|ht)[\s:=]*(\d+(?:\.\d+)?)\s*(cm|m)?', line)
            if height_match:
                val = height_match.group(1)
                unit = height_match.group(2) if height_match.group(2) else 'cm'
                info["height"] = f"{val} {unit.lower()}"

            # --- 4. 提取体重 (Weight) ---
            # 兼容格式: Weight: 70kg, weight=70.5, wt 70
            weight_match = re.search(r'(?i)(?:weight|wt)[\s:=]*(\d+(?:\.\d+)?)\s*(kg|lbs)?', line)
            if weight_match:
                val = weight_match.group(1)
                unit = weight_match.group(2) if weight_match.group(2) else 'kg'
                info["weight"] = f"{val} {unit.lower()}"

            # --- 5. 兼容 MIT-BIH 极简无标签格式 (数字 + M/F) ---
            # 如果前面没提取到标签，且该行以 "数字 空格 字母(M/F)" 开头
            mit_match = re.match(r'^(\d{1,3})\s+([MFWmfw])\b(.*)', line)
            if mit_match and (info["age"] == "未知" or info["sex"] == "未知"):
                info["age"] = mit_match.group(1)
                sex_str = mit_match.group(2).upper()
                info["sex"] = "男" if sex_str == 'M' else "女"

                remain = mit_match.group(3).strip()
                if remain:
                    info["history"].append(f"{remain}")
                continue  # 匹配成功则跳入下一行，防止将其作为病史再次添加

            # --- 6. 提取病史 / 用药 (Dx, Rx, History) ---
            # 如果这一行不是纯身高体重年龄的标签行，并且包含字母或汉字，则归类为病史/用药
            is_metadata = age_match or sex_match or height_match or weight_match
            if not is_metadata and re.search(r'[a-zA-Z\u4e00-\u9fa5]', line):
                info["history"].append(line)

        return info


if __name__ == "__main__":
    image_dir = "./image"
    report_dir = "./report"
    os.makedirs(image_dir, exist_ok=True)  
    os.makedirs(report_dir, exist_ok=True)  
    
    print("====== 开始运行 HRV 分析测试 ======")
    try:
        try:
            ecg = read_ecg()
            ecg_clean = clean_ecg(ecg).apply_filter()
            ecg_DWT = wavelet_denoise_ecg(ecg_clean).denoise()
        except Exception as e:
            print(f"本地读取信号失败 ({str(e)}), 将使用 NeuroKit2 生成模拟信号进行测试...")
            class MockECG:
                def __init__(self):
                    self.fs = 250
                    self.raw_ecg = nk.ecg_simulate(duration=30, sampling_rate=self.fs, heart_rate=70)
                    self.comments = ["Age: 25", "Sex: Male", "Healthy subject test"]
                    self.index = "simulated_record"
            ecg_DWT = MockECG()

        detector = PanTompkinsBPM(ecg_DWT)
        
        hrv = hrv_report(ecg_DWT, detecor=detector)
        hrv.print_report(report_dir=report_dir, image_dir=image_dir)
        
    except Exception as e:
        print(f"发生错误: {str(e)}")