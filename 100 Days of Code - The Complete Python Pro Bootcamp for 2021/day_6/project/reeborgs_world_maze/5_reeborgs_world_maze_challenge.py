'''
site to run Reeborg World Maze Challenge:
https://reeborg.ca/reeborg.html?lang=en&mode=python&menu=worlds%2Fmenus%2Freeborg_intro_en.json&name=Maze&url=worlds%2Ftutorial_en%2Fmaze1.json
'''
# First Solution: It had an bug loop problem.
'''
def turn_right():
    for turn in range(3):
        turn_left()

while not at_goal():
    if right_is_clear():
        turn_right()
        move()
    elif front_is_clear():
        move()
    else:
        turn_left()
'''

# Second Solution: Resolved bug loop problem.
'''
def turn_right():
    for turn in range(3):
        turn_left()
        
count_turn_right = 0
while not at_goal():
    if right_is_clear():
        turn_right()
        move()
        
        count_turn_right += 1
        if count_turn_right >= 3:
            if front_is_clear():
                move()
    elif front_is_clear():
        count = 0
        move()
    else:
        count = 0
        turn_left()
'''

# Instructor Bug loop Solution:
'''
def turn_right():
    for turn in range(3):
        turn_left()

while front_is_clear():
    move()
turn_left()

while not at_goal():
    if right_is_clear():
        turn_right()
        move()
    elif front_is_clear():
        move()
    else:
        turn_left()
'''