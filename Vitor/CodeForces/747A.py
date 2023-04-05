"""

n = a * b

b == a
b > a
> b - a

"""

# num = 42

import math as m

# r = num**(1/2) 

# if r - m.floor(r) == 0:
#     print(int(r), int(r))

# listA = []
# listB = []

# for n in range(1, num):
#     if num % n == 0:
#         listA.append(n)
#     for nn in range(1, num):
#         if n * nn == num:
#             listB.append(nn)

# menores = []

# lista_lista = []

# for i in listA:
#     for j in listB:
#         if j * i == num:
#             lista = [j, i]
#             if i-j > 0:
#                 menores.append(i-j)
#                 # print(lista)
#                 lista_lista += [((i-j),lista)]
#                 #print(menores)
# #print(min(menores))

# # print(lista_lista)

# lista_menor_dif = lista_lista[0][1]
# menor_dif = lista_lista[0][0]
# for i in range(1,len(lista_lista)):
#     if lista_lista[i][0] < menor_dif:
#         menor_dif = lista_lista[i][0]
#         lista_menor_dif = lista_lista[i][1]
    
# print(lista_menor_dif[0], lista_menor_dif[1])

# 42: 1, 2, 3, 6, 7, 14, 21, 42
# 25 : 1, 5, 25

# fatores = []
# for f in range(1,num+1):
#     if num % f == 0:
#         fatores += [f]

# if len(fatores)%2 == 1:
#     f2 = fatores[len(fatores)//2+1]
#     print(f2, f2)
# else:
#     f1 = fatores[len(fatores)//2]
#     f2 = fatores[len(fatores)//2+1]
#     print(f1,f2)

def solve(num):
    f0 = pow(num,1/2)
    f0 = m.ceil(f0)
    f0 = int(f0)

    for f in range(f0,num+1):
        if num%f == 0:
            print(num//f, f)
            break

def main():
    # t = int(input())
    # while t > 0:
        
        # take input
    num = int(input())

    solve(num)

    # t-=1


if __name__ == '__main__':
    main()