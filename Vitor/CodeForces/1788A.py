# Code Forces

t = int(input())

for tt in range(t):

    n = int(input())

    lista = list(map(int, input().split()))

    found = False

    soma_primeiro = 0
    soma_segundo = 0

    for v in lista:
        if v == 2:
            soma_segundo+=1

    for i, value in enumerate(lista):
        if i >= len(lista) - 1:
            break
        if value == 2:
            soma_primeiro+=1
            soma_segundo-=1

        if soma_primeiro == soma_segundo:
            print(i+1)
            found = True
            break

    if not found:
        print(-1)
