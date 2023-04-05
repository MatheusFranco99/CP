# Code forces

input1 = input().split()
n = int(input1[0])
k = int(input1[1])

lista = input().split()
for i in range(len(lista)):
    lista[i] = int(lista[i])

aprovados = 0

for i, value in enumerate(lista):
    if value >= lista[k-1] and value > 0:
        aprovados += 1


print(aprovados)