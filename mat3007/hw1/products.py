import cvxpy as cp

x1 = cp.Variable()
x2 = cp.Variable()

objective = cp.Maximize(6.8 * x1 + 5.1 * x2)

constraints = [
    (1/8) * x1 + (1/2) * x2 <= 80,  
    (1/4) * x1 + (1/6) * x2 <= 60,  
    x1 >= 0,                       
    x2 >= 0                        
]

problem = cp.Problem(objective, constraints)

result = problem.solve()

print(f"Optimal value: {result:.2f}")
print(f"Number of first type products: {x1.value:.2f}")
print(f"Number of second type products: {x2.value:.2f}")