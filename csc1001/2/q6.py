def eight_queens():

    """
    The classic Eight Queens puzzle is to place eight queens on a 
    chessboard such that no two queens can attack each other (i.e., no two queens are in the 
    same row, same column, or same diagonal). There are many possible solutions. Write a 
    program that displays one such solution.

    Note: you cannot just pre-define a solution and display it. 
    Please use algorithm to display a possible solution.
    """

    ############## Start your codes ##############
   
   
    #First I created something like a chessboard.
    board = [[0]*8 for _ in range(8)]

    #In this step, I transfer virtual judgements into algorithm.
    #(i, j) is regarded as the coordinate, k and l the chess pieces.
    def conflict(i, j):
        #Vertically and horizontally:
        for k in range(0,8):
            if board[i][k]==1 or board[k][j]==1:
                return True
        #Diagonally:
        for k in range(0,8):
            for l in range(0,8):
                if (k+l==i+j) or (k-l==i-j):
                    if board[k][l]==1:
                        return True
        return False

    #Final settlement of queens. This is a bit tricky, as recursions are applied in the loops.
    def numQueens(n):
        if n==0:
            return True
        for i in range(0,8):
            for j in range(0,8):
                if (not(conflict(i,j))) and (board[i][j]!=1):
                    board[i][j] = 1
                    if numQueens(n-1)==True:
                        return True
                    board[i][j] = 0
        return False

    #Operation.
    numQueens(8)
    for i in board:
        print (i)
   
     
    ##############  End your codes  ##############


if __name__ == '__main__':
    eight_queens()

    # This function does not need a return value. 
    # You can just print your solution. For example:
    # |Q| | | | | | | |
    # | | | | |Q| | | |
    # | | | | | | | |Q|
    # | | | | | |Q| | |
    # | | |Q| | | | | |
    # | | | | | | |Q| |
    # | |Q| | | | | | |
    # | | | |Q| | | | |