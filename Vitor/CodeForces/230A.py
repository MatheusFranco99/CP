"""
SE KIRITO S > DRAGON[i] S, KIRITO S += DRAGON[i] BONUS
Ordenar os dragons por forca e depois bonus atk
-> Separar o de menor atk em uma variavel
-> Se 2 atks iguais -> pegar a lista com maior soma (maior bonus)
-> Se atk de kirito > lista[0], somar lista[1] ao atk de kirito
-> Se o atk de kirito < lista[0] = "NO"
-> Tirar a lista da matriz. Acaba e "YES" quando a lista estiver vazia
-> A cada loop, comparar o atk de kirito com o maior atk. Se maior: "YES" e acaba
55
[
    [50, 10],
    [70, 50]
    [50, 50]
    [1,  99],
    [100, 0]
]
2 2
1 99
100 0
YES
"""

input1 = input().split()
s = int(input1[0])
n = int(input1[1])

m: list = []

for i in range(n):
    lista = input().split()
    lista = list(map(int, lista))
    m.append(lista)

m = sorted(m, key=lambda x: (x[0], -x[1]))
y = 0

for i in range(len(m)):
    if m[i][0] >= s:
        print("NO")
        break

    s += m[i][1]
    y += 1

    if len(m) == y:
        print("YES")
