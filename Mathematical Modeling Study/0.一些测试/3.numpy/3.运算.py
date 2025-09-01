import numpy as np

arr = np.array([[1,2,3],[4,5,6],[7,8,9]])

print(np.sum(arr))        # 总和 → 45
print(np.mean(arr))       # 平均值 → 5.0
print(np.max(arr, axis=0))# 按列求最大值 → [7 8 9]
print(np.min(arr, axis=1))# 按行求最小值 → [1 4 7]
print(np.std(arr))        # 标准差 → 2.581988897471611
print(np.cumsum(arr))     # 累积和 → [1 3 6 10 15 21 28 36 45]