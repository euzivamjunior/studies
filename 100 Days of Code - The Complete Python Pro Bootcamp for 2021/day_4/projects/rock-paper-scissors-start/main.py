import random
rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''


user_choice = int(input("What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors.\n"))

choice = [rock, paper, scissors]

print(choice[user_choice])
print("Computer chose:")

computer_choice = random.randint(0,2)
print(choice[computer_choice])

if (user_choice == 0) and (computer_choice == 2):
  print("You won!")
elif (user_choice == 2) and (computer_choice == 0):
  print("You lose")
elif (user_choice > computer_choice):
  print("You won!")
elif (user_choice == computer_choice):
  print("It's a draw")
else:
  print("You lose")

