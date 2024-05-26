t = int(input())


for i in range(t):
    inputs = input().split()
    a = int(inputs[0])
    b = int(inputs[1])

    if a % b == 0:
        print(0)
    else:
        print(b - (a % b))
