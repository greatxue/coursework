import cvxpy as cp

x1 = cp.Variable()
x2 = cp.Variable()
x3 = cp.Variable()
x4 = cp.Variable()

constraints = [
4 * x1 + 6 * x2 + 20 * x3 + x4 >= 25,
8 * x1 + 12 * x2 + 30 * x4 >= 40, 
130 * x1 + 120 * x2 + 150 * x3 + 70 * x4 >= 400, 
x1 >= 0, x2 >= 0, x3 >= 0, x4 >= 0
]

objective = cp. Minimize(2 * x1 + 3.5 * x2 + 8 * x3 + 1.5 * x4)

problem = cp. Problem(objective, constraints)
result = problem.solve()

print("min:", result)
print("x1:", x1. value)
print("x2:", x2. value)
print("x3:", x3.value)
print("x4:", x4.value) 