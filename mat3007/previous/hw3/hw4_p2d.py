import cvxpy as cp

y1 = cp.Variable()
y2 = cp.Variable()
y3 = cp.Variable()

constraints = [
4 * y1 + 8 * y2 + 130 * y3 <= 2, 
6 * y1 + 12 * y2 + 120 * y3 <= 3.5,
20 * y1 + 150 * y3 <= 8, 
y1 + 30 * y2 + 70 * y3 <= 1.5, 
y1 >= 0, y2 >= 0, y3 >= 0
]

objective = cp.Maximize (25*y1 + 40*y2 + 400*y3)
problem = cp.Problem(objective, constraints)
result = problem. solve()

print("max:", result)
print("y1:", y1. value)
print("y2:", y2. value)
print("y3:", y3. value)