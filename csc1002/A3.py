import turtle as t
import random
import time


def draw_frame():
    """
    The function is utilized to initialize basic GUI frame, initialize the status area and give a welcome reminder.
    """
    line.hideturtle()
    line.pensize(5)
    line.penup()

    corners = [
        (-250, 210), (-250, 290), (250, 290), (250, 210),
        (-250, 210), (-250, -290), (250, -290), (250, 210)
    ]
    # Coordinates of corners are all stored in a list for the convenience of editing.
    
    for corner in corners:
        line.goto(*corner)  # "*" is ued to unpack the tuple and pass the value of coordinate.
        line.pendown()

    t.update()

    word.up()
    word.hideturtle()
    word.goto(-200, 240)
    word.color('black')
    word.write('Contact: 0         Time: 0         Motion: Pause', font=('arial', 20))

    word.goto(-200, 60)
    word.write("Welcome to my Snake game!\nClick anywhere on the screen to start the game.", font=('arial', 15))


def collides_with_body(new_x, new_y):
    """
    The function is utilized to prevent the snake from passing itself by comparing the coordinates of body.
    """
    for body_x, body_y in g_contact_list[:-1]:
        if new_x == body_x and new_y == body_y:
            return True
    return False


def interface():
    """
    The function is utilized to monitor the keyboard action for direction and pause column in the status area.
        It also stops the user from choosing direction that is out-of-boundary and snake-cross-itself action.
    """
    t.listen()

    x, y = snake.position()
    heading = int(snake.heading())

    directions = {
        'Right': (0, 241),
        'Left': (180, -241),
        'Up': (90, 241),
        'Down': (270, -241)
    }
    # Directions are stored in a dictionary with their corresponding boundaries.

    for key, (direction, boundary) in directions.items():
        if not ((heading == direction and
                (direction == 0 or direction == 90) and x + 20 > boundary)
                or ((direction == 180 or direction == 270) and x - 20 < boundary)):

            def update_heading(dir=direction):
                """
                The function is utilized to monitor the direction and space action in the status area.
                """
                new_x, new_y = x, y
                if dir == 0:
                    new_x += 20
                elif dir == 180:
                    new_x -= 20
                elif dir == 90:
                    new_y += 20
                elif dir == 270:
                    new_y -= 20
                # This block is used to predict ongoing position of the head in case it crosses itself.
                if not collides_with_body(new_x, new_y):
                    snake.setheading(dir)

            t.onkey(update_heading, key)

    def pause_move():
        """
        The function is utilized to reverse pause status when space is activated.
        """
        global g_pause_flag
        g_pause_flag = not g_pause_flag

    t.onkey(pause_move, 'space')


def reach_range():
    """
    The function is utilized to detect whether the snake reaches the boundaries.
        It will return False if the snake is about to leave the required area of the screen, otherwise False.
    """
    x, y = snake.position()
    heading = int(snake.heading())
    # Show heading direction of the snake using angles.
    
    right = 241
    left = -241
    up = 201
    down = -281
    head_size = 20
    # One extra pixel is reserved in case there are some inaccuracy for coordinates.
    
    if (x + head_size > right and heading == 0) or \
       (x - head_size < left and heading == 180) or \
       (y + head_size > up and heading == 90) or \
       (y - head_size < down and heading == 270):       # all situations for out-of-range
        return False
    return True


word = t.Turtle()
word.hideturtle()

line = t.Turtle()
line.hideturtle()

number = t.Turtle()
number.hideturtle()  
g_num_list = ['eaten']   # Position[0] of g_num_list is intentionally set 'eaten' to match position with number.


def eat_num():
    """
    The function is used to judge whether the food has been consumed by the snake.
        If it is ,then position tuple will be replaced by 'eaten' to remain the index of list unchanged. 
        Then all the numbers will be redrawn with position tuples remained, excluding the ones replaced by 'eaten'.
    """
    global g_extend_flag, g_num_list, g_eaten_num
    number.penup()
    x, y = snake.position()
    refresh = False
    
    for i in range(1, 6):
        if g_num_list[i] != 'eaten':
            x_food, y_food = g_num_list[i][0], g_num_list[i][1]
            if abs(x-x_food) <= 15 and abs(y-y_food) <= 15:     # Eaten if the absolute difference is within 15
                g_num_list[i] = 'eaten'
                g_eaten_num += i              # Record the sum of numbers eaten for the "win" status of the game
                number.clear()
                refresh = True                # Switch refresh_flag to be true for the number refresh.

    g_extend_flag = g_eaten_num != 0   # Once a num is eaten, i.e. g_eaten_num !=0, the snake is to extend.

    if refresh:     # redraw the numbers after refreshing
        for i in range(1, 6):
            if g_num_list[i] != 'eaten':
                x_food, y_food = g_num_list[i][0], g_num_list[i][1]
                number.goto(x_food-10, y_food-10)
                number.write(i, font=('arial', 15))


g_contact = 0
result = t.Turtle()
result.hideturtle()
result.up()


def situation_judge():
    """
    This function is utilized to check whether the snake has eaten all the food or is caught or touched by the monster.
        If all the food is eaten or the snake-head is caught, it will return True and print out result information
        If the snake-body is touched, g_contact will add 1 and increase contact number.
    """
    global g_contact, g_x_monster, g_y_monster
    x, y = snake.position()
    filtered_list = []

    touch = False
    for body in g_contact_list:
        if abs(g_x_monster - body[0]) < 15 and abs(g_y_monster - body[1]) < 15:  # body touched by the monster
            filtered_list.append(body)
            touch = True
    if touch:
        g_contact += 1

    if abs(g_dx) <= 15 and abs(g_dy) <= 15:    # head caught by the monster
        g_contact += 1
        result.goto(x-20, y+20)                # show the result aside
        result.color('red')
        result.write('Game over!', font=('arial', 15))
        return True

    for num in g_num_list:
        if num != 'eaten':
            break                       # break if there are still nums remained
    else:
        result.goto(x-20, y+20)
        result.color('green')
        result.write('You win!', font=('arial', 15))
        return True


bar = t.Turtle()
bar.hideturtle()


def show_bar():
    """
    The function is utilized to display the direction and pause column in the status area.
        It serves as a connection with "interface" function above.
    """
    bar.clear()
    total_time = time.time() - g_start_time     # show total time for the game with timer
    global g_pause_flag, g_contact
    heading_to_direction = {
        0: 'Right',
        90: 'Up',
        180: 'Left',
        270: 'Down'
    }
    # This dictionary connects angle with direction name.
    if g_pause_flag:
        direction = 'Pause'
    else:
        direction = heading_to_direction.get(snake.heading(), '')

    bar.write('Contact: %s         Time: %s         Motion: %s'
              % (g_contact, int(total_time), direction), font=('arial', 20))
    # output changing  utility information


def draw_num():
    """
    The function is utilized to draw numbers for the first time.
       In order to align the snake with the numbers, coordinates are always times of 20, with minor adjustments as well.
    """
    global g_num_list
    number.up()
    number.hideturtle()

    for i in range(1, 6):
        x, y = random.randint(-11, 11) * 20, random.randint(-13, 9) * 20  # Coordinates are times of 20 to align.
        g_num_list.append((x, y))               # Then coordinates are stored into the g_num_list for later use.
        number.goto(x-10, y-10)                 # Minor adjustment of 10 pixels is necessary to match the frame.
        number.write(i, font=('arial', 15))


def hide_and_refresh_number():
    """
    The function is utilized to refresh numbers.
        It first randomly choose a 1-to-5 number, generate a 5-to-10 second interval,
        check if it is eaten, change positions of those not been eaten. Then it redraw all the numbers as a refresh.
        However, the way of using one Turtle for all nums makes it hard to hide one num for a while and then un-hide,
        for it could be confusing and complex for a list of fixed values to do it instead of pointers of Turtles.
        That's why I could not make it hide and un-hide till ddl. What a pity!
    """
    global g_num_list
    number.clear()

    index_to_refresh = random.randint(1, 5)

    if g_num_list[index_to_refresh] != 'eaten':
        x, y = random.randint(-220, 220), random.randint(-260, 180)
        g_num_list[index_to_refresh] = (x, y)
        number.goto(x-10, y-10)
        number.write(index_to_refresh, font=('arial', 15))

    for i in range(1, 6):
        if g_num_list[i] != 'eaten':
            x, y = g_num_list[i]
            number.goto(x-10, y-10)
            number.write(i, font=('arial', 15))

    t.ontimer(hide_and_refresh_number, random.randint(5000, 10000))


def draw_snake():
    """
    The function is utilized to draw the whole snake.
        The whole snake is just a combination of moving bodies, with appropriate updating rates.
    """
    for i in range(6):  
        move_body()
        t.ontimer(t.update(), 100)


snake_list = []
g_contact_list = []
snake = t.Turtle()
snake.hideturtle()
g_head = None


def move_body():
    """
    The function is utilized to move the body of the snake. By using Turtle instance called 'snake',
        head and body are drawn, with what shown on the screen all stamps of that pen.
        That is,the body of the snake, it is a list consisting of all the stamps of the pen.
        The head of snake is exactly the same, while especially marked red.
    """
    snake.color('blue', 'black')
    snake.forward(20)
    snake_list.append(snake.stamp())
    g_contact_list.append((snake.xcor(), snake.ycor()))

    global g_head
    if g_head is not None:
        snake.clearstamp(g_head)
    snake.color('red')
    g_head = snake.stamp()


def move_tail():
    """
    The function is utilized to move the tail of the snake, i.e. clear the stamp and dull content for the snake_list.
    """
    snake.clearstamp(snake_list[0])
    snake_list.pop(0)
    g_contact_list.pop(0)


g_extend_flag = 0
g_eaten_num = 0
g_pause_flag = False


def move_snake():
    """
    The function is utilized to move the whole snake.
        Some reference is applied here as it is a bit tricky for me at first!
        Every time the snake moves, the list behaves like a queue (FIFO) if not extending.
        It includes g_head showing the existence of the head.
        Every move position of the snake head is added into the g_contact_list, for latter interaction with monster.
    """
    global g_eaten_num
    global g_dx, g_dy, g_contact, g_x_monster, g_y_monster
    g_x_monster, g_y_monster = monster.position()
    x_snake, y_snake = snake.position()
    
    g_dx, g_dy = g_x_monster - x_snake, g_y_monster - y_snake
    interface()
    if (not g_pause_flag) and (not g_extend_flag) and reach_range():
        move_body()
        move_tail()
    elif (not g_pause_flag) and g_extend_flag and reach_range():
        g_eaten_num -= 1
        move_body()
    t.ontimer(t.update(), 50)


monster = t.Turtle()
monster.hideturtle()


def move_monster():
    """
    The function is utilized to move the monster.
        It could change direction efficiently to chase the snake, with steps a bit slower than that.
    """
    
    monster.clearstamps()
    monster.setheading(
        180 if g_dx >= 0 else 0
        if abs(g_dx) >= abs(g_dy) else 270
        if g_dy >= 0 else 90
    )
    # change direction efficiently to chase the snake
    monster.forward(random.randint(5, 15))
    # The max step of monster is designed as the same as constant step of snake.
    monster.stamp()
    t.ontimer(t.update(), 25)


def move():
    """
    The function is utilized to adjust the movement of snake and monster.
        While the snake is extending, the monster will accelerate to twice its speed to catch the head of monster.
    """

    if not g_extend_flag:
        move_snake()
        move_monster()

    elif g_extend_flag:
        move_snake()
        for i in range(2):      # simply invoking move_monster function twice
            move_monster()


def initial_snake():
    """
        The function is utilized to initialize the pen of snake.
    """
    snake.penup()
    snake.shape('square')
    snake.shapesize(1, 1, 0.1)
    snake.color('white', 'black')
    snake.goto(0, -40)
    draw_frame()
    snake.goto(0, -40)
    snake.color('red')
    snake.stamp()


def initial_monster():
    """
    The function is utilized to initialize the pen of monster.
    """
    monster.color('purple')
    monster.up()
    monster.hideturtle()
    monster.shape('square')
    x, y = random.randint(-240, 240), random.randint(-280, 200)
    monster.goto(x, y)
    monster.stamp()


def initial_game():
    """
    The function is utilized to initialize snake, monster, margin and starts listening for action.
    """

    initial_snake()
    initial_monster()

    bar.up()
    bar.hideturtle()
    bar.goto(-200, 235)

    s = t.Screen()
    s.title("Xue's Snake Game")
    s.listen()
    s.onclick(main)     # Screen is attached to main() function.


def main(a, b):
    """
    The function is utilized for the key structure.
        Key structure: draw_frame() -> eat_num -> show_bar() -> move() -> situation_judge() -> Break the loop.
    """
    s = t.Screen()
    s.onclick(None)
    word.clear()
    snake.clear()
    draw_num()
    draw_snake()
    t.ontimer(hide_and_refresh_number, random.randint(5000, 10000))
    
    while True:     # stop when "win" or "lose" situation appears
        global g_extend_flag, number
        eat_num()
        show_bar()
        move()
        if situation_judge():
            show_bar()
            break


t.setup(650, 750)
t.tracer(False)
g_start_time = time.time()
# Common Turtle utility settings:
initial_game()
t.listen()
t.mainloop()