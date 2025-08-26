import numpy as np
import pandas as pd


def generate_enterprise_data(n_samples=80, output_file="企业绩效评价数据.xlsx"):
    """
    生成企业绩效评价的模拟数据

    参数:
    n_samples: 样本数量，默认为80
    output_file: 输出的Excel文件名
    """
    # 设置随机种子，保证结果可复现
    np.random.seed(42)

    # 正向指标（数值越大越好）
    revenue_growth = np.random.normal(8, 3, n_samples)  # 营收增长率：均值8%，标准差3%
    profit_rate = np.random.normal(12, 4, n_samples)  # 利润率：均值12%，标准差4%
    rd_ratio = np.random.normal(5, 2, n_samples)  # 研发投入占比：均值5%，标准差2%

    # 负向指标（数值越小越好）
    debt_ratio = np.random.normal(50, 10, n_samples)  # 资产负债率：均值50%，标准差10%
    complaint_rate = np.random.normal(3, 1.5, n_samples)  # 客户投诉率：均值3‰，标准差1.5‰

    # 确保所有值为正数（避免数据异常）
    revenue_growth = np.clip(revenue_growth, 0.1, None)
    profit_rate = np.clip(profit_rate, 0.1, None)
    rd_ratio = np.clip(rd_ratio, 0.1, None)
    debt_ratio = np.clip(debt_ratio, 10, 90)
    complaint_rate = np.clip(complaint_rate, 0.1, None)

    # 创建DataFrame
    data = pd.DataFrame({
        '营收增长率(%)': revenue_growth.round(2),
        '利润率(%)': profit_rate.round(2),
        '研发投入占比(%)': rd_ratio.round(2),
        '资产负债率(%)': debt_ratio.round(2),
        '客户投诉率(‰)': complaint_rate.round(2)
    })

    # 保存数据到Excel
    data.to_excel(output_file, index=False)
    print(f"已生成{len(data)}家企业的模拟数据")
    print(f"数据已保存到: {output_file}")

    return data


if __name__ == "__main__":
    # 生成80家企业的数据，保存到默认文件
    generate_enterprise_data()
