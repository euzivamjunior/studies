'''
replit clear is used to clear the console on replit environment
'''
from replit import clear
from art import logo
#HINT: You can call clear() to clear the output in the console.
print(logo)
print("Welcome to the secret auction program.")
bids = {}
while True:
  name = input("What is your name?: ")
  bid = int(input("What's your bid?: $"))
  bids[name] = bid
  new_bid = input("Are there any other bidders? Type 'yes' or 'no'.")
  if new_bid == 'no':
    break
  else:
    clear()

clear()
winner = max(bids, key=bids.get)
print(f"The winner is {winner} with a bid of ${bids[winner]}.")