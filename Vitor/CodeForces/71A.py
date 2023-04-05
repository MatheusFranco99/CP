# Code Forces

num = int(input())

for i in range(num):

    word = input()

    n = len(word)
    if n <= 10:
        print(word)
    else:
        print(word[0] + str(n - 2) + word[-1])
