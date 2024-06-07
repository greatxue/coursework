class DFS():
    def __init__(self, v):
        self.graph = [[] for _ in range(v + 1)]
        self.visited = [False] * (v + 1)
        self.dfs = []
        self.v = v
    
    def dfs(self, node):
        self.visited[node] = True
        self.dfs_order.append(node)
        for nb in self.graph[node]:
            if not self.visited[nb]:
                self.dfs(nb)
    
    def compare(self, order):
        for i in range(2, self.v + 1):
            self.graph[parents[i - 2]].append(i)
        self.dfs(1)
        return self.dfs == order


num = int(input().strip())
for _ in range(num):
    v = int(input().strip())
    parents = list(map(int, input().strip().split()))
    order = list(map(int, input().strip().split()))
    
    dfs_ = DFS(v)

    if dfs_.compare(order):
        print("YES")
    else:
        print("NO")
