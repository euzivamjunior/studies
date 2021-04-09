from turtle import Turtle, Screen

tim = Turtle()
tim.shape("turtle")
tim.color("darkorange")


def dashed_line(turtle, dash_size=10, dash_number=10, rotate_left=0):
    turtle.left(rotate_left)
    for dash in range(dash_number):
        turtle.forward(dash_size)
        turtle.penup()
        turtle.forward(dash_size)
        turtle.pendown()


dashed_line(tim, 4, 50)
dashed_line(tim, 4, 50, 90)
dashed_line(tim, 4, 50, 90)
dashed_line(tim, 4, 50, 90)

screen = Screen()
screen.exitonclick()
