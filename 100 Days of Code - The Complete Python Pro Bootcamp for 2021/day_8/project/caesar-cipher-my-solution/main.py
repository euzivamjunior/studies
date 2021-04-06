from art import logo

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ]

print(logo)

def paramns():
  print("########################################################")
  direction = input("\nType 'encode' to encrypt, type 'decode' to decrypt:\n")
  while direction not in ['encode', 'decode']:
    direction = input("\nYour type input ins't valid. Type 'encode' to encrypt, type 'decode' to decrypt:\n")

  text = input("\nType your message:\n").lower()
  shift = int(input("\nType the shift number:\n"))

  # For the program continues to work even if the user enters a shift number greater than 26. 
  shift = shift % 26
  return direction, text, shift

# caesar encode/decode function
def caesar(text, shift):
  message = ''
  if direction == 'decode': shift *= -1
  for letter in text:
    if letter in alphabet:
      position = alphabet.index(letter)
      new_position = position + shift
      new_position = new_position % 26
      message += alphabet[new_position]
    else:
      message+= letter
  print(f"\nThe {direction} text is: \n{message}")

while True:
  direction, text, shift = paramns()
  caesar(text, shift)
  restart = input("\nType 'yes' if you want to go again. Otherwise type 'no'.\n")
  if restart != 'yes':
    print("\nGoodbye!")
    break

'''
########## Versão 1 ############

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ]

direction = input("\nType 'encode' to encrypt, type 'decode' to decrypt:\n")
while direction not in ['encode', 'decode']:
  direction = input("\nYour type input ins't valid. Type 'encode' to encrypt, type 'decode' to decrypt:\n")

text = input("\nType your message:\n").lower()
shift = int(input("\nType the shift number:\n"))

# For the program continues to work even if the user enters a shift number greater than 26. 
shift = shift % 26



# encode message
def encrypt(text, shift):
  encrypt_message = ''
  for letter in text:
    if letter in alphabet:
      position = alphabet.index(letter)
      new_position = position + shift
      # if new_position > 25, returns to begining of list
      new_position = new_position % 26
      encrypt_message += alphabet[new_position]
    else:
      encrypt_message += letter
    
  print(f"\nThe encode text is: \n{encrypt_message}")

# decode message
def decrypt(text, shift):
  decrypt_message = ''

  for letter in text: 

    if letter in alphabet:
      position = alphabet.index(letter)
      new_position = position - shift

      decrypt_message += alphabet[new_position]
    
    else:
      decrypt_message += letter

  print(f"\nThe decode text is: \n{decrypt_message}")


if direction == 'encode':
  encrypt(text, shift)
else:
  decrypt(text, shift)
'''

''' References:
https://stackoverflow.com/questions/3883004/the-modulo-operation-on-negative-numbers-in-python

'''