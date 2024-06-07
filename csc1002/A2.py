import turtle
# Set key constants.
BOARD_SIZE = 8
TOKEN_SIZE = 23
CELL_SIZE = 60
TRACKER_HEIGHT = 20
TRACKER_WIDTH = 60
OUTLINE_WIDTH = 5

# Set board with a nesting list.
board = [[0 for j in range(BOARD_SIZE)] for i in range(BOARD_SIZE)]

def checkfull():
    """
    This function traverses the whole board list to check if there is blank space.
    If there is not, the board is full.
    """
    if all(0 not in row for row in board):            
        return True


def draw_token(x, y, color, is_winning_token = False):
    """
    This function is utilized for drawing circles.
    If the specific circles are the winning ones, it will draw frameless red circles.
    If they are just common ones, it will draw token-like circles with colors according to current player. 
    """
    if is_winning_token:
        turtle.penup()
        turtle.goto(x, y)
        turtle.color("red")     # frameless red circles
        turtle.pensize(5)
        turtle.pendown()
        turtle.circle(TOKEN_SIZE)
    else:
        turtle.penup()
        turtle.goto(x, y)
        turtle.color(color)     # token-like circles
        turtle.pendown()
        turtle.begin_fill()
        turtle.circle(TOKEN_SIZE)
        turtle.end_fill()


def draw_trackers():
    """
    This function is utilized for drawing black column trackers.
    """
    for i in range(BOARD_SIZE):
        turtle.penup()
        turtle.goto(-230 + i * TRACKER_WIDTH, -255)
        turtle.pendown()
        turtle.begin_fill()
        turtle.setheading(90)
        turtle.forward(10)
        turtle.right(90)
        turtle.forward(CELL_SIZE * 0.75)    #additional width of 0.25 spaced for margins
        turtle.right(90)
        turtle.forward(10)
        turtle.end_fill()


def highlight_tracker(player):
    """
    This function is utilized for highlighting specific column tracker according to current player and mouse location.
    """
    turtle.color("blue" if player == 1 else "purple")
    turtle.penup()
    turtle.goto(-230 + mouse_col * TRACKER_WIDTH, -255)
    turtle.pendown()
    turtle.pensize(3)
    turtle.setheading(90)
    turtle.forward(10)
    turtle.right(90)
    turtle.forward(CELL_SIZE * 0.75)
    turtle.right(90)
    turtle.forward(10)
    turtle.penup()
     

def update_title(player):
    """
    This function changes the title of the turtle window each time the player is turned over.
    """
    turtle.title(f"Connect 4 - Player {player} Turn")               


def check_winner(board, player):
    """
    This function is utilized to check strings of winning tokens and return their coordinates if available.
    """
    #check direction of -
    for row in range(BOARD_SIZE):
        for col in range(BOARD_SIZE - 3):
            if (board[row][col] == player and 
                board[row][col+1] == player and 
                board[row][col+2] == player and
                board[row][col+3] == player):
                return [(row, col), (row, col+1), (row, col+2), (row, col+3)]
    
    #check direction of |
    for col in range(BOARD_SIZE):
        for row in range(BOARD_SIZE - 3):
            if (board[row][col] == player and
                board[row+1][col] == player and
                board[row+2][col] == player and
                board[row+3][col] == player):
                return [(row, col), (row+1, col), (row+2, col), (row+3, col)]

    #check direction of \
    for row in range(BOARD_SIZE - 3):
        for col in range(BOARD_SIZE - 3):
            if (board[row][col] == player and
                board[row+1][col+1] == player and
                board[row+2][col+2] == player and
                board[row+3][col+3] == player):
                return [(row, col), (row+1, col+1), (row+2, col+2), (row+3, col+3)]
    
    #check direction of /
    for row in range(BOARD_SIZE - 3):
        for col in range(3, BOARD_SIZE):
            if (board[row][col] == player and
                board[row+1][col-1] == player and
                board[row+2][col-2] == player and
                board[row+3][col-3] == player):
                return [(row, col), (row+1, col-1), (row+2, col-2), (row+3, col-3)]
    return None


game_over = False
def click(x, y):
    """
    This function is utilized to react to the event of "click" and complete the corresponding operations.
    """
    global board, current_player, game_over
    #print("click", x, y)
    col = int((x + BOARD_SIZE * CELL_SIZE // 2) // CELL_SIZE)   #convert x-coordinate to col-number
    row = -1
    if game_over:
        return
    if col < 0 or col >= BOARD_SIZE:    #stop executing if x-coordinate of the click is out-of-range
        return
    for i in range(BOARD_SIZE):         #return the first row with empty space
        if board[i][col] == 0:
            row = i
            break
    if row == -1:                       #define original situation
        return
    
    board[row][col] = current_player    #confirm corresponding token-type with player-code
    
    draw_token(-BOARD_SIZE * CELL_SIZE // 2 + col * CELL_SIZE + TOKEN_SIZE// 2,\
                -BOARD_SIZE * CELL_SIZE // 2 + row * CELL_SIZE + CELL_SIZE// 2,\
                "blue" if current_player == 1 else "purple")
    
    if check_winner(board, current_player) != None:     #change the title if there is winner and circle winning tokens.
        turtle.title(f"Winner! Player {current_player}")
        game_over = True
        
        for i in range(0,len(check_winner(board, current_player))):
            draw_token(-BOARD_SIZE * CELL_SIZE // 2 + int(check_winner(board, current_player)[i][1]) * CELL_SIZE + TOKEN_SIZE// 2,\
                        -BOARD_SIZE * CELL_SIZE // 2 + int(check_winner(board, current_player)[i][0]) * CELL_SIZE + CELL_SIZE// 2,\
                        "blue" if current_player == 1 else "purple",True)
        turtle.done()
        return
    
    current_player = 3 - current_player
    update_title(current_player)      #change the title for current player for common cases
    
    if checkfull():                   #change the title for a tie if the board is full
            turtle.title(f"Tie!")

def motion(motion):
    """
    This function is utilized to get coordinates of the event of "motion", convert it to column number and highlight specific tracker.
    """
    global mouse_col
    x = motion.x
    converted_x = x - 273
    mouse_col = int((converted_x + BOARD_SIZE * CELL_SIZE // 2) // CELL_SIZE)
    #print("motion", converted_x)
    #print("col", mouse_col)
    
    ####### Explanation:
    # Even though I am able to code a function for highlighting and show motion-coordinate and click-coordinate. I really find it hard to
    #    meet the requirement of highlighting the specific tracker because of some unknown bugs or error. I am really sorry, but I have tried 
    #    my best and show my latest attempt until ddl. 
     

# Set up Turtle Graphics
turtle.speed(0)
turtle.hideturtle()
turtle.setup(BOARD_SIZE * CELL_SIZE + CELL_SIZE, BOARD_SIZE * CELL_SIZE + CELL_SIZE * 2)

screen = turtle.Screen()
screen.onclick(click)
canvas = screen.getcanvas()
canvas.bind('<Motion>', motion)     #bind motion to the function

def main():
    global current_player
    current_player = 1

    turtle.bgcolor("white")
    draw_trackers()
    update_title(current_player)
    turtle.mainloop()

if __name__ == "__main__":
    main()