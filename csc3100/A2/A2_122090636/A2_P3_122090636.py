def encrpt_the_scroll():
    raw_data = list(map(str, input().split()))
    digit_list = [int(digit) for digit in raw_data[0]]
    takeout_num = int(raw_data[1])
    result = []

    if len(digit_list) == takeout_num:
        return 0
    
    for digit in digit_list:
        while len(result) != 0 and digit < result[-1]:
            if takeout_num == 0:
                break
            result.pop(-1)
            takeout_num -= 1
        result.append(digit)

    if takeout_num != 0:
        for _ in range(takeout_num):
            result.pop(-1)
    
    start_flag = False
    result_str = ''
    for char in result:
        if char == 0 and start_flag == False:
            continue
        if char != 0:
            start_flag = True
        result_str += str(char)

    if result_str == '':
        return 0
    
    return result_str 

print(encrpt_the_scroll())