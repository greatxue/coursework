def sort_pts(n, k, id, A):
    """Sorts the coorsinate in 4 different rules. """
    pts = [(a // k, a % k) for a in A]

    if id == 1: 
        pts.sort(key=lambda x: (x[0], x[1]))
    elif id == 2: 
        pts.sort(key=lambda x: (-x[0], x[1]))
    elif id == 3:
        pts.sort(key=lambda x: (x[0], -x[1]))
    elif id == 4:
        pts.sort(key=lambda x: (-x[0], -x[1]))

    return pts

# Statement: I/O module below refers to some reference, declared in the report.

T = int(input())                            
for _ in range(T):
    n, k, id = map(int, input().split())   # For Python lists, n is of no use.
    A = list(map(int, input().split()))     
    sorted_pts = sort_pts(n, k, id, A)
    for pt in sorted_pts:
        print(pt[0], pt[1])
    print()  # Print a newline after each case.