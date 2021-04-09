"""
    COLORGRAM:
        https://pypi.org/project/colorgram.py/

    How this process of extract colors take some times, we'll do it only once
    and then copy the colors list returned into the rgb_colors variable
"""

"""
import colorgram


def extract_colors(image_name, colors_numbers=6):
    colors = colorgram.extract(image_name, colors_numbers)
    color_list = []
    for color in colors:
        rgb_color = (color.rgb.r, color.rgb.g, color.rgb.b)
        color_list.append(rgb_color)
    return color_list


rgb_colors = extract_colors('damien-hirst-lactulose.jpg', 30)
"""
from turtle import Turtle, Screen
import random

tim = Turtle()
tim.shape("turtle")

screen = Screen()
screen.colormode(255)

rgb_colors = [(26, 109, 164), (194, 38, 81), (237, 161, 50), (234, 215, 86),
              (227, 237, 229), (222, 137, 176), (143, 109, 57), (101, 197, 219),
              (206, 166, 29), (21, 58, 132), (212, 75, 91), (238, 89, 49),
              (141, 208, 227), (119, 192, 141), (6, 160, 87), (4, 186, 179),
              (106, 108, 198), (136, 29, 72), (98, 51, 37), (25, 153, 211),
              (228, 168, 188), (153, 213, 195), (173, 186, 221), (234, 174, 162),
              (30, 91, 95), (87, 47, 34), (34, 46, 84)]


def re_turtle(turtle, circles_side_number, distance_size):
    turtle.penup()
    move_distance = distance_size * (circles_side_number - 1) / 2
    turtle.left(180)
    turtle.forward(move_distance)
    turtle.left(90)
    turtle.forward(move_distance)
    turtle.left(90)
    turtle.pendown()


def make_circle(turtle, radius):
    color_fill = random.choice(rgb_colors)
    turtle.color(color_fill)
    turtle.begin_fill()
    turtle.circle(radius)
    turtle.end_fill()


def dot_line(turtle, radius, circles_side_number, distance_size):
    make_circle(turtle, radius)
    for i in range(circles_side_number - 1):
        turtle.penup()
        turtle.forward(distance_size)
        turtle.pendown()
        make_circle(turtle, radius)


def new_line(turtle, circles_side_number, distance_size):
    turtle.penup()
    turtle.left(180)
    return_size = (circles_side_number - 1) * distance_size
    turtle.forward(return_size)
    turtle.right(90)
    up_size = distance_size
    turtle.forward(up_size)
    turtle.right(90)
    turtle.pendown()


def hist_painting(turtle, radius=20, circles_side_number=8, step_size=20, speed=0.5, hidden=False):
    if hidden:
        turtle.hideturtle()
    turtle.speed(speed)
    distance_size = step_size + (radius * 2)
    re_turtle(turtle, circles_side_number, distance_size)
    for _ in range(circles_side_number - 1):
        dot_line(turtle, radius, circles_side_number, distance_size)
        new_line(turtle, circles_side_number, distance_size)
    dot_line(turtle, radius, circles_side_number, distance_size)


hist_painting(tim, 10, 8, 50, 0, True)

screen.exitonclick()
