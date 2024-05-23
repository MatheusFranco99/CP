"""
par = (n/2)-1

impar = floor(n/2)

"""

from math import floor

t = int(input())

for i in range(t):
    n = int(input())

    if n % 2 == 0:
        print(int((n / 2) - 1))
    else:
        print(int(floor(n / 2)))
