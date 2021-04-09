from turtle import Turtle, Screen
import random

tim = Turtle()
tim.shape("turtle")


def polygon(turtle, sides=4, line_size=100):
    colors = ["royalblue", "firebrick", "darkorchid",
              "mediumspringgreen", "gold", "deeppink"]
    random_color = random.choice(colors)
    tim.color(random_color)
    angle = 360/sides
    for side in range(sides):
        turtle.forward(line_size)
        turtle.right(angle)


for sides in range(3, 11):
    polygon(tim, sides)

screen = Screen()
screen.exitonclick()
