# lista4 = [1, 2, 3, 4] -> 4, rep: 1
# lista4 = [1, 1, 3, 4] -> 4, rep: 2
# lista4 = [1, 1, 3, 3] -> 4, rep: 2
# lista4 = [1, 1, 1, 4] -> 6, rep: 3
# lista4 = [1, 1, 1, 1] -> -1, rep: 4

testes = int(input())

for teste in range(testes):

    lista = input()
    l = []
    for i in lista:
        l.append(int(i))

    counter = {} # stores number of occurrences
    for i, v in enumerate(l):
        if v in counter:
            counter[v] += 1
        else:
            counter[v] = 1

    rep = max(list(counter.values()))
    if rep == 1:
        print(4)
    elif rep == 2:
        print(4)
    elif rep == 3:
        print(6)
    else:
        print(-1)
