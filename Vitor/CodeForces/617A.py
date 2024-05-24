"""
x = 5 -> 1 : 5/5 = 1

x = 12 -> 3 : 12/5 = 2.4 -> ceil

x = 19 -> 4 : 19/5 = 3.8 -> ceil

x = 42 -> 9 : 42/5 = 8.4 -> ceil

x = 22 -> 5 : 22/5 = 4.4 -> ceil

x = 31 -> 7 : 32/5 = 6.2 -> ceil

"""

from math import ceil

x = int(input())

print(ceil(x/5))