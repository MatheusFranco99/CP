num = int(input())

verbose = False

n = 1
while True:

    Tn = (n * (n + 1))//2

    if verbose:
        print(f"{n=},{Tn=},{num=},{num==Tn=}")

    if num == Tn:
        print("YES")
        break
    else:
        n+=1

    if verbose:
        print(f"{n > Tn=}")
        
    if Tn > num:
        print("NO")
        break









"""


65

80
9

65 * 2 = n * (n + 1)

130 = n * ( n + 1 )

110, 132, 12*13


300 = n * (n+1)/2



"""