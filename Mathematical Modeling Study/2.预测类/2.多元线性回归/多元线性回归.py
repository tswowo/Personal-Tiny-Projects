import pandas as pd
import numpy as np
import statsmodels.api as sm
import os
from datetime import datetime
import matplotlib.pyplot as plt


def check_linear_relationship(df, dependent_var, independent_vars, significance_level=0.05):
    """
    对每个自变量做一元线性回归，筛选出显著的特征

    参数:
    df: 数据集
    dependent_var: 因变量名
    independent_vars: 待检验的自变量列表
    significance_level: 显著性水平（默认0.05）

    返回:
    显著的自变量列表
    """
    significant_vars = []
    print("\n===== 一元线性回归特征筛选 =====")
    print(f"显著性水平: {significance_level}")
    print(f"{'变量':<15} {'系数':<10} {'p值':<10} 显著性")
    print("-" * 45)

    for var in independent_vars:
        # 处理该变量的缺失值
        temp_df = df[[dependent_var, var]].dropna()
        if len(temp_df) < 10:
            print(f"{var:<15} 样本量不足   -        跳过")
            continue

        X = temp_df[var]
        y = temp_df[dependent_var]
        X = sm.add_constant(X)  # 添加常数项

        try:
            model = sm.OLS(y, X).fit()
            coef = model.params[var]
            pval = model.pvalues[var]

            # 判断显著性
            if pval < significance_level:
                significant = "显著"
                significant_vars.append(var)
            else:
                significant = "不显著"

            print(f"{var:<15} {coef:.4f}     {pval:.4f}    {significant}")

            # 绘制散点图和回归线（可选）
            # plt.scatter(temp_df[var], temp_df[dependent_var], alpha=0.5)
            # plt.plot(temp_df[var], model.predict(X), color='red')
            # plt.title(f'{var} vs {dependent_var}')
            # plt.xlabel(var)
            # plt.ylabel(dependent_var)
            # plt.show()

        except Exception as e:
            print(f"{var:<15} 分析失败     -        {str(e)}")

    print(f"\n筛选出的显著特征 ({len(significant_vars)}个): {', '.join(significant_vars)}")
    return significant_vars


def multiple_linear_regression(input_file, output_file, dependent_var,
                               independent_vars=None, significance_level=0.05):
    """多元线性回归主函数，增加特征筛选步骤"""
    # 读取数据
    try:
        df = pd.read_excel(input_file)
        print(f"成功读取数据，共 {df.shape[0]} 行，{df.shape[1]} 列")
    except Exception as e:
        print(f"读取数据失败: {e}")
        return None

    # 确定初始自变量列表
    if independent_vars is None:
        independent_vars = [col for col in df.columns if col != dependent_var]
        print(f"初始自变量: {', '.join(independent_vars)}")

    # 步骤1：一元回归筛选特征
    significant_vars = check_linear_relationship(
        df, dependent_var, independent_vars, significance_level
    )

    if not significant_vars:
        print("警告：没有筛选出显著特征，无法进行多元回归")
        return None

    # 步骤2：用筛选后的特征做多元回归
    print("\n===== 多元线性回归分析（筛选后特征） =====")
    # 处理缺失值
    analysis_df = df[[dependent_var] + significant_vars].dropna()
    print(f"有效样本量: {len(analysis_df)}")

    X = analysis_df[significant_vars]
    y = analysis_df[dependent_var]
    X = sm.add_constant(X)  # 添加常数项

    # 执行多元回归
    try:
        model = sm.OLS(y, X).fit()
    except Exception as e:
        print(f"多元回归失败: {e}")
        return None

    # 输出并保存结果（与之前功能一致）
    # ...（省略结果输出和保存代码，与原程序相同）...

    # 打印主要结果
    print("\n===== 多元回归主要结果 =====")
    print(f"R²: {model.rsquared:.4f}")
    print(f"调整后R²: {model.rsquared_adj:.4f}")
    print("\n系数与显著性:")
    print(f"{'变量':<15} {'系数':<10} {'p值':<10} 显著性")
    print("-" * 45)
    for var, coef in model.params.items():
        pval = model.pvalues[var]
        sig = "***" if pval < 0.01 else "**" if pval < 0.05 else "*" if pval < 0.1 else " "
        print(f"{var:<15} {coef:.4f}     {pval:.4f}    {sig}")

    # 保存结果（简化版）
    try:
        with pd.ExcelWriter(output_file, engine='openpyxl') as writer:
            # 系数和p值
            pd.DataFrame({
                '系数': model.params,
                'p值': model.pvalues,
                '95%置信区间下限': model.conf_int().iloc[:, 0],
                '95%置信区间上限': model.conf_int().iloc[:, 1]
            }).to_excel(writer, sheet_name='多元回归结果')

            # 筛选记录
            pd.DataFrame({
                '筛选出的特征': significant_vars,
                '筛选标准': f'一元回归p < {significance_level}'
            }).to_excel(writer, sheet_name='特征筛选结果', index=False)
        print(f"\n结果已保存到 {output_file}")
    except Exception as e:
        print(f"保存结果失败: {e}")

    return model


def main():
    # 参数设置
    input_file = "data.xlsx"
    output_file = "regression_with_selection_results.xlsx"
    dependent_var = "销售额"
    independent_vars = None  # 为None则自动使用所有其他列
    significance_level = 0.05  # 筛选特征的显著性水平

    # 执行分析
    multiple_linear_regression(
        input_file=input_file,
        output_file=output_file,
        dependent_var=dependent_var,
        independent_vars=independent_vars,
        significance_level=significance_level
    )


if __name__ == "__main__":
    main()
