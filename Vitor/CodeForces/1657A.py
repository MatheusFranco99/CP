
"""
5   .   .   .   .   .   .

4   .   .   .   .   .   .

3   .   .   .   .   .   .

2   .   .   .   .   .   .

1   .   .   .   .   .   .

0   .   .   .   .   .   .   
    
    0   1   2   3   4   5

0,1 -> 1
1,0 -> 1
1,1 -> 2
0,2 -> 1
1,2 -> 2
2,2 -> 2

"""

import math as m


def solve(x,y):
    d = (x**2 + y**2)**(1/2)
    if x == 0 and y == 0:
        print(0)
        return
    if d - m.floor(d) == 0:
        print(1)
    else:
        print(2)

        
def main():
    t = int(input())
    while t > 0:
        
        x,y = map(int,input().split())

        solve(x,y)

        t-=1


if __name__ == '__main__':
    main()