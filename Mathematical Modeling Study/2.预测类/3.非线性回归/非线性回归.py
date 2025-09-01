import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import os
import warnings

# 设置中文显示 - 只使用Windows系统常见字体，避免缺失警告
plt.rcParams["font.sans-serif"] = ["Microsoft YaHei"]  # 解决中文显示问题
plt.rcParams["axes.unicode_minus"] = False  # 解决负号显示异常的问题（可选）

# ----------------------
# 参数设置
# ----------------------
INPUT_FILE = "data.xlsx"  # 输入数据文件
OUTPUT_FILE = "glucose_regression_results.xlsx"  # 输出结果文件
MODEL_NAME = "modified_gaussian"  # 使用修正高斯模型
SHEET_NAME = 0
X_COLUMN = "时间(分钟)"
Y_COLUMN = "血糖浓度(mmol/L)"
MAX_ITERATIONS = 30000  # 增加迭代次数以确保收敛


# ----------------------
# 非线性模型定义
# ----------------------
def modified_gaussian(x, a, b, c, d, e):
    """修正的高斯函数（适合血糖曲线）"""
    return a + b * np.exp(-0.5 * (
            ((x < c) * (c - x) / d) +  # 上升阶段
            ((x >= c) * (x - c) / e)  # 下降阶段
    ) ** 2)


def gaussian_model(x, a, b, c, d):
    """标准高斯模型"""
    return a + b * np.exp(-(x - c) ** 2 / (2 * d ** 2))


def exponential_model(x, a, b, c):
    """指数模型"""
    return a * np.exp(b * x) + c


def logistic_model(x, a, b, c, d):
    """逻辑斯蒂模型"""
    return a / (1 + np.exp(-b * (x - c))) + d


def polynomial_model(x, *params):
    """多项式模型"""
    return np.polyval(params, x)

def get_model_function(model_name, x_data, y_data):
    # 计算统计量（不变）
    y_min = np.min(y_data) if len(y_data) > 0 else 0.0
    y_max = np.max(y_data) if len(y_data) > 0 else 1.0
    y_range = y_max - y_min
    x_min = np.min(x_data) if len(x_data) > 0 else 0.0
    x_max = np.max(x_data) if len(x_data) > 0 else 1.0
    x_peak = x_data[np.argmax(y_data)] if len(y_data) > 0 else (x_min + x_max) / 2

    models = {
        'modified_gaussian': (
            modified_gaussian,
            # 核心修复6：初始参数显式转为float，避免混合int/float导致拟合值类型异常
            [float(y_min), float(y_range), float(x_peak), 30.0, 60.0],
            ['基线值(a)', '峰值高度(b)', '峰值时间(c)', '上升宽度(d)', '下降宽度(e)'],
            ([y_min*0.8, 0.1, x_min, 5.0, 10.0],
             [y_min*1.2, y_range*1.5, x_max, 100.0, 200.0])
        ),
        # 其他模型（如gaussian/exponential）同理，初始参数均加float()转换，此处省略...
    }

    if model_name not in models:
        raise ValueError(f"不支持的模型: {model_name}，支持的模型有: {list(models.keys())}")

    return models[model_name]


# ----------------------
# 数据加载
# ----------------------
def load_data(file_path, sheet_name=0, x_col=None, y_col=None):
    try:
        df = pd.read_excel(file_path, sheet_name=sheet_name)
        print(f"成功读取数据，共 {len(df)} 行")

        if x_col is None:
            x_col = df.columns[0]
        if y_col is None:
            y_col = df.columns[1]

        print(f"使用列 '{x_col}' 作为自变量，'{y_col}' 作为因变量")

        x_data = df[x_col].values
        y_data = df[y_col].values

        if len(x_data) < 5:
            warnings.warn("数据点太少（少于5个），可能导致拟合不稳定")

        # 确保x和y数据长度一致
        if len(x_data) != len(y_data):
            raise ValueError(f"x和y数据长度不匹配: x有{len(x_data)}个点，y有{len(y_data)}个点")

        return x_data, y_data, x_col, y_col, df

    except Exception as e:
        print(f"读取数据出错: {str(e)}")
        raise


# ----------------------
# 回归分析
# ----------------------
def perform_regression(x_data, y_data, model_func, initial_guess, bounds):
    try:
        if len(x_data) != len(y_data):
            raise ValueError(f"回归分析时数据长度不匹配: x={len(x_data)}, y={len(y_data)}")

        with warnings.catch_warnings(record=True) as w:
            warnings.simplefilter("always")

            params, covariance = curve_fit(
                model_func,
                x_data,
                y_data,
                p0=initial_guess,
                maxfev=MAX_ITERATIONS,
                bounds=bounds
            )

            for warning in w:
                if "Covariance of the parameters could not be estimated" in str(warning.message):
                    print("警告: 无法估计参数协方差，拟合可能未收敛")
                    covariance = np.eye(len(params)) * 1e-6

        # 核心修复1：计算拟合值后，去除多余维度+统一类型（避免(73,1)转(73,)的隐性问题）
        y_fit = model_func(x_data, *params)
        y_fit = np.squeeze(y_fit)  # 关键！去除多余维度（如二维数组转一维）
        y_fit = y_fit.astype(float)  # 统一为float类型，避免类型不兼容

        # 再次验证长度，提前拦截问题
        if len(y_fit) != len(y_data):
            raise ValueError(f"拟合后长度不匹配: y_fit={len(y_fit)}, y_data={len(y_data)}")

        # 计算R²值（不变）
        ss_total = np.sum((y_data - np.mean(y_data)) ** 2)
        ss_residual = np.sum((y_data - y_fit) ** 2)
        r_squared = 1 - (ss_residual / ss_total)

        # 计算参数的标准误差（不变）
        try:
            param_errors = np.sqrt(np.diag(covariance))
        except:
            param_errors = np.full(len(params), np.nan)

        return params, param_errors, y_fit, r_squared

    # 异常处理（不变）
    except RuntimeError as e:
        print(f"拟合失败: {str(e)}")
        print("尝试调整初始参数或更换模型...")
        raise
    except Exception as e:
        print(f"回归分析出错: {str(e)}")
        raise


# ----------------------
# 结果可视化
# ----------------------
def plot_results(x_data, y_data, y_fit, x_label, y_label, params, param_names, r_squared, model_name):
    # 确保绘图数据长度一致
    min_len = min(len(x_data), len(y_data), len(y_fit))
    x_data = x_data[:min_len]
    y_data = y_data[:min_len]
    y_fit = y_fit[:min_len]

    fig, ax = plt.subplots(figsize=(10, 6))

    ax.scatter(x_data, y_data, color='blue', alpha=0.7, label='原始数据')

    sorted_indices = np.argsort(x_data)
    ax.plot(x_data[sorted_indices], y_fit[sorted_indices],
            color='red', linewidth=2, label='拟合曲线')

    # 标记峰值点
    peak_idx = np.argmax(y_fit)
    ax.scatter(x_data[sorted_indices][peak_idx], y_fit[sorted_indices][peak_idx],
               color='green', s=100, zorder=5, label=f'预测峰值: {y_fit[sorted_indices][peak_idx]:.2f}')

    ax.set_title(f'{model_name}模型血糖曲线拟合结果', fontsize=14)
    ax.set_xlabel(x_label, fontsize=12)
    ax.set_ylabel(y_label, fontsize=12)

    param_text = f'R²值: {r_squared:.4f}\n'
    for i, (name, param) in enumerate(zip(param_names, params)):
        param_text += f'{name}: {param:.4f}\n'

    ax.text(0.05, 0.05, param_text, transform=ax.transAxes,
            verticalalignment='bottom', bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.5))

    ax.grid(True, linestyle='--', alpha=0.5)
    ax.legend()
    plt.tight_layout()

    return plt


# ----------------------
# 结果保存
# ----------------------
def save_results_to_excel(original_df, x_col, y_col, y_fit, params, param_names, param_errors,
                          r_squared, model_name, output_file):
    try:
        # 核心修复2：强制验证长度，提前暴露问题
        if len(y_fit) != len(original_df):
            raise ValueError(f"拟合值与原始数据长度强制不匹配: 拟合值{len(y_fit)}行，原始数据{len(original_df)}行")

        # 核心修复3：用pd.Series包装拟合值（解决ndarray直接赋值的索引不兼容问题）
        y_fit_series = pd.Series(y_fit, name=f'{y_col}_拟合值', index=original_df.index)
        result_df = pd.concat([original_df, y_fit_series], axis=1)  # 用concat合并，避免直接赋值

        # 修复4：参数解释列表适配（避免越界）
        param_explanations = [
            '基础血糖水平(mmol/L)',
            '餐后血糖最大升高量(mmol/L)',
            '达到血糖峰值的时间(分钟)',
            '上升阶段宽度(值越小上升越陡峭)',
            '下降阶段宽度(值越小下降越陡峭)'
        ]
        used_explanations = param_explanations[:len(param_names)]  # 按实际参数数量截取
        used_explanations += [''] * (len(param_names) - len(used_explanations))  # 补空避免长度不匹配

        # 构建参数DataFrame（优化格式）
        params_df = pd.DataFrame({
            '参数名称': param_names,
            '参数值': params.round(4),  # 保留4位小数，避免科学计数法
            '标准误差': param_errors.round(4),
            '参数解释': used_explanations
        })
        # 追加R²和模型信息（用concat避免loc越界）
        params_df = pd.concat([params_df, pd.DataFrame({
            '参数名称': ['R²值', '模型名称'],
            '参数值': [round(r_squared, 4), model_name],
            '标准误差': ['', ''],
            '参数解释': ['拟合优度，越接近1越好', '使用的非线性模型']
        })], ignore_index=True)

        # 核心修复5：指定openpyxl引擎，确保Excel保存兼容性
        with pd.ExcelWriter(output_file, engine='openpyxl') as writer:
            result_df.to_excel(writer, sheet_name='原始数据与拟合结果', index=False)
            params_df.to_excel(writer, sheet_name='回归参数', index=False)
        print(f"结果已保存到: {os.path.abspath(output_file)}")

    # 异常处理（增加详细调试信息）
    except Exception as e:
        print(f"保存结果出错: {str(e)}")
        # 输出调试信息，方便定位问题
        print(f"调试信息:")
        print(f"- 原始数据形状: {original_df.shape}")
        print(f"- 拟合值形状: {y_fit.shape}")
        print(f"- 拟合值类型: {type(y_fit)}")
        raise


# ----------------------
# 主函数
# ----------------------
def main():
    plt_obj = None
    try:
        print("===== 非线性回归分析开始 =====")

        # 加载数据
        x_data, y_data, x_col, y_col, original_df = load_data(
            INPUT_FILE, SHEET_NAME, X_COLUMN, Y_COLUMN
        )

        # 获取模型函数
        model_func, initial_guess, param_names, bounds = get_model_function(MODEL_NAME, x_data, y_data)
        print(f"使用模型: {MODEL_NAME}")
        print(f"初始参数猜测: {[round(p, 2) for p in initial_guess]}")

        # 执行回归分析
        print("执行非线性回归...")
        params, param_errors, y_fit, r_squared = perform_regression(
            x_data, y_data, model_func, initial_guess, bounds
        )

        print(f"回归完成，R²值: {r_squared:.4f}（越接近1拟合越好）")
        for i, (name, param) in enumerate(zip(param_names, params)):
            print(f"{name}: {param:.4f} (标准误差: {param_errors[i]:.4f})")

        # 绘制结果
        plt_obj = plot_results(x_data, y_data, y_fit, x_col, y_col,
                               params, param_names, r_squared, MODEL_NAME)

        # 保存结果
        save_results_to_excel(original_df, x_col, y_col, y_fit,
                              params, param_names, param_errors,
                              r_squared, MODEL_NAME, OUTPUT_FILE)

        # 保存图表
        if plt_obj is not None:
            plot_file = os.path.splitext(OUTPUT_FILE)[0] + '.png'
            plt_obj.savefig(plot_file, dpi=300, bbox_inches='tight')
            print(f"图表已保存到: {plot_file}")
            plt_obj.show()
        else:
            print("警告: 未能生成图表")

        print("===== 非线性回归分析完成 =====")

    except Exception as e:
        print(f"分析失败: {str(e)}")
        if plt_obj is not None:
            plt_obj.close()
        exit(1)


def showOriginMap():
    """显示原始数据的散点图和折线图"""
    xName = "时间(分钟)"
    yName = "血糖浓度(mmol/L)"

    try:
        # 读取数据
        df = pd.read_excel(INPUT_FILE, SHEET_NAME)

        # 提取数据并确保长度一致
        x = df[xName].values
        y = df[yName].values

        if len(x) != len(y):
            raise ValueError(f"原始数据中 {xName} 和 {yName} 长度不匹配")

        # 绘制散点图
        plt.figure(figsize=(10, 6))
        plt.scatter(x, y, color='blue', alpha=0.7, label='数据点')
        plt.title(f'{xName}与{yName}散点图', fontsize=14)
        plt.xlabel(xName, fontsize=12)
        plt.ylabel(yName, fontsize=12)
        plt.grid(True, linestyle='--', alpha=0.5)
        plt.legend()
        plt.tight_layout()
        plt.show()

        # 绘制折线图
        plt.figure(figsize=(10, 6))
        # 按时间排序以确保折线图正确
        sorted_indices = np.argsort(x)
        plt.plot(x[sorted_indices], y[sorted_indices], color='red', marker='o',
                 linestyle='-', linewidth=2, markersize=6, label='血糖趋势')
        plt.title(f'{xName}与{yName}折线图', fontsize=14)
        plt.xlabel(xName, fontsize=12)
        plt.ylabel(yName, fontsize=12)
        plt.grid(True, linestyle='--', alpha=0.5)
        plt.legend()
        plt.tight_layout()
        plt.show()

    except Exception as e:
        print(f"绘制原始数据图表出错: {str(e)}")


if __name__ == "__main__":
    showOriginMap()  # 先显示原始数据图表
    main()  # 再执行回归分析
