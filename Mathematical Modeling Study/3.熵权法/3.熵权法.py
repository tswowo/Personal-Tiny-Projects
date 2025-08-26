import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# 设置中文显示
plt.rcParams['font.sans-serif'] = ['SimHei', 'Microsoft YaHei', 'Arial Unicode MS']
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题


def entropy_weight(data, positive_indicators):
    """
    熵权法计算函数

    参数:
    data: DataFrame，包含评价指标数据
    positive_indicators: 正向指标的列名列表

    返回:
    weights: 各指标的权重
    scores: 各样本的综合得分
    """
    values = data.values
    n, m = values.shape
    columns = data.columns

    # 数据标准化
    normalized_data = np.zeros_like(values, dtype=np.float64)
    for j in range(m):
        col_data = values[:, j]
        col_min, col_max = np.min(col_data), np.max(col_data)
        if col_max == col_min:
            normalized_data[:, j] = 0.5  # 避免除零，赋予默认值
        else:
            if columns[j] in positive_indicators:
                # 正向指标标准化：越高越好
                normalized_data[:, j] = (col_data - col_min) / (col_max - col_min)
            else:
                # 负向指标标准化：越低越好
                normalized_data[:, j] = (col_max - col_data) / (col_max - col_min)

    # 计算信息熵与权重
    eps = 1e-10  # 避免log(0)
    p = (normalized_data + eps) / np.sum(normalized_data + eps, axis=0)
    e = -np.sum(p * np.log(p), axis=0) / np.log(n)  # 信息熵
    g = 1 - e  # 差异系数
    weights = g / np.sum(g)  # 权重归一化

    # 计算样本综合得分
    scores = np.sum(normalized_data * weights, axis=1)

    return weights, scores


def analyze_enterprise_data(file_path="企业绩效评价数据.xlsx"):
    """
    读取企业数据Excel文件，进行熵权法分析并生成结果

    参数:
    file_path: Excel文件路径
    """
    # 读取Excel数据
    try:
        data = pd.read_excel(file_path)
        print(f"成功读取数据文件: {file_path}")
        print(f"数据规模: {data.shape[0]}家企业, {data.shape[1]}个指标")
    except Exception as e:
        print(f"读取文件失败: {e}")
        return

    # 定义正向指标（数值越大越好）
    positive_indicators = ['营收增长率(%)', '利润率(%)', '研发投入占比(%)']

    # 计算权重和综合得分
    weights, scores = entropy_weight(data, positive_indicators)

    # 输出指标权重
    print("\n=== 指标权重 ===")
    for i, col in enumerate(data.columns):
        print(f"{col}: {weights[i]:.4f}")

    # 输出前10名企业得分
    print("\n=== 综合得分前10名企业 ===")
    top10_indices = np.argsort(scores)[-10:][::-1]  # 按得分降序取前10
    for idx in top10_indices:
        print(f"企业{idx + 1}: 得分 {scores[idx]:.4f}")

    # 保存包含得分的数据
    result_data = data.copy()
    result_data['综合得分'] = scores.round(4)
    result_data.to_excel("企业绩效评价结果.xlsx", index=False)
    print("\n包含综合得分的结果已保存到: 企业绩效评价结果.xlsx")

    # 绘制指标权重柱状图
    plt.figure(figsize=(10, 6))
    bars = plt.bar(data.columns, weights, color=['#1f77b4', '#ff7f0e', '#2ca02c', '#d62728', '#9467bd'])
    plt.title('企业绩效评价指标权重分布', fontsize=15, pad=20)
    plt.ylabel('权重值', fontsize=12)
    plt.xticks(rotation=30, ha='right')
    # 在柱子上添加权重值
    for bar, weight in zip(bars, weights):
        plt.text(bar.get_x() + bar.get_width() / 2, bar.get_height() + 0.005,
                 f'{weight:.4f}', ha='center', fontsize=10)
    plt.tight_layout()
    plt.show()

    # 绘制综合得分分布直方图
    plt.figure(figsize=(10, 6))
    n, bins, patches = plt.hist(scores, bins=15, alpha=0.7, color='#2ca02c', edgecolor='black')
    plt.title(f'{len(data)}家企业综合得分分布', fontsize=15, pad=20)
    plt.xlabel('综合得分', fontsize=12)
    plt.ylabel('企业数量', fontsize=12)
    # 添加平均值线
    mean_score = np.mean(scores)
    plt.axvline(mean_score, color='red', linestyle='--', linewidth=2,
                label=f'平均得分: {mean_score:.4f}')
    plt.legend(fontsize=10)
    plt.grid(axis='y', alpha=0.3)
    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    # 分析数据
    analyze_enterprise_data()
