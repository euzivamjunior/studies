"""
    Coffee Machine Documentation:
    https://docs.google.com/document/d/e/2PACX-1vTragRHILyj76AvVgpWeOlEaLBXoxPM_43SdEyffIKtOgarj42SoSAsK6LwLAdHQs2qFLGthRZds6ok/pub
"""

from menu import Menu, MenuItem
from coffee_maker import CoffeeMaker
from money_machine import MoneyMachine

menu = Menu()
money_machine = MoneyMachine()
coffee_maker = CoffeeMaker()

while True:
    choice = input(f"What would you like? ({menu.get_items()}): ")
    if choice == "off":
        break
    elif choice == "report":
        coffee_maker.report()
        money_machine.report()
    else:
        """
        coffee = menu.find_drink(choice)
        if coffee is not None:
            check = coffee_maker.is_resource_sufficient(coffee)
            if check:
                transaction = money_machine.make_payment(coffee.cost)
                if transaction:
                    coffee_maker.make_coffee(coffee)"""
        coffee = menu.find_drink(choice)
        if coffee is not None:
            if coffee_maker.is_resource_sufficient(coffee) and money_machine.make_payment(coffee.cost):
                coffee_maker.make_coffee(coffee)
