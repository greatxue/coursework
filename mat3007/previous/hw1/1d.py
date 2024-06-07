"""
Scripts for HW#1, 1(d)

@author: Xue Zhongkai, 122090636
"""
import cvxpy as cp

n1 = cp.Variable(nonneg=True)  
n2 = cp.Variable(nonneg=True)  

# Objective： Maximize the profit
profit = 7.8 * n1 + 7.1 * n2
objective = cp.Maximize(profit)

# Constraints
constraints = [
    (1/4)*n1 + (1/3)*n2 <= 90,  
    (1/8)*n1 + (1/3)*n2 <= 80, 
]

problem = cp.Problem(objective, constraints)
problem.solve(solver=cp.ECOS)

print("Optimal number of first product:", n1.value)
print("Optimal number of second product:", n2.value)
print("Maximum Profit:", problem.value)
