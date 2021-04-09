"""
    Turtle Documentation:
        https://docs.python.org/3/library/turtle.html#turtle.forward
    Turtle Colors:
        https://cs111.wellesley.edu/labs/lab01/colors
    Colors:
        https://trinket.io/docs/colors
"""
from turtle import Turtle, Screen

timmy = Turtle()
timmy.shape("turtle")
timmy.color("red")


def square_draw():
    for side in range(4):
        timmy.forward(100)
        timmy.left(90)


square_draw()

screen = Screen()
screen.exitonclick()
