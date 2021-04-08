"""
    Pretty Table Package:
    https://pypi.org/project/prettytable/
    Pretty Table Documentation:
    https://code.google.com/archive/p/prettytable/wikis/Tutorial.wiki
"""

from prettytable import PrettyTable
table = PrettyTable()
table.add_column("Pokemon Name", ["Pikachi", "Squirtle", "Charmander"])
table.add_column("Type", ["Electric", "Water", "Fire"])
table.align["Pokemon Name"] = "l"
table.align["Type"] = "l"

print(table)
