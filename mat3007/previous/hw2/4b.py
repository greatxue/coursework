"""
Scripts for HW#2, 4(b)

@author: Xue Zhongkai, 122090636
"""
import cvxpy as cp
import numpy as np

T = np.array([0.75, 0.35, 0.40, 0.75, 0.65]) # cost vector for each share
q = np.array([10, 5, 10, 10, 5])

# payoff matrix A
A = np.array([
    [1, 0, 1, 1, 0],
    [1, 0, 0, 1, 1],
    [1, 0, 1, 1, 0],
    [0, 1, 0, 1, 1],
    [0, 1, 1, 0, 1]
])

# Decision variables
x = cp.Variable(5, integer=True)

payoffs = A @ x
costs = T @ x  

# The min first picks out the row of the matrix with the least value, and then maxzimize it with 
#  respect to the vector x.
objective = cp.Maximize(cp.min(payoffs - costs))

problem = cp.Problem(objective, [x >= 0, x <= q])
problem.solve()


print(f"Optimal number of shares for each security to buy: {x.value}")
print(f"Optimal worst-case payoff: {problem.value}")
