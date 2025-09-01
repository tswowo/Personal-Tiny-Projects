import random

# 模拟次数（一百万次）
n_simulations = 1000000  
count_success = 0  # 统计系统正常的次数

for _ in range(n_simulations):
    # 生成每个元件的状态：True表示正常（概率0.9），False表示故障（概率0.1）
    status = {
        1: random.random() < 0.9,
        2: random.random() < 0.9,
        3: random.random() < 0.9,
        4: random.random() < 0.9,
        5: random.random() < 0.9
    }
    # 判断系统是否正常（满足至少一条路径）
    path1 = status[1] and status[2]
    path2 = status[3] and status[4]
    path3 = status[1] and status[5] and status[4]
    path4 = status[3] and status[5] and status[2]
    if path1 or path2 or path3 or path4:
        count_success += 1

# 计算系统可靠性（正常次数/总次数）
reliability = count_success / n_simulations
print(f"系统可靠性约为：{reliability:.6f}")