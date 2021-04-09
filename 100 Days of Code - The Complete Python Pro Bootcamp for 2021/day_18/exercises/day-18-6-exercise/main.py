from turtle import Turtle, Screen
import random

tim = Turtle()
tim.shape("turtle")
tim.speed(0)

screen = Screen()
screen.colormode(255)


def random_rgb_color():
    random_red = random.randint(0, 255)
    random_green = random.randint(0, 255)
    random_blue = random.randint(0, 255)
    random_color_generated = (random_red, random_green, random_blue)
    return random_color_generated


def random_walk(turtle, steps=10, step_size=10, line_width=5):
    angle = [0, 90, 180, 270]
    tim.pensize(line_width)
    for step in range(steps):
        turtle.color(random_rgb_color())
        random_angle = random.choice(angle)
        turtle.right(random_angle)
        turtle.forward(step_size)


random_walk(tim, 300, 20)

screen.exitonclick()
