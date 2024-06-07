def winner():
    row = int(input())
    matrix = []

    for _ in range(row):
        row_data = list(map(int, input().split()))
        matrix.extend(row_data)

    candidate = 0
    num_candi = 0
    
    for i in range(1, row):
        if matrix[candidate * row + i] == 1:
            candidate = i
            num_candi += 1
    
    if num_candi > 1:
        return -1
    
    for j in range(row):
        if matrix[candidate * row + j] == 1:
            return -1

    return candidate


print(winner())
