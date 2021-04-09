from turtle import Turtle, Screen
import random

tim = Turtle()
tim.shape("turtle")

screen = Screen()
screen.colormode(255)


def random_rgb_color():
    random_red = random.randint(0, 255)
    random_green = random.randint(0, 255)
    random_blue = random.randint(0, 255)
    random_color_generated = (random_red, random_green, random_blue)
    return random_color_generated


def make_circle(turtle, radius):
    turtle.color(random_rgb_color())
    turtle.circle(radius)


def draw_spirograph(turtle, radius=60, angle=10, speed=1):
    turtle.speed(speed)
    arc_number = int(360/angle)
    for _ in range(arc_number):
        make_circle(turtle, radius)
        turtle.left(angle)


draw_spirograph(tim, 150, 5, 0)

screen.exitonclick()
