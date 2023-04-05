testes = int(input(""))

for teste in range(testes):
    lista = list(map(int, input("").split()))

    if lista[0] + lista[1] == lista[2]:
        print("+")
    else:
        print("-")
