n, m, p = map(int, input().split()) # grid size (m * n), p squads

# Initialize the m * n empty grid.
grid = []
for _ in range(n):
    row = [0] * m
    grid.append(row)

for _ in range(p):
    i, j, k = map(int, input().split()) # grid (i, j), number k
    grid[i-1][j-1] += k  # i, j starts from 1 mathematically


extended_grid = []
for _ in range(n + 1):
    row = [0] * (m + 1)
    extended_grid.append(row)

total_sum = 0

for i in range(1, n+1):
    for j in range(1, m+1):
        extended_grid[i][j] = (extended_grid[i-1][j] + extended_grid[i][j-1] \
                             - extended_grid[i-1][j-1] + grid[i-1][j-1]) % 998244353
for a in range(1, n+1):
    for b in range(1, m+1):
        for c in range(a, n+1):
            temp1 = extended_grid[a-1][b-1] % 998244353
            for d in range(b, m+1):
                temp2 = extended_grid[c][b-1] % 998244353
                rect_sum = (extended_grid[c][d] - extended_grid[a-1][d] - temp2 + temp1) % 998244353
                total_sum = (total_sum + rect_sum) % 998244353


print(total_sum)
