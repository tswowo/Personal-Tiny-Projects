import numpy as np
import pandas as pd

# 读取概率转移矩阵和初始状态数据
mat = pd.read_excel(r'data.xlsx', sheet_name=r'概率转移矩阵', index_col=0)
now_data = pd.read_excel(r'data.xlsx', sheet_name=r'初始值', index_col=0)

# 数据格式转换：确保转移矩阵和初始状态为numpy数组
transition_matrix = mat.values
initial_state = now_data.values.flatten()  # 转换为一维数组

# 检查矩阵格式是否正确（行列数相等）
if transition_matrix.shape[0] != transition_matrix.shape[1]:
    raise ValueError("转移矩阵必须是方阵")

# 检查初始状态与转移矩阵维度是否匹配
if len(initial_state) != transition_matrix.shape[0]:
    raise ValueError("初始状态维度与转移矩阵不匹配")


def predict_future(initial, matrix, steps):
    """
    预测未来指定步数的状态概率分布

    参数:
    initial: 初始状态概率分布（一维数组）
    matrix: 状态转移矩阵（方阵）
    steps: 预测步数

    返回:
    包含各步预测结果的字典
    """
    predictions = {0: initial}  # 第0步为初始状态
    current = initial

    for i in range(1, steps + 1):
        # 马尔可夫链核心公式：下一刻状态 = 当前状态 × 转移矩阵
        current = np.dot(current, matrix)
        predictions[i] = current

    return predictions


# 预测未来5步的状态（可根据需要调整步数）
future_steps = 5
forecast_results = predict_future(initial_state, transition_matrix, future_steps)

# 打印预测结果（格式化输出）
print("状态名称:", mat.columns.tolist())
print(f"初始状态（第0步）: {initial_state.round(4)}")

for step, prob in forecast_results.items():
    if step > 0:
        print(f"第{step}步预测: {prob.round(4)}")

# 可选：将结果转换为DataFrame便于查看和保存
result_df = pd.DataFrame.from_dict(forecast_results, orient='index', columns=mat.columns)
print("\n预测结果表格:")
print(result_df.round(4))

# 保存结果到Excel
result_df.to_excel(r'预测结果.xlsx')
print("\n预测结果已保存至'预测结果.xlsx'")
