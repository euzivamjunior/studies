#Write your code below this line 👇
def paint_calc(height, width, cover):
  '''
  -(-number // number2): rounds up float number. ex: 27/5 = 5.4 => round up: 6 
  '''
  number_of_cans = -(-(height * width) // cover)
  
  print(f"You'll need {number_of_cans} cans of paint.")

#Write your code above this line 👆
# Define a function called paint_calc() so that the code below works.   

# 🚨 Don't change the code below 👇
test_h = int(input("Height of wall: "))
test_w = int(input("Width of wall: "))
coverage = 5
paint_calc(height=test_h, width=test_w, cover=coverage)