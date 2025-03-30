import numpy as np


def gradient_descent(
    func_str, variables, x0, step=0.1, tolerance=1e-6, max_iter=1000
):
    """
    最速下降法
    func_str: 目标函数(字符串形式)
    x0: 初始点
    step: 步长
    tolerance: 收敛条件(梯度模小于该值)
    max_iter: 最大迭代次数
    return: 优化结果
    """

    def func(values):

        local_vars = {var: val for var, val in zip(variables, values)}
        return eval(func_str, {}, local_vars)

    def compute_gradient(values, h=1e-8):
        grad = np.zeros_like(values)
        for i in range(len(values)):
            x_forward = values.copy()
            x_backward = values.copy()
            x_forward[i] += h  
            x_backward[i] -= h  
            grad[i] = (func(x_forward) - func(x_backward)) / (2 * h) 
        return grad

    x = np.array(x0, dtype=float)  # 初始点
    for i in range(max_iter):
        # 计算梯度
        gradient = compute_gradient(x)
        grad_norm = np.linalg.norm(gradient) 

        if grad_norm < tolerance:
            print(f"迭代终止: 梯度范数 {grad_norm:.6f} 小于容许误差 {tolerance}.")
            break

        # 更新变量
        x = x - step * gradient

        if (i + 1) % 100 == 0 or i == 0:  # 每 100 次打印一次
            print(
                f"迭代 {i+1}: x = {x}, f(x) = {func(x):.6f}, 梯度范数 = {grad_norm:.6f}"
            )

    return x, func(x)


# 用户输入目标函数和初始条件
def user_input():
    print("目标函数 f = ")
    func_str = input("目标函数 = ")
    print("变量名 = ")
    variables_str = input("变量名 = ")
    variables = [var.strip() for var in variables_str.split(",")]

    print("\n初始点(用逗号分隔,e.g. '0, 0') = ")
    x0 = list(map(float, input("初始点 = ").split(",")))

    return func_str, variables, x0


# 主程序
if __name__ == "__main__":
    # 用户输入
    func_str, variables, x0 = user_input()

    # 参数设置
    step = float(input("步长 (e.g. 0.1) = "))
    tolerance = float(input("容许误差 (e.g. 1e-6) = "))
    max_iter = int(input("最大迭代次数 (e.g. 1000) = "))

    # 调用最速下降法
    result_x, result_f = gradient_descent(
        func_str, variables, x0, step, tolerance, max_iter
    )

    # 输出最终结果
    print("\n优化结果:")
    print(f"最优点: x = {result_x}")
    print(f"最优值: f(x) = {result_f:.6f}")
