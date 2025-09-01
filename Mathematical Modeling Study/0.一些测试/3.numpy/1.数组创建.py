import numpy as np

#从列表创建
nums=np.array([1,2,3])
print(nums)

#全0
print(np.zeros((2,3)))

#全1
print(np.ones((1,4)))

#连续整数    np.arange(start, stop, step)
print(np.arange(0,10,2))

#均匀分布 	np.linspace(start, stop, num)
print(np.linspace(0,1,5) )

#单位矩阵
print(np.eye(3))

#随机数组
print(np.random.rand(2,2))

#随机整数矩阵
print(np.random.randint(1,10,(2,3)))