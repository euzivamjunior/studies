"""
    Turtle documentation:
    https://docs.python.org/3/library/turtle.html
    Turtle Colors Code:
    https://cs111.wellesley.edu/labs/lab01/colors
"""
from turtle import Turtle, Screen

timmy = Turtle()
print(timmy)
timmy.shape("turtle")
timmy.color("chartreuse3")
timmy.forward(100)

my_screen = Screen()
print(my_screen.canvheight)
my_screen.exitonclick()