import pandas as pd
import numpy as np


def general_gray_correlation_analysis(
        input_path: str,  # 输入Excel文件路径
        output_path: str,  # 输出Excel文件路径
        scheme_col: str = "方案名称",  # Excel中“方案列”的表头（如“公司名称”“产品型号”）
        indicator_type: dict = None,  # 指标类型：key=指标名，value="正向"（越大越好）/"负向"（越小越好）
        rho: float = 0.5  # 分辨系数（默认0.5，取值范围0-1）
) -> tuple[pd.DataFrame, pd.DataFrame, pd.DataFrame]:
    """
    通用灰色关联分析函数：
    1. 从Excel读取方案-指标数据
    2. 自动处理正向/负向指标（生成理想参考序列）
    3. 计算方案关联度并排名
    4. 分析各指标对整体评估的影响（平均关联系数、权重占比）
    5. 结果保存到Excel的3个工作表

    参数说明：
    - scheme_col: Excel中“方案名称”列的表头（如分析产品则填“产品名称”）
    - indicator_type: 指标类型字典（如{"成本":"负向","效率":"正向"}），未指定的指标默认“正向”
    - rho: 分辨系数，用于调整关联系数的灵敏度（默认0.5，常用值0.1-0.9）
    """
    # -------------------------- 1. 读取并验证Excel数据 --------------------------
    try:
        # 读取Excel，保留所有列（方案列 + 指标列）
        df = pd.read_excel(input_path)
    except FileNotFoundError:
        raise FileNotFoundError(f"输入文件不存在：{input_path}")

    # 验证“方案列”是否存在
    if scheme_col not in df.columns:
        raise ValueError(f"Excel中未找到'{scheme_col}'列，请检查表头是否正确")

    # 提取方案名称和指标数据（排除方案列，剩余均为指标列）
    scheme_names = df[scheme_col].values  # 所有方案名称（如A公司、B公司）
    indicator_cols = [col for col in df.columns if col != scheme_col]  # 所有指标列（如业绩、成本）

    # 处理空值（若有缺失值，用该指标的均值填充，避免计算错误）
    df_clean = df[indicator_cols].fillna(df[indicator_cols].mean())
    data = df_clean.values  # 指标数据矩阵（行=方案，列=指标）

    # -------------------------- 2. 生成理想参考序列（核心：适配正/负向指标） --------------------------
    # 默认所有指标为“正向”（越大越好），若指定indicator_type则覆盖
    if indicator_type is None:
        indicator_type = {ind: "正向" for ind in indicator_cols}

    # 生成参考序列：正向指标取最大值，负向指标取最小值（理想方案的指标值）
    reference_series = []
    for i, ind in enumerate(indicator_cols):
        if indicator_type.get(ind, "正向") == "正向":
            # 正向指标：理想值=该指标最大值（越大越好）
            ref_val = np.max(data[:, i])
        else:
            # 负向指标：理想值=该指标最小值（越小越好，如成本、误差）
            ref_val = np.min(data[:, i])
        reference_series.append(ref_val)
    reference_series = np.array(reference_series)  # 最终理想参考序列（行向量）

    # -------------------------- 3. 数据标准化（消除量纲影响，通用初值化法） --------------------------
    # 标准化公式：x'_ij = x_ij / x_ref_j（x_ref_j为第j个指标的理想值）
    # 避免除以0（若理想值为0，用该指标的均值替代）
    reference_series_safe = np.where(reference_series == 0, df_clean.mean().values, reference_series)
    standardized_data = data / reference_series_safe  # 标准化后的指标数据
    standardized_ref = reference_series / reference_series_safe  # 标准化后的参考序列（恒为1）

    # -------------------------- 4. 计算关联系数与关联度 --------------------------
    # 步骤1：计算每个方案与参考序列的绝对差
    abs_diff = np.abs(standardized_data - standardized_ref)  # 形状：(方案数, 指标数)

    # 步骤2：找全局最大/最小绝对差（所有方案-指标的差的极值）
    max_diff = np.max(abs_diff)
    min_diff = np.min(abs_diff)

    # 步骤3：计算关联系数（灰色关联分析核心公式）
    correlation_coeff = (min_diff + rho * max_diff) / (abs_diff + rho * max_diff)  # 形状：(方案数, 指标数)

    # 步骤4：计算每个方案的关联度（关联系数的平均值，反映方案与理想方案的相似度）
    correlation_degree = np.mean(correlation_coeff, axis=1)  # 形状：(方案数,)

    # -------------------------- 5. 方案关联度排名 --------------------------
    scheme_rank = pd.DataFrame({
        "排名": range(1, len(scheme_names) + 1),
        scheme_col: scheme_names,
        "灰色关联度": correlation_degree.round(4)  # 保留4位小数，便于阅读
    }).sort_values(by="灰色关联度", ascending=False).reset_index(drop=True)
    scheme_rank["排名"] = range(1, len(scheme_rank) + 1)  # 重新排序排名

    # -------------------------- 6. 指标影响分析（量化指标重要性） --------------------------
    # 核心逻辑：平均关联系数越高，指标对整体评估的影响越大
    indicator_analysis = pd.DataFrame({
        "指标名称": indicator_cols,
        "指标类型": [indicator_type.get(ind, "正向") for ind in indicator_cols],
        "理想参考值": reference_series.round(4),  # 该指标的理想值
        "平均关联系数": np.mean(correlation_coeff, axis=0).round(4),  # 所有方案在该指标的关联系数均值
        "指标权重占比": (np.mean(correlation_coeff, axis=0) / np.sum(np.mean(correlation_coeff, axis=0))).round(4) * 100
        # 占比（%）
    }).sort_values(by="平均关联系数", ascending=False).reset_index(drop=True)
    # 增加影响优先级（1=影响最大）
    indicator_analysis["影响优先级"] = range(1, len(indicator_analysis) + 1)

    # -------------------------- 7. 中间结果：各方案的指标关联系数（可选查看） --------------------------
    coeff_detail = pd.DataFrame(
        correlation_coeff.round(4),
        columns=[f"{ind}关联系数" for ind in indicator_cols],
        index=scheme_names
    ).reset_index().rename(columns={"index": scheme_col})

    # -------------------------- 8. 保存结果到Excel（分3个工作表） --------------------------
    with pd.ExcelWriter(output_path, engine="openpyxl") as writer:
        scheme_rank.to_excel(writer, sheet_name="方案关联度排名", index=False)
        indicator_analysis.to_excel(writer, sheet_name="指标影响分析", index=False)
        coeff_detail.to_excel(writer, sheet_name="各方案指标关联系数", index=False)

    print(f"分析完成！结果已保存到：{output_path}")
    return scheme_rank, indicator_analysis, coeff_detail


# -------------------------- 示例：如何使用（根据你的数据修改以下参数即可） --------------------------
if __name__ == "__main__":
    # 1. 配置参数（仅需修改这部分，核心代码无需动）
    INPUT_EXCEL = "input_data.xlsx"  # 你的输入Excel路径
    OUTPUT_EXCEL = "灰色关联分析结果.xlsx"  # 输出结果路径
    SCHEME_COLUMN = "公司名称"  # 你的方案列表头（如“产品型号”“项目编号”）
    # 指标类型（key=指标名，value="正向"/"负向"，未列的指标默认正向）
    INDICATOR_TYPE = {
        "公司业绩": "正向",  # 越大越好
        "市场占有率": "正向",  # 越大越好
        "技术创新能力": "正向",  # 越大越好
        "客户满意度": "正向",  # 越大越好
        "运营成本": "负向"  # 越小越好（示例：若有负向指标可添加）
    }

    # 2. 执行通用灰色关联分析
    rank_result, indicator_result, coeff_detail = general_gray_correlation_analysis(
        input_path=INPUT_EXCEL,
        output_path=OUTPUT_EXCEL,
        scheme_col=SCHEME_COLUMN,
        indicator_type=INDICATOR_TYPE,
        rho=0.5
    )

    # 3. 打印关键结果（可选，便于快速查看）
    print("\n=== 方案关联度排名 ===")
    print(rank_result[["排名", SCHEME_COLUMN, "灰色关联度"]])
    print("\n=== 指标影响分析（按影响优先级排序） ===")
    print(indicator_result[["影响优先级", "指标名称", "指标类型", "平均关联系数", "指标权重占比"]])