p, desloc = list(map(int,input().split()))

total = 240

tempo_exercicio = 5
tempo = 0


i = 0
while i < p:
    tempo += (i+1) * 5
    if desloc + tempo > total:
        break

    i += 1
        
print(i)


# [500,100,400,900,800,500]
# 100,
# 400,
# 500,
# 500,
# 900,

# [100,400,500,800,900]

# lst = list(1,range(1e6)+1)

# def findLinear(lst,v = 5*1e5):
#     steps = 0
#     for i in range(len(lst)):
#         steps += 1
#         if lst[i] == v:
#             return i, steps
#     return -1,steps

# def binarySearch(lst,v = 5*1e5):
#     low = 0
#     high = len(lst)-1
#     mid = 0
#     steps = 0

#     while low <= high:
#         steps += 1
#         mid = (low + high) // 2

#         if lst[mid] == v:
#             return mid,steps
#         elif lst[mid] < v:
#             low = mid + 1
#         else:
#             high = mid-1
    
#     return -1,steps

# import random


# def run():

#     lst = random.sample(range(1,int(1e6)),1000)

#     search_elm = lst[random.randint(0,len(lst)-1)]

#     _, steps1 = findLinear(lst,v = search_elm)
#     _, steps2 = binarySearch(lst,v = search_elm)

#     return steps1,steps2

# def runMultiple(n = 10):
#     linear = [0]*n
#     binary = [0]*n


#     for i in range(n):
#         l,b = run()
#         linear[i] = l
#         binary[i] = b
    
#     for i in range(n):

#         print(linear[i])
#         print(binary[i])
#         print("-"*30)


# runMultiple()

# # pior caso: N, melhor caso: 1, caso médio: N/2




