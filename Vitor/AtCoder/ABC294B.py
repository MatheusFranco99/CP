h, w = list(map(int, input().split()))

lista = []

for i in range(h):
    lista.append(list(map(int, input().split())))


for i in lista:
    for j in i:
        if j == 0:
            print(".", end="")
        else:
            print(chr(j + ord('A') - 1), end="")
    print("")
    
