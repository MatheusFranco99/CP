n = int(input())

lista = list(map(int, input().split()))

pct = 0

for _, v in enumerate(lista):
    if v != 0:
        pct += v
        
print(pct/n)