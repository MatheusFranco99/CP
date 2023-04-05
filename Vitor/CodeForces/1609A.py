"""
1 2 3 4 5



8 16 22 48 25 100

1 1 11 3 25 25

2^3
2^4
2*11
2^4*3
5^2
2*5^2
type in.txt | python 1609A.py
"""


t = int(input())

for _ in range(t):

    n = int(input())

    lista = list(map(int, input().split()))

    soma_dois = 0

    for i, v in enumerate(lista):
        while lista[i] % 2 == 0:
            lista[i]/=2
            soma_dois += 1

    maior = max(lista)
    maior_soma = maior * pow(2,soma_dois)

    result = maior_soma + sum(lista) - maior

    print(int(result))