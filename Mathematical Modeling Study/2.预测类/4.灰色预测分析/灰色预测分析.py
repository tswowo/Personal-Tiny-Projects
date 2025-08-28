import pandas as pd
import numpy as np
import os


class GreyPrediction:
    """灰色预测GM(1,1)模型实现"""

    def __init__(self, data, column_name=None, forecast_num=1):
        """初始化灰色预测模型"""
        # 确保数据为非负
        self.data = np.array(data)
        if np.any(self.data < 0):
            min_val = np.min(self.data)
            self.data = self.data - min_val + 1e-6  # 平移变换确保非负
            self.shift = min_val - 1e-6  # 记录平移量，用于还原
        else:
            self.shift = 0

        self.n = len(self.data)  # 数据长度
        self.forecast_num = forecast_num  # 预测步数
        self.column_name = column_name if column_name else "data"

        # 模型参数初始化
        self.a = None  # 发展系数
        self.b = None  # 灰色作用量
        self.x1 = None  # 1-AGO序列
        self.x0_hat = None  # 预测的原始序列
        self.forecast = None  # 预测结果

        # 检验指标初始化
        self.residuals = None  # 残差
        self.relative_errors = None  # 相对误差
        self.c = None  # 后验差比
        self.p = None  # 小误差概率

    def _ago(self):
        """累加生成(AGO)"""
        self.x1 = np.zeros_like(self.data, dtype=np.float64)
        self.x1[0] = self.data[0]
        for i in range(1, self.n):
            self.x1[i] = self.x1[i - 1] + self.data[i]
        return self.x1

    def _mean_generating(self):
        """紧邻均值生成"""
        z1 = np.zeros_like(self.x1, dtype=np.float64)
        for i in range(1, self.n):
            z1[i] = 0.5 * self.x1[i] + 0.5 * self.x1[i - 1]
        return z1[1:]  # 第一个元素为0，从第二个开始使用

    def fit(self):
        """拟合GM(1,1)模型"""
        # 1. 计算1-AGO序列
        self._ago()

        # 2. 计算紧邻均值生成序列
        z1 = self._mean_generating()

        # 3. 构造矩阵B和向量Y
        B = np.zeros((self.n - 1, 2), dtype=np.float64)
        Y = np.zeros((self.n - 1, 1), dtype=np.float64)

        for i in range(self.n - 1):
            B[i, 0] = -z1[i]
            B[i, 1] = 1
            Y[i, 0] = self.data[i + 1]

        # 4. 最小二乘法求解参数 [a, b]^T
        B_T = B.T
        params = np.linalg.inv(B_T @ B) @ B_T @ Y
        self.a = params[0, 0]
        self.b = params[1, 0]

        # 5. 计算拟合值
        self.x0_hat = np.zeros_like(self.data, dtype=np.float64)
        self.x0_hat[0] = self.data[0]

        for i in range(1, self.n):
            x1_hat_i = (self.data[0] - self.b / self.a) * np.exp(-self.a * i) + self.b / self.a
            x1_hat_i_1 = (self.data[0] - self.b / self.a) * np.exp(-self.a * (i - 1)) + self.b / self.a
            self.x0_hat[i] = x1_hat_i_1 - x1_hat_i

        # 6. 模型检验
        self._test_model()

        return self

    def _test_model(self):
        """模型检验"""
        # 计算残差和相对误差
        self.residuals = self.data - self.x0_hat
        self.relative_errors = np.abs(self.residuals) / self.data * 100  # 百分比

        # 计算后验差检验指标
        # 原始数据方差
        s1_sq = np.var(self.data, ddof=1)
        # 残差方差
        s2_sq = np.var(self.residuals, ddof=1)
        # 后验差比
        self.c = np.sqrt(s2_sq) / np.sqrt(s1_sq) if s1_sq != 0 else 0

        # 小误差概率
        mean_residual = np.mean(np.abs(self.residuals))
        self.p = np.sum(np.abs(self.residuals - mean_residual) < 0.6745 * np.sqrt(s1_sq)) / self.n if s1_sq != 0 else 1

    def predict(self):
        """预测未来数据"""
        if self.a is None or self.b is None:
            raise ValueError("模型尚未拟合，请先调用fit()方法")

        # 预测未来forecast_num个数据点
        self.forecast = np.zeros(self.forecast_num, dtype=np.float64)
        for k in range(1, self.forecast_num + 1):
            x1_hat_nk = (self.data[0] - self.b / self.a) * np.exp(-self.a * (self.n + k - 1)) + self.b / self.a
            x1_hat_nk_1 = (self.data[0] - self.b / self.a) * np.exp(-self.a * (self.n + k - 2)) + self.b / self.a
            self.forecast[k - 1] = x1_hat_nk_1 - x1_hat_nk

        # 还原平移变换
        self.data += self.shift
        self.x0_hat += self.shift
        self.forecast += self.shift

        return self.forecast

    def get_evaluation(self):
        """获取模型评价结果"""
        if self.c is None or self.p is None:
            raise ValueError("模型尚未检验，请先调用fit()方法")

        # 模型精度等级
        grade = "优" if self.p > 0.95 and self.c < 0.35 else \
            "良" if self.p > 0.8 and self.c < 0.5 else \
                "合格" if self.p > 0.7 and self.c < 0.65 else "不合格"

        return {
            "发展系数a": self.a,
            "灰色作用量b": self.b,
            "平均相对误差(%)": np.mean(self.relative_errors),
            "后验差比C": self.c,
            "小误差概率P": self.p,
            "模型精度等级": grade
        }


def grey_forecast_from_excel(input_file, output_file, sheet_name=None,
                             data_column=0, forecast_num=3, date_column=None):
    """
    从Excel读取数据，进行灰色预测，并将结果输出到Excel

    :param input_file: 输入Excel文件路径
    :param output_file: 输出Excel文件路径
    :param sheet_name: 工作表名称，None则自动检测
    :param data_column: 数据所在列索引（整数）或列名（字符串）
    :param forecast_num: 预测步数
    :param date_column: 日期列索引（整数）或列名（字符串）
    :return: 预测结果字典
    """
    try:
        # 检查文件是否存在
        if not os.path.exists(input_file):
            print(f"输入文件不存在: {input_file}")
            print("正在创建示例数据文件...")

            # 创建示例数据
            dates = pd.date_range(start="2023-01-01", periods=10, freq="M")
            data = np.array([100, 120, 135, 150, 170, 190, 210, 235, 260, 290])
            np.random.seed(42)
            data = data + np.random.normal(0, 5, size=len(data))

            df = pd.DataFrame({
                "日期": dates,
                "数值": data
            })

            # 保存示例数据，使用默认工作表名称
            with pd.ExcelWriter(input_file, engine='openpyxl') as writer:
                df.to_excel(writer, sheet_name='数据', index=False)

            print(f"示例数据已保存至 {input_file}，工作表名称为 '数据'")

        # 读取Excel文件信息
        try:
            excel_file = pd.ExcelFile(input_file)
            sheet_names = excel_file.sheet_names

            print(f"文件 '{input_file}' 中包含的工作表: {sheet_names}")

            # 确定要使用的工作表
            if sheet_name is None:
                # 未指定工作表，使用第一个
                sheet_name = sheet_names[0]
                print(f"未指定工作表，将使用第一个工作表: {sheet_name}")
            elif sheet_name not in sheet_names:
                # 指定的工作表不存在，使用第一个
                print(f"指定的工作表 '{sheet_name}' 不存在")
                sheet_name = sheet_names[0]
                print(f"将使用第一个工作表: {sheet_name}")

            # 读取数据
            df = pd.read_excel(input_file, sheet_name=sheet_name)
            print(f"成功读取工作表 '{sheet_name}' 中的数据")
            print(f"工作表中的列: {list(df.columns)}")

        except Exception as e:
            raise ValueError(f"读取工作表时出错: {str(e)}")

        # 处理数据列
        data_col_index = None
        if isinstance(data_column, str):
            # 列名处理
            if data_column in df.columns:
                data_col_index = df.columns.get_loc(data_column)
                column_name = data_column
                print(f"使用列名 '{data_column}'，对应索引 {data_col_index}")
            else:
                raise ValueError(f"数据列 '{data_column}' 不存在于工作表中，可用列名: {list(df.columns)}")
        else:
            # 索引处理
            try:
                data_col_index = int(data_column)
                if data_col_index < 0 or data_col_index >= len(df.columns):
                    raise ValueError
                column_name = df.columns[data_col_index]
                print(f"使用列索引 {data_col_index}，对应列名 '{column_name}'")
            except:
                raise ValueError(f"数据列索引 {data_column} 无效，有效范围: 0 到 {len(df.columns) - 1}")

        # 提取数据
        data = df.iloc[:, data_col_index].dropna().values

        if len(data) < 4:
            raise ValueError(f"数据量不足，灰色预测至少需要4个数据点，当前只有 {len(data)} 个")

        # 处理日期列
        dates = None
        date_col_index = None
        if date_column is not None:
            if isinstance(date_column, str):
                if date_column in df.columns:
                    date_col_index = df.columns.get_loc(date_column)
                    print(f"使用日期列名 '{date_column}'，对应索引 {date_col_index}")
                else:
                    raise ValueError(f"日期列 '{date_column}' 不存在于工作表中，可用列名: {list(df.columns)}")
            else:
                try:
                    date_col_index = int(date_column)
                    if date_col_index < 0 or date_col_index >= len(df.columns):
                        raise ValueError
                    print(f"使用日期列索引 {date_col_index}，对应列名 '{df.columns[date_col_index]}'")
                except:
                    raise ValueError(f"日期列索引 {date_column} 无效，有效范围: 0 到 {len(df.columns) - 1}")

            # 提取日期数据
            dates = df.iloc[:, date_col_index].dropna().values

            # 确保日期长度与数据长度一致
            if len(dates) != len(data):
                raise ValueError(f"日期列长度 ({len(dates)}) 与数据列长度 ({len(data)}) 不一致")

        # 创建并拟合模型
        gp = GreyPrediction(data, column_name, forecast_num)
        gp.fit()
        forecast = gp.predict()
        evaluation = gp.get_evaluation()

        # 生成预测日期（如果有原始日期）
        forecast_dates = None
        if dates is not None:
            try:
                # 尝试推断日期频率
                date_series = pd.Series(dates)
                date_series = pd.to_datetime(date_series)
                delta = date_series.iloc[-1] - date_series.iloc[-2]
                forecast_dates = [date_series.iloc[-1] + (i + 1) * delta for i in range(forecast_num)]
            except:
                forecast_dates = [f"预测{i + 1}" for i in range(forecast_num)]

        # 写入Excel结果
        with pd.ExcelWriter(output_file, engine='openpyxl') as writer:
            # 原始数据与拟合数据
            df_result = pd.DataFrame({
                "日期": dates if dates is not None else [f"数据点{i + 1}" for i in range(len(data))],
                f"原始{column_name}": data,
                f"拟合{column_name}": gp.x0_hat,
                "相对误差(%)": [f"{e:.2f}" for e in gp.relative_errors]
            })
            df_result.to_excel(writer, sheet_name="拟合结果", index=False)

            # 预测数据
            df_forecast = pd.DataFrame({
                "预测日期": forecast_dates if forecast_dates is not None else [f"预测{i + 1}" for i in
                                                                               range(forecast_num)],
                f"预测{column_name}": forecast
            })
            df_forecast.to_excel(writer, sheet_name="预测结果", index=False)

            # 模型评价
            df_evaluation = pd.DataFrame(list(evaluation.items()), columns=["评价指标", "值"])
            df_evaluation.to_excel(writer, sheet_name="模型评价", index=False)

        print(f"\n灰色预测分析完成，结果已保存至: {output_file}")
        print(f"模型精度等级: {evaluation['模型精度等级']}")
        print(f"平均相对误差: {evaluation['平均相对误差(%)']:.2f}%")

        return {
            "原始数据": data,
            "拟合数据": gp.x0_hat,
            "预测数据": forecast,
            "评价指标": evaluation
        }

    except Exception as e:
        print(f"\n发生错误: {str(e)}")
        return None


if __name__ == "__main__":
    # 示例用法
    input_excel = "data1.xlsx"  # 输入Excel文件
    output_excel = "grey_forecast_result.xlsx"  # 输出Excel文件

    # 执行灰色预测
    # 请根据你的Excel文件调整以下参数
    grey_forecast_from_excel(
        input_file=input_excel,
        output_file=output_excel,
        sheet_name='Sheet1',  # 设为None自动检测工作表
        date_column=r'月份',  # 可以是列索引（整数）或列名（字符串）
        forecast_num=5,  # 预测未来5个数据点
        data_column=r'广告费用(万元)x'  # 可以是列索引（整数）或列名（字符串）
    )
