import heapq
class heap:
    def __init__(self):
        self.heap = []
    def push(self, item):
        heapq.heappush(self.heap, item)
    def pop(self):
        return heapq.heappop(self.heap)
    def isEmpty(self):
        return not self.heap

class prim:
    def __init__(self, costs):
        self.gifts = heap()
        self.connected = {0}
        self.total = W
        self.costs = costs
    def randomAdd(self):
        for node in range(1, N):
            cost_0_out = self.costs[0][node]
            if cost_0_out > 0:
                self.gifts.push((cost_0_out, node))
    def addMin(self):
        while not self.gifts.isEmpty():
            cost, next = self.gifts.pop()
            if next in self.connected:
                continue
            self.connected.add(next)
            self.total += min(cost, W)
            
            for node in range(N):
                if node in self.connected:
                    continue
                cost_next_out = self.costs[next][node]
                if cost_next_out > 0:
                    self.gifts.push((cost_next_out, node))
        return self.total


N, W = map(int, input().split())
costs = []
for _ in range(N):
    costs.append(list(map(int, input().split())))
prim_ = prim(costs)
prim_.randomAdd()
print(prim_.addMin())
