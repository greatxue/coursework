"""
Scripts for HW#2, 5

@author: Xue Zhongkai, 122090636
"""
import cvxpy as cp
import numpy as np

vertices = np.array([[0, 1], 
                     [0, 6], 
                     [4, 10], 
                     [8, 10], 
                     [11, 7], 
                     [11, 4], 
                     [7, 0], 
                     [1, 0]])

y = cp.Variable(2)  # center in 2D array
r = cp.Variable()   


constraints = []
constraints.append(r >= 0)

# This loop aims to fetch pairs of vertices of each edge, calculate the vertex vector and the 
#  corresponding normalized inward normal vector, hence figuring out the distance from the center.
for i in range(len(vertices)):
    p1 = vertices[i]
    p2 = vertices[(i + 1) % len(vertices)] # robust for overflow
    
    edge_vec = p2 - p1
    inward_normal = np.array([-edge_vec[1], edge_vec[0]])
    norm = np.linalg.norm(inward_normal)
    inward_normal = inward_normal / norm
    
    b = np.dot(inward_normal, p1)
    constraints.append(inward_normal @ y + r <= b)

objective = cp.Maximize(r)
problem = cp.Problem(objective, constraints)
problem.solve(solver=cp.ECOS)

print(f"The center of the fountain: {y.value}")
print(f"The maximum possible radius is: {r.value}")
