import pandas as pd

# pandas提供两种基本数据类型

# Series 一维带标签数组
# 列表初始化
s = pd.Series([10, 20, 30, 40], name="数值")
print(s)
# 字典初始化
s = pd.Series({"a": 10, "b": 20, "c": 30}, name="数值")
print(s)

# DataFrame 二维表格 带索引的表格，其实内部是多个Series
# 从字典创建 每一列
data = {
    "姓名": ["张三", "李四", "王五"],
    "年龄": [20, 25, 30],
    "性别": ["男", "女", "男"]
}
df = pd.DataFrame(data)
print(df)
# 从列表创建 每一行
df = pd.DataFrame(
    data=[[1, "A"], [2, "B"], [3, "C"]],  # 每一行
    columns=["ID", "类别"],  # 给每一列起索引
    index=["a", "b", "c"]  # 给每一行起索引
)
print(df)
