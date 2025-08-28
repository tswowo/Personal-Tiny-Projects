import pandas as pd
import matplotlib.pyplot as plt

def showOriginMap():
    # 关键：使用 Windows 自带的“微软雅黑”字体（无需额外安装）
    plt.rcParams["font.sans-serif"] = ["Microsoft YaHei"]  # 解决中文显示问题
    plt.rcParams["axes.unicode_minus"] = False  # 解决负号显示异常的问题（可选）

    # 读取 Excel 数据（确保工作表索引/名称正确）
    df = pd.read_excel(r'data.xlsx', 0)  # 0 表示第一个工作表，避免名称问题

    # 提取 x 和 y（确保列名与 Excel 中完全一致，包括空格、括号）
    x = df['广告费用(万元)x']
    y = df['销售额(万元)y']

    # 绘制散点图（中文标签 now 正常显示）
    plt.figure(figsize=(10, 6))
    plt.scatter(x, y, color='blue', alpha=0.7, label='数据点')
    plt.title('广告费用与销售额散点图', fontsize=14)  # 中文标题
    plt.xlabel('广告费用(万元)', fontsize=12)  # 中文 x 轴标签
    plt.ylabel('销售额(万元)', fontsize=12)  # 中文 y 轴标签
    plt.grid(True, linestyle='--', alpha=0.5)
    plt.legend()
    plt.show()

    # 绘制折线图
    plt.figure(figsize=(10, 6))
    plt.plot(x, y, color='red', marker='o', linestyle='-', linewidth=2, markersize=6, label='销售额趋势')
    plt.title('广告费用与销售额折线图', fontsize=14)
    plt.xlabel('广告费用(万元)', fontsize=12)
    plt.ylabel('销售额(万元)', fontsize=12)
    plt.grid(True, linestyle='--', alpha=0.5)
    plt.legend()
    plt.show()
if __name__ == "__main__":
    showOriginMap()