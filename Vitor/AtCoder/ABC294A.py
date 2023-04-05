n = int(input())

lista = list(map(int, input().split()))

for i in lista:
    if i % 2 == 0:
        print(i, end=" ")