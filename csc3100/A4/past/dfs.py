def dfs(graph, node, visited, dfs_order):
    visited[node] = True
    dfs_order.append(node)
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(graph, neighbor, visited, dfs_order)

def compare(v, parents, order):
    graph = [[] for _ in range(v + 1)]
    for i in range(2, v + 1):
        graph[parents[i - 2]].append(i)

    visited = [False] * (v + 1)
    dfs_order = []
    dfs(graph, 1, visited, dfs_order)

    return dfs_order == order


num = int(input().strip())
for _ in range(num):
    v = int(input().strip())
    parents = list(map(int, input().strip().split()))
    order = list(map(int, input().strip().split()))

    if compare(v, parents, order):
        print("YES")
    else:
        print("NO")
