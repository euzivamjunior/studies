#Password Generator Project
import random
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

print("Welcome to the PyPassword Generator!")
nr_letters= int(input("How many letters would you like in your password?\n")) 
nr_symbols = int(input(f"How many symbols would you like?\n"))
nr_numbers = int(input(f"How many numbers would you like?\n"))

#Eazy Level - Order not randomised:
#e.g. 4 letter, 2 symbol, 2 number = JduE&!91
password = ''
for i in range(nr_letters):
  letter = random.choice(letters)
  password += letter

for i in range(nr_symbols):
  symbol = random.choice(symbols)
  password += symbol

for i in range(nr_numbers):
  number = random.choice(numbers)
  password += number

print("Order not randomised:", password) 

#Hard Level - Order of characters randomised:
#e.g. 4 letter, 2 symbol, 2 number = g^2jk8&P

# cria uma lista com os caracteres de password
pass_ = []
for i in password:
  pass_.append(i)
random_password =''

#Minha Solução:
'''
#escolhe randomicamente um elemento desta lista, o adiciona a pass_ e então deleta esse elemento da lista

for i in range(0, len(password)):
  char_index = random.randint(0, len(pass_)-1)
  random_password += pass_[char_index]
  del pass_[char_index]

print("Order of characters randomised:",random_password)
'''

#Solução Instrutor:
random.shuffle(pass_)
for item in pass_:
  random_password += item

print("Order of characters randomised:",random_password)