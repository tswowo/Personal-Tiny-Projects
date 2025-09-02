import pandas as pd

# 大写汉字分数 -> 整数的映射字典（覆盖文件中所有出现的分值）
def chubuqiuhe(data_path,score):
    score_map = {
        '叁': 3,    # 对应 3 分
        '伍': 5,    # 对应 5 分
        '陆': 6,    # 对应 6 分
        '拾': 10,   # 对应 10 分
        '拾伍': 15, # 对应 15 分
        '贰拾': 20, # 对应 20 分
        '叁拾': 30  # 对应 30 分
    }
    df=pd.read_excel(data_path)

    if(score!=r'分数'):
        df['分数'] = df[score].map(score_map).fillna(df[score])

    df=df.rename(columns={'专业班级':'班级'})

    sx_df=df.loc[df['班级']==r'人工智能24-2',['姓名','分数','学号']]

    print(sx_df)

    group_df=sx_df.groupby('姓名', as_index=False).agg({
    '学号': 'first',  # 对学号取第一个值（或用'last'取最后一个）
    '分数': 'sum'     # 对分数求和
    })

    print(group_df)

    group_df.to_excel(data_path[:-5]+"_处理结果.xlsx")

def merge_solve():
    data_paths=['2025年六月份德育加分表_处理结果.xlsx'
               '2025年七月份德育加分表_处理结果.xlsx',
               '校组织六月份加分汇总_处理结果.xlsx',
               '校组织七月份加分汇总_处理结果.xlsx']
    dfs=[]
    for path in data_paths:
        d=pd.read_excel(path,index_col=0)
        dfs.append(d)
    for i in dfs:
        print(i)
    df=pd.concat(dfs, ignore_index=True)
    group_df=df.groupby('姓名', as_index=False).agg({
    '学号': 'first',  # 对学号取第一个值（或用'last'取最后一个）
    '分数': 'sum'     # 对分数求和
    })
    print(group_df)
    group_df.to_excel("最终_处理结果.xlsx")


chubuqiuhe(r'2025年六月份德育加分表.xlsx','分数')
chubuqiuhe(r'2025年七月份德育加分表.xlsx','分数')
chubuqiuhe(r'校组织六月份加分汇总.xlsx','分值')
chubuqiuhe(r'校组织七月份加分汇总.xlsx','分值')
merge_solve()