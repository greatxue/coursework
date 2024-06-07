"""
Scripts for HW#1, 5

@author: Xue Zhongkai, 122090636
"""
import cvxpy as cp

num_vertices = 10

x = cp.Variable(num_vertices)

# Edges in the graph (as pairs of vertex indices)
# The number corresponds to the index of alphabets in the graph.
edges = [(0, 1), (0, 4), (0, 5),
         (1, 2), (1, 6),
         (2, 3), (2, 7),
         (3, 4), (3, 8),
         (4, 9),
         (5, 7), (5, 8),
         (6, 8), (6, 9),
         (7, 9)]

# Objective: Minimize the sum of the vertices
objective = cp.Minimize(cp.sum(x))

# Constraints
constraints = [x[u] + x[v] >= 1 for u, v in edges]
constraints += [0 <= x, x <= 1]

problem = cp.Problem(objective, constraints)
problem.solve()

print(x.value, problem.value)
