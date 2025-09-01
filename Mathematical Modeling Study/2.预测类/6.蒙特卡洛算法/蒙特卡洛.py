import numpy as np
import matplotlib.pyplot as plt


def mengtekaluo(simple_size=100):
    arrX=np.random.uniform(-1,1,simple_size)
    arrY=np.random.uniform(-1,1,simple_size)
    arrIn=(arrX**2+arrY**2)<=1
    ans=4*sum(arrIn)/simple_size

    plt.plot([-1, 1, 1, -1, -1], [-1, -1, 1, 1, -1], 'b-', linewidth=2)
    circle = plt.Circle((0, 0), 1, fill=False, color='r', linewidth=2)
    plt.gca().add_patch(circle)
    plt.scatter(arrX[arrIn], arrY[arrIn], c='g', s=1, alpha=0.6, label='圆内点')
    plt.scatter(arrX[~arrIn], arrY[~arrIn], c='y', s=1, alpha=0.6, label='圆外点')
    plt.show()

    return ans

for i in range(0,6):
    print(f'{10**i}个点蒙特卡洛结果为{mengtekaluo(10**i)}')