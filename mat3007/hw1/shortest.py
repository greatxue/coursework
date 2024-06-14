import cvxpy as cp
import numpy as np

inf = 1000

W = np.array([
    [  inf,   5,   4, inf, inf, inf, inf, inf], 
    [  5,   inf, inf,   3, inf,   7, inf, inf], 
    [  4, inf,   inf, inf,   1,   2, inf, inf],
    [inf,   3, inf,   inf,   2, inf, inf, inf],
    [inf, inf,   1,   2,   inf, inf,   2,   5],
    [inf,   7,   2, inf, inf,   inf, inf,   3],
    [inf, inf, inf, inf,   2, inf,   inf,   1],
    [inf, inf, inf, inf,   5,   3,   1,   inf]
])

num = 8
x = cp.Variable((num, num), boolean=True)

objective = cp.Minimize(cp.sum(cp.multiply(W, x)))

constraints = []
constraints.append(cp.sum(x[0, :]) == 1)
constraints.append(cp.sum(x[:, num - 1]) == 1)
for i in range(1, num - 1):
    constraints.append(cp.sum(x[i, :]) - cp.sum(x[:, i]) == 0)

problem = cp.Problem(objective, constraints)
problem.solve()

path = []
current = 0
while current != num - 1:
    next_num = np.argmax(x.value[current])
    path.append((current + 1, next_num + 1))
    current = next_num

print("Optimal path:", path)
print("Minimum path length:", problem.value)