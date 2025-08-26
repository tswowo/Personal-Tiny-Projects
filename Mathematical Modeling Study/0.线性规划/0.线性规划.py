from scipy.optimize import linprog
# res = linprog(c, A_ub=None, b_ub=None, A_eq=None, b_eq=None,
#               bounds=None, method='highs', options=None)

c=[-20,-15,-25,
   5,4,2,3,6,7]#目标函数 linprog默认求最小值，当需要求最大值时取负
A_ub=[
    [2,1,3,0,0,0,0,0,0],
    [3,4,2,0,0,0,0,0,0],
    [1,1,1,0,0,0,0,0,0],
    [0,0,0,1,1,1,0,0,0],
    [0,0,0,0,0,0,1,1,1]
]#不等式约束左侧
b_ub=[80,100,90,40,50]#不等式约束右侧

A_eq=[
    [1,0,0,-1,0,0,-1,0,0],
    [0,1,0,0,-1,0,0,-1,0],
    [0,0,1,0,0,-1,0,0,-1]
]
b_eq=[0,0,0]

bounds=[(0,None)]*9#变量范围
res= linprog(c=c,A_ub=A_ub,b_ub=b_ub,A_eq=A_eq,b_eq=b_eq,bounds=bounds)#核心函数

if res.success:
    print("最优解找到！")
    print(f"生产计划：A = {res.x[0]:.2f}, B = {res.x[1]:.2f}, C = {res.x[2]:.2f}")
    print(f"运输计划：")
    print(f"  仓库X：A = {res.x[3]:.2f}, B = {res.x[4]:.2f}, C = {res.x[5]:.2f}")
    print(f"  仓库Y：A = {res.x[6]:.2f}, B = {res.x[7]:.2f}, C = {res.x[8]:.2f}")
    print(f"最大总利润：{-res.fun:.2f} 元")
else:
    print("求解失败:", res.message)