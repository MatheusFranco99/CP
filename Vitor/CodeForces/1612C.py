"""
X -> 1
X X -> 3
X X X -> 6
X X X X -> 10
X X X X X-> 15
X X X X -> 19
X X X -> 22
X X -> 24
X  -> 25

X
X X
X X X
X X X X
X X X
X X
X
lst: [1, 2, 3, ..., k-1, k, ..., 3, 2, 1]

= PA1 + k-1 + k-2 + k-3 + ... + k-i

S = k-1 + k-2 + k-3 + ... + k-i
S = k-i + k-i+1 + k-i+2 + ... + k-1
2S = (2k-1-i) + (2k-i-1) + ... + (2k-i-1) = (2k-i-1) * (i-2)

S = (2k-i-1) * (i-2)/2



87, 56

87 - 56 -1


S = 1, 2, 3, ..., k
S = k, k-1, k-2, ..., 1

2S = (k+1) + (k+1) + ... + (k+1) = (k+1) * k

S = k * (k+1) / 2



lst : [1, 3, 6, 10, 15, 19, 22, 24, 25]

soma[i] = lista[i]
"""
    
    

SOMA = 0 # emotes
K = 1000000000 # 2k - 1 mensagens
X = 923456789987654321 # limite de emotes
COUNT = 1 # número de linhas


verbose = False


def PA(a,b):
    c = min(a,b)
    d = max(a,b)
    a = c
    b = d

    return (a+b)*(b-a+1)//2


def value_in_list(v,k):
    # recebe o numero da mensagem, v, e o k
    # retorna o numero de emojis enviados ate v (inclusive)

    if v <= k:
        return PA(1, v)
    else:
        MSG_v = 2 * k - v
        return PA(1, k) + PA(k-1, MSG_v)

# lista low->1 ate high->2k-1

exemplo = [1, 3, 6, 10, 15, 19, 22, 24, 25]

# bin search: tem lista e quer buscar elemento na lista
def search1(lst,X):
    low = 0
    high = 2*K

    while low <= high:
        mid = (low + high) // 2
        if lst[mid] == X:
            return mid
        elif lst[mid] < X:
            low = mid + 1
        elif lst[mid] > X:
            high = mid - 1
    return -1

# bin search: tem lista e quer buscar menor elm da lista que eh maior que X

# [1, 5, 8, 11, 15, 20]
    0, 1, 2, 3, 4, 5
    X = 20
def search2(lst,X):
    low = 0
    high = len(lst)-1

    result = None

    while low <= high:

        mid = (low + high) // 2

        print(f"{low=},{high=},{mid=},{lst[mid]=},{X=}")

        if lst[mid] == X:
            return mid
        if lst[mid] > X:
            result = mid
            high = mid - 1
        else:
            low = mid + 1
        print(f"\tnext:{low=},{high=}")
    
    if result == None:
        return len(lst)-1

    return result
    

# bin search: sem lista e quer buscar menor elm da lista que eh maior que X
def search3(low,high,X,function):

    original_high = high

    result = None

    while low <= high:

        mid = (low + high) // 2

        v = function(mid)

        if verbose:
            print(f"{low=},{high=},{mid=},{v=},{X=}")

        if v == X:
            return mid
        if v > X:
            result = mid
            high = mid - 1
        else:
            low = mid + 1
        if verbose:
            print(f"\tnext:{low=},{high=}")
    
    if result == None:
        return original_high

    return result

def solve2(k,x):

    print(search3(1,2*k-1,x,lambda line: value_in_list(line,k)))



def solve(k,x):
    K = k
    X = x
    SOMA = 0
    COUNT = 1
    for i in range(1, 2*K):
        if i <= K:
            SOMA += i
        else:
            SOMA += (2*K - i)

        if verbose:
            print("-"*50)
            print(f"{i=},{SOMA=},{X=}")
            print(f"{COUNT=}")
            print(f"{SOMA<=X=}")


        if SOMA < X:
            COUNT+=1
            continue
        else:
            break

    print(min(COUNT,2*K-1))

def main():
    t = int(input())

    while t > 0:
        
        k,x = map(int,input().split())
        
        if x == 0 or k == 0:
            print(0)
        if x == 1 or k == 1: # Casos extremos
            print(1)
        else:
            solve2(k,x)

        t -= 1



def main2():
    lst = [1,5,8,11,15,20]
    x = 11

    print(search3(0,len(lst)-1,x,lambda x: lst[x]))
    # print(search2(lst,x))

if __name__ == '__main__':
    main()

# lst = [2,3,4,5,6,7,8,9,10,11,12]

# def bin_search(lst,v):
#     low = 0
#     high = len(lst)-1

#     while low <= high:
#         mid = (low + high) // 2

#         if lst[mid] == v:
#             return mid
#         elif lst[mid] > v:
#             high = mid - 1
#         elif lst[mid] < v:
#             low = mid + 1

#     return -1

    

# print(bin_search(lst,8))