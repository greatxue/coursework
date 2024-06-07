
def sqrt(n):
    ''' Babylonian Method of Computing the Square Root 
    param n: You need to get the squre root of n.
    return: The square root of n.
    '''
    ########### Start your code ############
    ### hint: the stop condition should be abs(nextGuess - lastGuess) < 0.0001
    
    lastGuess=1
    nextGuess=0
    while True:
        nextGuess=(lastGuess+(n/lastGuess))/2
        if nextGuess<=lastGuess:
            if lastGuess-nextGuess<0.0001:
                return ("%.4f" % nextGuess)
                break
            else:
                lastGuess=nextGuess
        else:
            if nextGuess-lastGuess<0.0001:
                return ("%.4f" % nextGuess)
                break
            else:
                lastGuess=nextGuess    

    ############ End your code #############



if __name__ == '__main__':
    # Example test cases
    # Note: there will be more test cases in scoring
    ans1 = sqrt(5)
    ans2 = sqrt(37)
    ######## We will judge the correctness by examing the result of sqrt() function. #########