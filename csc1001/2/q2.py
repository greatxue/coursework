import time
start = time.time()
def emirps_100():
    '''
    Displays the first 100 emirps. Display 10 numbers per line and align the numbers properly.
    This function does not need a return value. 
    '''
    ########### Start your code ############
    ### hint: When aligh the numbers, monospaced font will be helpful.

    def reverseNumber(i):
        i_list= list(str(i))
        a = list(i_list)
        a.reverse()
        j = ''.join(str(m) for m in a)
        j = int(j)
        return j

    def primeCheck(number):
        isPrime = True
        for k in range(2,number): 
            if number % k == 0:
                isPrime = False 
                break 
        if number == 2:
            isPrime = True
        return isPrime

    num = 0
    for i in range(10,10000):
        flag = (primeCheck(i)) and (primeCheck(reverseNumber(i))) and (i != reverseNumber(i))
        if flag:
            num += 1
            if num <=100:
                if num % 10 == 0: 
                    print("%-6d" % i)
                else:
                    print('%-6d' % i, end = '')
        
    ############ End your code #############

if __name__ == '__main__':
    emirps_100()

    # You can just print your solution. Like this:
    #    13   17   31   37   71   73   79   97  107  113
    #   149  157  167  179  199  311  337  347  359  389
    # ...

end = time.time()
print(end-start)