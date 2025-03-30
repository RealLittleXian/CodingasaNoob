import numpy as np


def penalty_function(x, r, constraints, objective_function):
    """
    x: 参数向量
    r: 当前罚因子
    constraints: 约束条件列表
    objective_function: 目标函数
    return: 目标函数值 + 罚函数值
    """

    f_x = eval(objective_function)

    # 罚函数
    penalty = 0
    for constraint in constraints:
        g_x = eval(constraint)
        if g_x > 0:  # 对于不等式约束，违反时计算罚值
            penalty += g_x**2

    return f_x + r * penalty


def penalty_method(
    initial_x, r_init, r_mult, tol, max_iter, constraints, objective_function
):
    """
    initial_x: 初始点
    r_init: 初始罚因子
    r_mult: 罚因子增大倍数
    tol: 收敛阈值
    max_iter: 最大迭代次数
    constraints: 约束条件列表
    objective_function: 目标函数
    return: 优化后的 x
    """
    x = np.array(initial_x, dtype=float)
    r = r_init

    for _ in range(max_iter):
        grad_tol = 1e-6
        step_size = 0.01
        for _ in range(1000):
            grad = np.zeros_like(x)
            for i in range(len(x)):
                x_eps = np.copy(x)
                x_eps[i] += 1e-6
                grad[i] = (
                    penalty_function(x_eps, r, constraints, objective_function)
                    - penalty_function(x, r, constraints, objective_function)
                ) / 1e-6
            x_new = x - step_size * grad
            if np.linalg.norm(grad) < grad_tol:
                break
            x = x_new

        # 检查约束是否满足
        max_violation = max([max(0, eval(constraint)) for constraint in constraints])
        if max_violation < tol:
            break

        # 增大罚因子
        r *= r_mult

    return x


if __name__ == "__main__":
    # 手动输入目标函数
    print("f(x) = ")
    # print("e.g. (x[0] - 2)**2 + (x[1] - 3)**2")
    objective_function = input("目标函数 f(x) = ")

    # 手动输入约束条件
    print("约束条件（多个约束用逗号分隔）")
    # print("e.g. 'x[0] + x[1] - 5', '-x[0]', '-x[1]'")
    constraints_input = input("约束条件列表 = ")
    constraints = [constraint.strip() for constraint in constraints_input.split(",")]

    # 初始化参数
    initial_x = list(map(float, input("初始点 (e.g. 0 0) = ").split()))
    r_init = float(input("初始罚因子 r_init (e.g. 1) = "))
    r_mult = float(input("罚因子增长倍数 r_mult (e.g. 10) = "))
    tol = float(input("收敛阈值 tol (e.g. 1e-6) = "))
    max_iter = int(input("最大迭代次数 max_iter (e.g. 100) = "))

    # 调用罚函数算法
    result = penalty_method(
        initial_x, r_init, r_mult, tol, max_iter, constraints, objective_function
    )

    # 输出结果
    print("\n优化结果:")
    print("x =", result)
    print("目标函数值: f(x) =", eval(objective_function))
    print("约束验证结果:")
    for i, constraint in enumerate(constraints):
        print(f"约束 {i+1}: {constraint} =", eval(constraint))
