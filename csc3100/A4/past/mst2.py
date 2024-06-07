import heapq

N, W = map(int, input)
def calculate_min_cost(N, W, costs):
    total_cost = W
    heap = []
    for j in range(1, N):
        if costs[0][j] > 0:
            heapq.heappush(heap, (costs[0][j], j))
    connected = set()
    connected.add(0)
    while heap:
        cost, next_gift = heapq.heappop(heap)
        if next_gift in connected:
            continue
        connected.add(next_gift)
        total_cost += min(cost, W)
        for j in range(N):
            if j not in connected and costs[next_gift][j] > 0:
                heapq.heappush(heap, (costs[next_gift][j], j))
    return total_cost
N, W = map(int, input().split())
costs = [list(map(int, input().split())) for _ in range(N)]
min_cost = calculate_min_cost(N, W, costs)
print(min_cost)
