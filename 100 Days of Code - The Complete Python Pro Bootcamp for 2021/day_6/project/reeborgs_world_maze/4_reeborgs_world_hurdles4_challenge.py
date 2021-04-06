'''
site to run Reeborg World Hurdles Challenge:
https://reeborg.ca/reeborg.html?lang=en&mode=python&menu=worlds%2Fmenus%2Freeborg_intro_en.json&name=Hurdle%204&url=worlds%2Ftutorial_en%2Fhurdle4.json
'''
def turn_right():
    for turn in range(3):
        turn_left()

def jump():
    turn_left()
    while not right_is_clear():
        move()
    for turn in range(2):
        turn_right()
        move()
    while front_is_clear():
        move()
    turn_left()

while not at_goal():
    if front_is_clear():
        move()
    if wall_in_front():
        jump()