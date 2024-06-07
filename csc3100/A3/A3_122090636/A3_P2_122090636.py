from math import pi, pow

def compute_d2(r1, r2, d1):
    d2 = r2 - pow(r2**3 - (r1**3 - (r1 - d1)**3), 1/3)
    return d2


n = int(input())
for _ in range(n):
    r1, r2, d1 = map(int, input().split())
    print(compute_d2(r1, r2, d1))

