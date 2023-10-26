
def isValid(number):
    ''' Return True if the card number is valid.
    param number: The card number.
    return: True of False
    '''
    ########### Start your code ############
    
    sum = sumOfOddPlace(number) + sumOfDoubleEvenPlace(number)
    if sum % 10 == 0:
        return True
    else:
        return False

    ############ End your code #############

def sumOfDoubleEvenPlace(number):
    ''' Get the result from step 2.
    param number: The card number.
    return: Sum of double even place.
    '''
    ########### Start your code ############
    
    sum = 0
    for n in range(0,16):
         if n%2 == 1:
            sum += getDigit( (number//(10**n)) %10 )
         else:
            pass
    return sum
    
    ############ End your code #############

def getDigit(number):
    ''' Get digit of the number. For instance: getDigit(5) = 5, getDigit(15) = 6.
    param number: A number who only has one or two digits.
    return: Return this number if it is a single digit, otherwise return the sum of the two digits.
    '''
    ########### Start your code ############
    
    number = number*2
    if number//10 >= 1:
        number = (number//10) + (number%10)
    else:
        pass
    return number

    ############ End your code #############

def sumOfOddPlace(number):
    ''' Return the sum of odd place digits in number.
    param number: The card number.
    return: The sum of odd place digits.
    '''
    ########### Start your code ############
    
    sum=0
    for n in range(0,16):
        if n%2 ==0:
            sum += (number//(10**n)) %10  
    return sum

    ############ End your code #############


if __name__ == '__main__':
    # Example test cases
    # Note: there will be more test cases in scoring
    ans1 = isValid(4388576018402626)
    ans2 = isValid(4388576018410707)
    ######## We will judge the correctness by examing the result of isValid() function. #########