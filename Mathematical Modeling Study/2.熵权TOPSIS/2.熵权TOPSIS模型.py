import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# -------------------------- 1. 读取数据并自动筛选数值列 --------------------------
file_path = r'F:\01\study\2.熵权TOPSIS\TOPSIS.xlsx'  # 替换为你的文件路径
data = pd.read_excel(file_path)

# 自动筛选数值列（排除字符串列如“方案名称”）
numeric_data = data.select_dtypes(include=[np.number]).copy()
numeric_columns = numeric_data.columns.tolist()

if not numeric_columns:
    raise ValueError("未检测到数值列，请检查数据格式！")


# -------------------------- 2. 扩展标准化函数（支持4类指标） --------------------------
def standardize_data(df, max_cols, min_cols, mid_cols, interval_cols):
    """
    标准化数据：根据指标类型应用不同公式
    参数：
    - df: 数值型数据框
    - max_cols: 极大型指标（列名列表）
    - min_cols: 极小型指标（列名列表）
    - mid_cols: 中间型指标（字典，{列名: 最优值}）
    - interval_cols: 区间型指标（字典，{列名: (下限a, 上限b)}）
    返回：标准化后的DataFrame（值越大越优）
    """
    df_std = df.copy()
    for column in df_std.columns:
        x = df_std[column]
        x_max = x.max()
        x_min = x.min()

        # 1. 极大型指标
        if column in max_cols:
            if x_max == x_min:
                df_std[column] = 0.0
            else:
                df_std[column] = (x - x_min) / (x_max - x_min)

        # 2. 极小型指标
        elif column in min_cols:
            if x_max == x_min:
                df_std[column] = 0.0
            else:
                df_std[column] = (x_max - x) / (x_max - x_min)

        # 3. 中间型指标
        elif column in mid_cols:
            x_best = mid_cols[column]  # 最优值
            # 计算最大偏差（用于分母，避免为0）
            max_deviation = max(x_max - x_best, x_best - x_min)
            if max_deviation == 0:
                df_std[column] = 1.0  # 所有值都等于最优值
            else:
                df_std[column] = 1 - np.abs(x - x_best) / max_deviation

        # 4. 区间型指标
        elif column in interval_cols:
            a, b = interval_cols[column]  # 最优区间[a, b]
            if a > b:
                raise ValueError(f"区间型指标{column}的下限a必须≤上限b！")
            # 计算最大偏离范围（用于分母）
            max_range = max(a - x_min, x_max - b)
            if max_range == 0:
                df_std[column] = 1.0  # 所有值都在区间内
            else:
                # 分情况计算标准化值
                df_std[column] = np.where(
                    x < a, 1 - (a - x) / max_range,
                    np.where(x > b, 1 - (x - b) / max_range, 1.0)
                )

        # 未指定类型的指标（默认按极大型处理，或报错）
        else:
            raise ValueError(f"指标{column}未指定类型（极大型/极小型/中间型/区间型）！")

    return df_std


# -------------------------- 3. 熵权计算与TOPSIS核心逻辑（不变） --------------------------
def calculate_entropy_weights(df):
    prob_matrix = df.div(df.sum(axis=0) + np.finfo(float).eps, axis=1)
    entropy = -np.sum(prob_matrix * np.log(prob_matrix + np.finfo(float).eps), axis=0) / np.log(len(df))
    weights = (1 - entropy) / (1 - entropy).sum()
    return weights


def topsis(df, weights):
    weighted_normalized_df = df.mul(weights, axis=1)
    ideal_best = weighted_normalized_df.max(axis=0)
    ideal_worst = weighted_normalized_df.min(axis=0)
    distance_to_best = np.sqrt(((weighted_normalized_df - ideal_best) ** 2).sum(axis=1))
    distance_to_worst = np.sqrt(((weighted_normalized_df - ideal_worst) ** 2).sum(axis=1))
    return distance_to_worst / (distance_to_best + distance_to_worst + np.finfo(float).eps)


# -------------------------- 4. 用户输入：指定指标类型及参数 --------------------------
# 显示自动识别的数值列及索引
print("自动识别的数值指标列（索引从1开始）：")
for idx, col in enumerate(numeric_columns, 1):
    print(f"{idx}: {col}")

# 1. 极大型指标
max_input = input("\n请输入极大型指标的列索引（用空格分隔，如1 4）: ").split()
max_index = [int(i) - 1 for i in max_input]  # 转换为0-based索引
max_columns = [numeric_columns[i] for i in max_index]

# 2. 极小型指标
min_input = input("请输入极小型指标的列索引（用空格分隔，如2 3）: ").split()
min_index = [int(i) - 1 for i in min_input]
min_columns = [numeric_columns[i] for i in min_index]

# 3. 中间型指标（需输入索引和最优值）
mid_columns = {}
mid_input = input("请输入中间型指标的列索引（用空格分隔，如5）: ").split()
if mid_input:
    mid_index = [int(i) - 1 for i in mid_input]
    for idx in mid_index:
        col = numeric_columns[idx]
        x_best = float(input(f"请输入中间型指标「{col}」的最优值: "))
        mid_columns[col] = x_best

# 4. 区间型指标（需输入索引和区间[a, b]）
interval_columns = {}
interval_input = input("请输入区间型指标的列索引（用空格分隔，如6）: ").split()
if interval_input:
    interval_index = [int(i) - 1 for i in interval_input]
    for idx in interval_index:
        col = numeric_columns[idx]
        a, b = map(float, input(f"请输入区间型指标「{col}」的最优区间[a, b]（用空格分隔，如36 37）: ").split())
        interval_columns[col] = (a, b)

# -------------------------- 5. 验证指标类型无重复 --------------------------
all_specified = set(max_columns) | set(min_columns) | set(mid_columns.keys()) | set(interval_columns.keys())
if len(all_specified) != len(max_columns) + len(min_columns) + len(mid_columns) + len(interval_columns):
    raise ValueError("存在指标被重复指定类型，请检查输入！")

if set(all_specified) != set(numeric_columns):
    missing = set(numeric_columns) - all_specified
    raise ValueError(f"以下指标未指定类型：{missing}")

# -------------------------- 6. 执行计算与结果输出 --------------------------
# 标准化数据
standardized_data = standardize_data(
    numeric_data,
    max_cols=max_columns,
    min_cols=min_columns,
    mid_cols=mid_columns,
    interval_cols=interval_columns
)

# 计算熵权与TOPSIS得分
weights = calculate_entropy_weights(standardized_data)
topsis_scores = topsis(standardized_data, weights)

# 合并结果并排序
data['TOPSIS_Score'] = topsis_scores
data_sorted = data.sort_values(by='TOPSIS_Score', ascending=False).reset_index(drop=True)

# -------------------------- 7. 结果保存与可视化 --------------------------
# 保存结果
output_path = 'topsis_results_with_all_types.xlsx'
data_sorted.to_excel(output_path, index=False)

# 可视化
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
x_labels = data_sorted['方案名称'] if '方案名称' in data.columns else [f'样本{i + 1}' for i in range(len(data))]

plt.figure(figsize=(12, 8))
bars = plt.bar(x_labels, data_sorted['TOPSIS_Score'], color='lightgreen')
for bar in bars:
    height = bar.get_height()
    plt.text(bar.get_x() + bar.get_width() / 2, height + 0.01,
             f'{height:.4f}', ha='center', va='bottom')

plt.xlabel('方案')
plt.ylabel('TOPSIS得分（越高越优）')
plt.title('各方案TOPSIS得分对比（含中间型/区间型指标）')
plt.ylim(0, 1.1)
plt.grid(axis='y', alpha=0.3)
plt.tight_layout()
plt.savefig('topsis_scores_all_types.png', dpi=300)
plt.show()

# -------------------------- 8. 打印结果 --------------------------
print(f"\n结果已保存至：{output_path}")
print(f"可视化图表已保存至：topsis_scores_all_types.png")

print("\n各指标熵权：")
for col, w in weights.items():
    print(f"{col}: {w:.6f}")

print("\n各方案TOPSIS得分（降序）：")
for i, row in data_sorted.iterrows():
    name = row['方案名称'] if '方案名称' in row else f'样本{i + 1}'
    print(f"{name}: {row['TOPSIS_Score']:.6f}")
