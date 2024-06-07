import sys
sys.setrecursionlimit(2000000)
MOD = 10**9 + 7

class Node():
    def __init__(self):
        self.adj = []

class blackWhiteTree():
    def __init__(self, node_num):
        self.tree = [Node() for i in range(node_num)]
        self.color = [0] * node_num
        self.count = [0] * node_num
        self.dis = [0] * node_num
        self.ans = [0] * node_num
        self.total = 0  
    
    def save_color(self, color):
        self.color = color
        self.total = sum(self.color) 

    def save_node(self, u, v, w):
        self.tree[u].adj.append((v, w))
        self.tree[v].adj.append((u, w))
    
    def dfs_helper(self, node, pt):
        self.count[node] = self.color[node]
        for adj, weight in self.tree[node].adj:
            if adj != pt:
                self.dfs_helper(adj, node)
                self.count[node] += self.count[adj]
                self.dis[node] += self.dis[adj] + self.count[adj] * weight
    
    def dfs(self, node, pt):
        self.ans[node] = self.dis[node]
        for adj, weight in self.tree[node].adj:
            if adj != pt:
                prev_dis_adj = self.dis[adj]
                self.dis[adj] += self.dis[node] - (prev_dis_adj + self.count[adj] * weight) + \
                    (self.total - self.count[adj]) * weight
                self.dfs(adj, node)

    
    
n = int(input())
tree = blackWhiteTree(n)

color = list(map(int, input().split()))
tree.save_color(color)

for _ in range(n - 1):
    u, v, w = map(int, input().split())
    tree.save_node(u - 1, v - 1, w)

tree.dfs_helper(0, -1)
tree.dfs(0, -1)

for i in tree.ans:
    print(i % MOD)
