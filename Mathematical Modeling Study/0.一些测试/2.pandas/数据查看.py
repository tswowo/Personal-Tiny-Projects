import pandas as pd

data = {
    'Name': ['Alice', 'Bob', 'Charlie'],
    'Age': [25, 30, 35],
    'City': ['New York', 'London', 'Paris']
}
df = pd.DataFrame(data)

# 查看前几行（默认5行）
print("查看前几行")
print(df.head())

# 查看后几行
print("查看后几行")
print(df.tail())

# 查看基本信息（列名、数据类型、非空值数量）
print("查看基本信息")
print(df.info())

# 查看统计摘要
print("查看统计摘要")
print(df.describe())