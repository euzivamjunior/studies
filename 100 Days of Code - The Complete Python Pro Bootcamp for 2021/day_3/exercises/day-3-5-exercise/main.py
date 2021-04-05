# 🚨 Don't change the code below 👇
print("Welcome to the Love Calculator!")
name1 = input("What is your name? \n")
name2 = input("What is their name? \n")
# 🚨 Don't change the code above 👆

#Write your code below this line 👇
combined = (name1+name2).lower()

first_score = 0
second_score = 0

for i in combined:
  if i in "true":
    first_score += 1
  if i in "love":
    second_score += 1

final_score = (first_score * 10) + second_score

if final_score < 10 or final_score > 90:
  print(f"Your score is {final_score}, you go together like coke and mentos.")
elif final_score > 40 and final_score < 50:
  print(f"Your score is {final_score}, you are alright together.")
else:
  print(f"Your score is {final_score}.")