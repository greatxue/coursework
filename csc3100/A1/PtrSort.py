def sort_pts(n, k, id, A):
    '''Calculates the coordinate of the points.'''
    pts = [(a // k, a % k) for a in A]

    if id == 1: 
        # Method 1: x sorted S->L, x equal then y S->L
        pts.sort(key=lambda x: (x[0], x[1]))
    elif id == 2: 
        # Method 2: x sorted L->S, x equal then y S->L
        pts.sort(key=lambda x: (-x[0], x[1]))
    elif id == 3:
        # Method 3: x sorted S->L, x equal then y L->S
        pts.sort(key=lambda x: (x[0], -x[1]))
    elif id == 4:
        # Method 4: x sorted L->S, x equal then y L->S
        pts.sort(key=lambda x: (-x[0], -x[1]))

    return pts

# Statement: The i/o module below refers to the quora page 
# https://www.quora.com/What-does-the-following-line-means-S-list-map-int-input-split-for-in-range-3

T = int(input())                            
for _ in range(T):
    n, k, id = map(int, input().split())   # For Python lists, n is of no use.
    A = list(map(int, input().split()))     
    sorted_pts = sort_pts(n, k, id, A)
    for pt in sorted_pts:
        print(pt[0], pt[1])
    print()  # Print a newline after each case.
