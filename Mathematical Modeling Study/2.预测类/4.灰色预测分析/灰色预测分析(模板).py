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
        self.x1 = None  # 1 - AGO序列
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
        # 1. 计算1 - AGO序列
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


input_file = r'data.xlsx'
sheet_name = r'sheet1'
data_column = r'人口(万人)'
date_column = r'年份'
excel_file = pd.ExcelFile(input_file)
df = excel_file.parse(sheet_name)

# 提取数据列和日期列
data = df[data_column].dropna().values
dates = df[date_column].dropna().values

# 确保日期长度与数据长度一致
if len(dates) != len(data):
    raise ValueError("日期列长度与数据列长度不一致")

# 创建并拟合模型，预测未来 3 个数据点
forecast_num = 3
gp = GreyPrediction(data, data_column, forecast_num)
gp.fit()
forecast = gp.predict()
evaluation = gp.get_evaluation()

print(f"原始数据: {data}")
print(f"预测数据: {forecast}")
print(f"模型评价: {evaluation}")