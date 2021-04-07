from coffee_art import logo
print(logo)

MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}

resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
    "money": 0,
}


def check_resources(ingredients):
    """Returns True when order can be made, False if ingredients are insufficient."""
    for item in ingredients:
        if resources[item] < ingredients[item]:
            print(f"Sorry there is not enough {item}.")
            return False
    return True


def reload_resources():
    resources["water"] = 300
    resources["milk"] = 200
    resources["coffee"] = 100
    print("The resources available was reload")


def process_coins():
    """Returns the total calculated from coins inserted."""
    print("Please insert coins.")
    quarters = int(input("How many quarters?: "))
    dimes = int(input("How many dimes?: "))
    nickles = int(input("How many nickles?: "))
    pennies = int(input("How many nickles?: "))
    total_cash = (quarters * 0.25) + (dimes * 0.10) + (nickles *
                                                       0.05) + (pennies * 0.01)
    return total_cash


def transaction(total_cash, cost):
    """Return True when the payment is accepted, or False if money is insufficient."""
    if total_cash < cost:
        print("Sorry that's not enough money. Money refunded.")
    else:
        resources["money"] += cost
        refund = round(total_cash - cost, 2)
        if refund > 0:
            print(f"Here is {refund} dollars in change.")


def make_coffee(ingredients):
    """Deduct the required ingredients from the resources."""
    for item in ingredients:
        resources[item] -= ingredients[item]
    print("Here is your latte. Enjoy!")


while True:
    choice = input("What would you like? (espresso/latte/cappuccino): ")
    if choice == "off":
        break
    elif choice == "report":
        print(f"Water: {resources['water']} ml")
        print(f"Milk: {resources['milk']} ml")
        print(f"Coffee: {resources['coffee']} g")
        print(f"Money: ${resources['money']}")
    elif choice == "reload":
        reload_resources()
    else:
        coffee = MENU[choice]
        check = check_resources(coffee["ingredients"])
        if check == True:
            total_cash = process_coins()
            transaction(total_cash, coffee["cost"])
            make_coffee(coffee["ingredients"])
