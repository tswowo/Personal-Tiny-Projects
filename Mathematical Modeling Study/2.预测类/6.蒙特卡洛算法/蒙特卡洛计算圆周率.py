import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['Microsoft YaHei', 'SimHei', 'Arial Unicode MS']  # 适配不同系统的中文字体
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示异常的问题

def monte_carlo_pi(sample_size=100000, visualize=False):
    """
    使用蒙特卡洛算法计算圆周率

    参数:
        sample_size: 随机点的数量
        visualize: 是否可视化结果

    返回:
        pi_approx: 计算得到的π近似值
    """
    # 生成正方形内的随机点，坐标范围[-1, 1)
    x = np.random.uniform(-1, 1, sample_size)  # x坐标
    y = np.random.uniform(-1, 1, sample_size)  # y坐标

    # 判断点是否在圆内 (x² + y² ≤ 1)
    inside_circle = (x ** 2 + y ** 2) <= 1
    count_inside = np.sum(inside_circle)  # 圆内点的数量

    # 计算π的近似值: π ≈ 4 * (圆内点数 / 总点数)
    pi_approx = 4 * (count_inside / sample_size)

    # 可视化结果
    if visualize:
        plt.figure(figsize=(8, 8))
        # 绘制正方形
        plt.plot([-1, 1, 1, -1, -1], [-1, -1, 1, 1, -1], 'b-', linewidth=2)
        # 绘制圆
        circle = plt.Circle((0, 0), 1, fill=False, color='r', linewidth=2)
        plt.gca().add_patch(circle)
        # 绘制点
        plt.scatter(x[inside_circle], y[inside_circle], c='g', s=1, alpha=0.6, label='圆内点')
        plt.scatter(x[~inside_circle], y[~inside_circle], c='y', s=1, alpha=0.6, label='圆外点')
        plt.axis('equal')
        plt.title(f'蒙特卡洛计算π: 样本数={sample_size}, π≈{pi_approx:.6f}')
        plt.legend()
        plt.grid(True, alpha=0.3)
        plt.show()

    return pi_approx


# 测试不同样本量的结果
if __name__ == "__main__":
    # 小样本测试并可视化
    pi_small = monte_carlo_pi(1000, visualize=True)

    # 大样本测试（更精确）
    sample_sizes = [1000, 10000, 100000, 1000000]
    for size in sample_sizes:
        pi = monte_carlo_pi(size)
        error = abs(pi - np.pi)
        print(f"样本数: {size:7d} | π近似值: {pi:.6f} | 与真实值误差: {error:.6f}")
