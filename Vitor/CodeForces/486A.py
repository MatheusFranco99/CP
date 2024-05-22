"""

For a positive integer n let's define a function f:

f(n) = -1 + 2 -3 + .. + (-1)ˆn * n

Your task is to calculate f(n) for a given positive integer n.

f(4) = 2
f(5) = -3
f(6) = 3
f(7) = -4
f(8) = 4
"""

from math import ceil


def func(n: int):
    if n % 2 == 0:
        print(ceil(n / 2))
    else:
        print(ceil(n / 2) * (-1))


def main():
    n = int(input())

    func(n)


if __name__ == "__main__":
    main()
