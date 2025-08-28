import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.metrics import mean_squared_error
from math import sqrt
import warnings

warnings.filterwarnings('ignore')

# 优化中文显示配置（确保Windows系统能正常显示）
plt.rcParams["font.sans-serif"] = ["Microsoft YaHei"]  # 解决中文显示问题
plt.rcParams["axes.unicode_minus"] = False  # 解决负号显示异常的问题（可选）
plt.rcParams['figure.figsize'] = (14, 8)  # 默认图表大小


def load_and_clean_data(file_path):
    """加载并清洗数据（确保格式绝对正确）"""
    # 读取Excel，强制指定列名
    df = pd.read_excel(file_path, names=['date', 'value'])  # 强制第一列日期、第二列数值

    # 1. 日期处理：强制转换为datetime，删除转换失败的行
    df['date'] = pd.to_datetime(df['date'], errors='coerce')
    # 2. 数值处理：强制转换为float，删除转换失败的行
    df['value'] = pd.to_numeric(df['value'], errors='coerce')
    # 3. 删除空值和重复行
    df = df.dropna().drop_duplicates().sort_values('date').reset_index(drop=True)

    # 强制设置日度频率（确保时间连续）
    df = df.set_index('date').asfreq('D').dropna()

    print(f"数据加载完成：")
    print(f"- 时间范围：{df.index.min().strftime('%Y-%m-%d')} ~ {df.index.max().strftime('%Y-%m-%d')}")
    print(f"- 数据量：{len(df)} 条")
    print(f"- 数值范围：{df['value'].min():.2f} ~ {df['value'].max():.2f}")
    return df['value'].values, df.index  # 返回numpy数组和日期索引


def split_data(data, test_size=0.2):
    """分割训练集/测试集（按时间顺序）"""
    split_idx = int(len(data) * (1 - test_size))
    return data[:split_idx], data[split_idx:]


def arima_manual_predict(history, p=2, d=1, q=2, steps=12):
    """
    手动ARIMA预测：完全绕开statsmodels的forecast()方法
    逻辑：1. 差分平稳 2. 计算AR和MA系数 3. 手动推导预测值 4. 差分还原
    """
    # 步骤1：对历史数据做d阶差分（这里d=1，一阶差分）
    diff = np.diff(history, n=d)

    # 步骤2：计算AR(p)系数（自回归系数）- 用滞后p阶的自相关计算
    def autocorr(x, lag):
        """计算自相关系数"""
        return np.corrcoef(np.array([x[:-lag], x[lag:]]))[0, 1]

    ar_coeffs = [autocorr(diff, lag=i) for i in range(1, p + 1)]

    # 步骤3：计算MA(q)系数（移动平均系数）- 用残差的自相关计算
    # 先通过AR(p)计算残差
    ar_pred = np.zeros_like(diff)
    for i in range(p, len(diff)):
        ar_pred[i] = np.dot(ar_coeffs, diff[i - p:i])
    residuals = diff - ar_pred
    # 再计算残差的自相关作为MA系数
    ma_coeffs = [autocorr(residuals, lag=i) for i in range(1, q + 1)]

    # 步骤4：手动逐步预测（差分后的序列）
    diff_pred = []
    # 初始化：用历史差分的最后p个值和残差的最后q个值
    last_diff = diff[-p:] if p > 0 else np.array([])
    last_residuals = residuals[-q:] if q > 0 else np.array([])

    for _ in range(steps):
        # AR部分：前p个差分的加权和
        ar_part = np.dot(ar_coeffs, last_diff) if p > 0 else 0
        # MA部分：前q个残差的加权和
        ma_part = np.dot(ma_coeffs, last_residuals) if q > 0 else 0
        # 差分预测值
        current_diff_pred = ar_part + ma_part
        diff_pred.append(current_diff_pred)

        # 更新历史（用于下一次预测）
        if p > 0:
            last_diff = np.roll(last_diff, -1)
            last_diff[-1] = current_diff_pred
        if q > 0:
            last_residuals = np.roll(last_residuals, -1)
            last_residuals[-1] = current_diff_pred  # 残差用当前预测值近似

    # 步骤5：差分还原（从差分序列恢复原始序列）
    pred = np.zeros(steps)
    pred[0] = history[-1] + diff_pred[0]  # 第一个预测值 = 最后一个历史值 + 第一个差分预测值
    for i in range(1, steps):
        pred[i] = pred[i - 1] + diff_pred[i]  # 后续值 = 前一个预测值 + 当前差分预测值

    return np.round(pred, 2)  # 保留2位小数


def plot_results(train, test, test_pred, future_pred, train_dates, test_dates, future_dates):
    """绘制所有结果图，确保图像能正常显示"""
    # 创建新图形
    plt.figure(figsize=(16, 9))

    # 绘制历史训练数据
    plt.plot(train_dates, train, label='历史训练数据', color='#1f77b4', alpha=0.8, linewidth=1.5)
    # 绘制测试集真实值和预测值
    plt.plot(test_dates, test, label='测试集真实值', color='#ff7f0e', alpha=0.8, linewidth=1.5)
    plt.plot(test_dates, test_pred, label='测试集预测值', color='#ff7f0e', linestyle='--', linewidth=1.5)
    # 绘制未来预测值
    plt.plot(future_dates, future_pred, label=f'未来{len(future_pred)}天预测值',
             color='#2ca02c', linestyle='--', linewidth=2)

    # 添加网格、标题和标签
    plt.title('时间序列ARIMA预测结果（手动计算版）', fontsize=18, pad=20)
    plt.xlabel('日期', fontsize=14, labelpad=10)
    plt.ylabel('数值', fontsize=14, labelpad=10)
    plt.legend(fontsize=12, loc='upper left')
    plt.grid(alpha=0.3, linestyle='--')
    plt.xticks(rotation=45, ha='right')  # 日期旋转45度，右对齐

    # 调整布局
    plt.tight_layout()

    # 强制显示图像（解决不显示问题的关键）
    plt.show(block=True)


# ------------------- 主程序（确保绘图正常）-------------------
if __name__ == "__main__":
    # 1. 加载数据（替换为你的Excel路径）
    data, all_dates = load_and_clean_data(file_path="time_series_data.xlsx")

    # 2. 分割训练集/测试集
    train, test = split_data(data, test_size=0.2)
    train_dates = all_dates[:len(train)]
    test_dates = all_dates[len(train):len(train) + len(test)]

    print(f"\n数据分割：训练集{len(train)}条，测试集{len(test)}条")

    # 3. 测试集手动预测（验证模型）
    test_pred = []
    for i in range(len(test)):
        # 每次用训练集+已预测的测试集部分作为历史数据
        current_history = np.concatenate([train, test_pred[:i]])
        # 手动预测1步
        step_pred = arima_manual_predict(current_history, steps=1)
        test_pred.append(step_pred[0])
    test_pred = np.array(test_pred)

    # 计算测试集误差
    rmse = sqrt(mean_squared_error(test, test_pred))
    print(f"\n测试集性能：RMSE = {rmse:.4f}")

    # 4. 未来预测（12天）
    full_history = np.concatenate([train, test])
    future_pred = arima_manual_predict(full_history, steps=12)

    # 生成未来日期
    last_date = all_dates[-1]
    future_dates = [last_date + pd.Timedelta(days=i + 1) for i in range(12)]

    # 5. 输出未来预测结果
    print(f"\n未来12天预测结果：")
    future_df = pd.DataFrame({
        '日期': [d.strftime('%Y-%m-%d') for d in future_dates],
        '预测值': future_pred
    })
    print(future_df.to_string(index=False))

    # 6. 绘制所有结果（确保显示）
    print("\n正在绘制预测结果图...")
    plot_results(train, test, test_pred, future_pred, train_dates, test_dates, future_dates)
    print("绘图完成！")
