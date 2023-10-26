# This is a puzzle game.
print("Welcome to my puzzle game!")
print("Intro: N-puzzle Game is a sliding puzzle game having 8 (or 15) square tiles placed on a board, with digits 1 - n \n\
       numbered in a frame that is 3 (or 4) tiles high and 3 (or 4) tiles wide, leaving one unoccupied tile position. \n\
       Tiles in the same row or column of the open position can be moved by sliding them horizontally or vertically. \n\
       The goal of the puzzle is to place the tiles in numerical order.")
while True:
    con = input('Enter "c" to continue, "q" to quit: ')
    if con == "q": break
    if con == "c": pass
    else: print("Invalid input. Please try again.")

## Step 1: User Input
    raw_num = 0
    while True:
        raw_num = input('Enter "1" for 8-puzzle, "2" for 15-puzzle: ')
        if raw_num == "1": 
            num = 3
            break
        if raw_num == "2":  
            num = 4 
            break
        else: print("Invalid input. Please try again.")
### num indicates the length of side.
        
    while True:
        try:
            raw_direct = input("Enter the four letters used for left, right, up and down move: ")

            left = raw_direct[0]
            right = raw_direct[2]
            up = raw_direct[4]
            down = raw_direct[6]
            
            direct_list = []
            direct_list.append(left)
            direct_list.append(right)
            direct_list.append(up)
            direct_list.append(down)
            if (left.isalpha()) and (right.isalpha()) and (up.isalpha()) and (down.isalpha())\
                and sorted(direct_list) == sorted(list(set(direct_list)))\
                and len(direct_list) == 4:
                break
            else: print("Invalid input. Please try again.")
        except: print("Invalid input. Please try again.")
#### Ensure the symbol is a letter, no repetition and in adequate numbers.
### Determine the direction symbol.


## Step 2: Data Initialization
    import random
    raw = []    
    for i in range(num**2):
        raw.append(str(i))
### Initialize a ordered value in raw list.
    while True:
        for i in range(num**2):
            tmp = raw[i]
            pos = random.randint(0,num**2-1)
            raw[i] = raw[pos]
            raw[pos] = tmp
        rev_num = 0
        for j in raw:
            for k in raw[0:raw.index(j)-1]:
                if k > j:
                    rev_num += 1
        if num == 3:
            if rev_num % 2 == 0: break
        if num == 4:
            if rev_num % 2 == 1: break
### Generate a random list by swapping one element in raw list with another one. 
### Also guarantee the puzzle is solvable.

## Step 3: Interface Presentation
    def pre():
        for i in range(num**2):
            if raw[i] == "0":
                print("".ljust(4),end="")
            else: print(raw[i].ljust(4),end="")
            if i % num == num - 1: print("\n")
    ### Generate and adjust for an artificial board.


## Step 4: Find Blank
    def findBlank():
        for i in range(num**2):
            if raw[i] == "0": 
                return i
### Find blank space and return its index.        


## Step 5: User Movement
    def movement(): 
        opt_list = []
        if (findBlank() + 1) < num**2 and (findBlank() + 1) % num != 0: 
            opt_list.append("left-%s" % left)
### The spaces on the right must be within, and must be an artificial neighbour of it.
        if (findBlank() - 1) >= 0 and findBlank() % num != 0:   
            opt_list.append("right-%s" % right)
### The spaces on the left must be within, and must be an artificial neighbour of it.
        if (findBlank() + num) < num**2:
            opt_list.append("up-%s" % up)
### The spaces on the top must be within, and must be an artificial neighbour of it.
        if (findBlank() - num) >= 0:
            opt_list.append("down-%s" % down)
### The spaces on the bottom must be within, and must be an artificial neighbour of it.
        opt_str = ""
        for temp in opt_list:
            opt_str += temp + ", "
        opt_str = opt_str[: -2]
        option = input("Enter your move! " + "(" + opt_str + ") ")
### Display possible operations.
        if option == left:
            pos = findBlank()
            tmp = raw[pos]
            raw[pos] = raw[pos+1]
            raw[pos+1] = tmp
        elif option == right: 
            pos = findBlank()
            tmp = raw[pos]
            raw[pos] = raw[pos-1]
            raw[pos-1] = tmp        
        elif option == up:
            pos = findBlank()
            tmp = raw[pos]
            raw[pos] = raw[pos + num]
            raw[pos + num] = tmp
        elif option == down:
            pos = findBlank()
            tmp = raw[pos]
            raw[pos] = raw[pos - num]
            raw[pos - num] = tmp


## Step 6: Game Start
    def win():
        for i in range(num**2 - 1):
            if raw[i] != str(i+1):
                return False
        else: return True
 ### Determine if it is in accordance with a win.



## Main:
    pre()
    i = 0
    while (win() != True):
        movement()
        pre()
        i += 1
    print("Congratulations! You solved the puzzle in " + str(i) + " moves!")





     




