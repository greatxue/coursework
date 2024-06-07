"""
Scripts for HW#1, 4

@author: Xue Zhongkai, 122090636
"""
import cvxpy as cp
import numpy as np

# Cost matrix from Table 1
cost_matrix = np.array([
    [0, 10, 12, 17, 34],
    [10, 0, 18, 8, 46],
    [12, 18, 0, 9, 27],
    [17, 8, 9, 0, 20],
    [34, 46, 27, 20, 0]
])

# Current and needed cars from Table 2
current_cars = np.array([115, 385, 410, 480, 610])
needed_cars = np.array([200, 500, 800, 200, 300])

# Variables: number of cars to move from i to j
x = cp.Variable((5, 5), integer=True)

# Objective: Minimize total cost
objective = cp.Minimize(cp.sum(cp.multiply(cost_matrix, x)))

# Constraints
constraints = [
    cp.sum(x, axis=1) <= current_cars, # sum up w.r.t columns
    cp.sum(x, axis=0) - cp.sum(x, axis=1) >= needed_cars - current_cars, 
    x >= 0                                
]

problem = cp.Problem(objective, constraints)
problem.solve()

optimal_moves = x.value
optimal_cost = problem.value
print(optimal_moves, optimal_cost, sep = "\n")