import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score, mean_squared_error, mean_absolute_error
import os
from openpyxl import load_workbook
from openpyxl.drawing.image import Image


def linear_regression_analysis(input_path, output_path, x_col, y_col, plot_image=True):
    """
    通用一元线性回归分析函数，支持中文显示

    参数:
    input_path: 输入Excel文件路径
    output_path: 输出Excel文件路径
    x_col: 自变量列名
    y_col: 因变量列名
    plot_image: 是否生成可视化图表并插入Excel
    """
    # 1. 读取Excel数据
    try:
        df = pd.read_excel(input_path)
    except Exception as e:
        raise Exception(f"读取Excel文件失败: {str(e)}")

    # 检查列是否存在
    if x_col not in df.columns:
        raise ValueError(f"输入文件中未找到列: {x_col}")
    if y_col not in df.columns:
        raise ValueError(f"输入文件中未找到列: {y_col}")

    # 提取数据并处理缺失值
    x_data = df[x_col].dropna().values.reshape(-1, 1)
    y_data = df[y_col].dropna().values

    if len(x_data) != len(y_data):
        raise ValueError("自变量和因变量的有效数据行数不一致")

    if len(x_data) < 2:
        raise ValueError("数据量不足，至少需要2组数据才能进行回归分析")

    # 2. 执行线性回归
    model = LinearRegression()
    model.fit(x_data, y_data)

    # 3. 获取回归结果
    intercept = model.intercept_  # 截距
    slope = model.coef_[0]  # 斜率
    y_pred = model.predict(x_data)  # 预测值

    # 4. 计算评估指标
    r2 = r2_score(y_data, y_pred)  # 决定系数
    mse = mean_squared_error(y_data, y_pred)  # 均方误差
    rmse = np.sqrt(mse)  # 均方根误差
    mae = mean_absolute_error(y_data, y_pred)  # 平均绝对误差

    # 5. 准备结果数据
    result_summary = pd.DataFrame({
        '项目': ['回归方程', '截距(a)', '斜率(b)', '决定系数(R²)',
                 '均方误差(MSE)', '均方根误差(RMSE)', '平均绝对误差(MAE)'],
        '值': [f'{y_col} = {intercept:.4f} + {slope:.4f}×{x_col}',
               f'{intercept:.4f}',
               f'{slope:.4f}',
               f'{r2:.4f}',
               f'{mse:.4f}',
               f'{rmse:.4f}',
               f'{mae:.4f}']
    })

    # 6. 生成预测与实际值对比表
    comparison = pd.DataFrame({
        x_col: x_data.flatten(),
        f'实际{y_col}': y_data,
        f'预测{y_col}': y_pred.round(4),
        '残差': (y_data - y_pred).round(4)
    })

    # 7. 保存结果到Excel
    with pd.ExcelWriter(output_path, engine='openpyxl') as writer:
        result_summary.to_excel(writer, sheet_name='回归分析 summary', index=False)
        comparison.to_excel(writer, sheet_name='实际值与预测值对比', index=False)

    # 8. 生成可视化图表并插入Excel（已解决中文显示问题）
    if plot_image:
        # 配置中文字体，解决中文显示问题
        plt.rcParams['font.sans-serif'] = ['SimHei', 'Arial Unicode MS']  # 支持中文的字体
        plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示异常

        plt.figure(figsize=(10, 6))
        plt.scatter(x_data, y_data, color='blue', label='实际数据')
        plt.plot(x_data, y_pred, color='red', linewidth=2,
                 label=f'回归直线: {y_col}={intercept:.2f}+{slope:.2f}{x_col}')
        plt.xlabel(x_col)
        plt.ylabel(y_col)
        plt.title(f'{x_col}与{y_col}的一元线性回归分析')
        plt.legend()
        plt.grid(alpha=0.3)

        # 保存图表为临时图片
        temp_image = 'temp_regression_plot.png'
        plt.savefig(temp_image, dpi=300, bbox_inches='tight')
        plt.close()

        # 将图片插入Excel
        wb = load_workbook(output_path)
        ws = wb['回归分析 summary']
        img = Image(temp_image)
        ws.add_image(img, 'D2')  # 插入到D2单元格位置
        wb.save(output_path)

        # 删除临时图片
        if os.path.exists(temp_image):
            os.remove(temp_image)

    print(f"分析完成！结果已保存至: {output_path}")
    return result_summary, comparison


if __name__ == "__main__":
    # 配置参数 - 根据实际情况修改
    INPUT_FILE = "data.xlsx"  # 输入Excel文件路径
    OUTPUT_FILE = "regression_result.xlsx"  # 输出结果文件路径
    X_COLUMN = "广告费用(万元)x"  # 自变量列名（与Excel中一致）
    Y_COLUMN = "销售额(万元)y"  # 因变量列名（与Excel中一致）

    # 执行分析
    summary, comparison = linear_regression_analysis(
        input_path=INPUT_FILE,
        output_path=OUTPUT_FILE,
        x_col=X_COLUMN,
        y_col=Y_COLUMN,
        plot_image=True
    )

    # 打印主要结果
    print("\n=== 回归分析摘要 ===")
    print(summary)
