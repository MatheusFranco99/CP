
""""


1elm:
    R: só precisa ter 1 L e acabou. Se não tem L, não tem solução
    L: precisa de um RL. só tem L, impossível. L _l_ _r_

"""


def Rcase(value):
    # return index of swap or -1
    if "L" in value:
        return 0
    else:
        return -1


def Lcase(value):
    # return index of swap or -1
    if "R" not in value:
        return -1
    else:
        foundR = False
        foundRL = False
        for char in value:
            if char == 'R':
                foundR = True
            if char == 'L' and foundR:
                foundRL = True
                break
        
        if foundRL:
            return 0
        else:
            for i, v in enumerate(value):
                if v == 'R':
                    return i
                

def main():
    t = int(input())
    
    for i in range(t):
        n = int(input())
        word = input()
        
        if word[0] == "R":
            print(Rcase(word))
        else:
            print(Lcase(word))


if __name__ == "__main__":
    main()