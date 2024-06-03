n = int(input())

lista = input().split()
a = list(map(int, lista))

soma: int = 0

for i in a:
    if i < max(a):
        soma += max(a) - i
        
print(soma)