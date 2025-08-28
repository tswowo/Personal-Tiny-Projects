import pandas as pd

try:#尝试一下
    df=pd.read_excel("数据读写input.xlsx",sheet_name="Sheet1")
except Exception as e:#若错误，打印错误信息
    print(f"文件读取出错：{e}")
else:#没有错误时
    print(f"文件读取成功：{"数据读写input"}")
finally:#无论如何都会执行
    print("是的，无论如何都会执行")

if 'df' in locals():#如果df已定义
    print(df)
    for thislen in df:
        print(df[thislen])