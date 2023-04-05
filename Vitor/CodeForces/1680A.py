t = int(input())

verbose = False

def log(a):
    if verbose:
        print(a)


#print(t)


def take_intersection(intervalo1, intervalo2):
    """
    intervalo1: (a,b) onde a <= b
    intervalo2: (c,d) onde c <= d
    return intersecao se houver, else None,None
    """

    if intervalo1[1] < intervalo2[0] or intervalo2[1] < intervalo1[0]:
        return None,None
    else:
        valor_minimo = max(intervalo1[0],intervalo2[0])
        valor_maximo = min(intervalo1[1],intervalo2[1])
        return valor_minimo, valor_maximo
    
    



for tt in range(t):
    inn = input()
    #print(inn)
    a, b, c, d = list(map(int, inn.split()))

    log(f"{a=},{b=},{c=},{d=}")

    # take_intersection:
    #   -> None, None se nao houver intersecao
    #   -> else: intersecao (e,f)
    e,f = take_intersection((a,b),(c,d))

    if e == None:
        print(a+c)
    else:
        print(e)


    # list1 = []
    # list2 = []

    # for i in range(a, b+1):
    #     for j in range(c, d+1):

    #         log(f"{i=},{j=}")
    #         log(f"{i==j=}")

    #         if i == j:
    #             print(i)
    #             break
    #         else:
    #             list1.append(i)
    #             list2.append(j)
    #         print(min(list1) + min(list2))
                
