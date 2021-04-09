"""
    Turtle Documentatio:
        https://docs.python.org/3/library/turtle.html#turtle.forward
    Turtle Colors:
        https://cs111.wellesley.edu/labs/lab01/colors
    Colors:
        https://trinket.io/docs/colors
"""


from turtle import Turtle, Screen

timmy_the_turtle = Turtle()
timmy_the_turtle.shape("turtle")
timmy_the_turtle.color("red")

timmy_the_turtle.forward(100)
timmy_the_turtle.left(45)
timmy_the_turtle.forward(100)

screen = Screen()
screen.exitonclick()
