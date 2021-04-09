from turtle import Turtle, Screen
import random

tim = Turtle()
tim.shape("turtle")
tim.speed(0)


def random_walk(turtle, steps=10, step_size=10, line_width=5):
    colors = ["royalblue", "firebrick", "darkorchid",
              "mediumspringgreen", "gold", "deeppink"]
    angle = [0, 90, 180, 270]
    turtle.pensize(line_width)
    for step in range(steps):
        random_color = random.choice(colors)
        turtle.color(random_color)
        random_angle = random.choice(angle)
        turtle.right(random_angle)
        turtle.forward(step_size)


random_walk(tim, 100, 30)

screen = Screen()
screen.exitonclick()
