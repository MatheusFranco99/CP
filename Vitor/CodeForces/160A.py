# Code Forces

n = int(input())

line = input()
lst = [int(elm) for elm in line.split()]

lst.sort()

minha_soma = 0

soma_da_lista = sum(lst)

ans = 0

idx = len(lst)-1


while minha_soma <= soma_da_lista:
    value = lst[idx]
    minha_soma += value
    soma_da_lista -= value
    ans += 1
    idx -= 1



print(ans)
