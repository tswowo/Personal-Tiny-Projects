import numpy as np

arr=np.random.randint(1,10,(2,3))
print(arr)
print(arr[0])
print(arr[0,1])

arr=np.arange(0,11,1)
print(arr[0:5:2])

arr = np.array([[1, 2, 3, 4],
                [5, 6, 7, 8],
                [9, 10, 11, 12],
                [13, 14, 15, 16]])

# 前2行，第2-3列（索引1到2，不含3）
print(arr[:2, 1:3])

# 每隔1行（取第0、2行），所有列
print(arr[::2, :])

#布尔数组
arr=np.arange(1,11)>7
print(arr)
print(sum(arr))

#重塑
arr= np.arange(12)
print(arr.reshape(3,4))
print(arr.reshape(6,-1))
print(arr.reshape(-1,6).reshape(1,-1))