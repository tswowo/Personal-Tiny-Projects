import pandas as pd

#读取
df=pd.read_csv("data.csv")
print(df)
df=pd.read_excel("data.xlsx",sheet_name="数据结果")
print(df)
# df=pd.read_json("data.json")
# print(df)

# 写入
df = pd.DataFrame(
    {
        "姓名": ['张三', '李四', '王五'],
        "性别": ['男', '男', '女'],
    }
)
print(df)

# 写入
df.to_csv("output.csv", index=False, encoding="utf-8")
df.to_excel("output.xlsx", sheet_name="数据结果", index=False)
