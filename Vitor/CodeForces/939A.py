
def solve(lst):
    # n elementos
    # lst[i] esta no intervalo (0,n-1)


    for i in lst:
        if is_in_triangle(lst, i):
            print("YES")
            return
    
    print("NO")


def is_in_triangle(lst,i):
    j = lst[i]
    z = lst[j]
    w = lst[z]
    return w == i

def main():
    n = int(input())
    lst = [v-1 for v in list(map(int,input().split()))]
    solve(lst)


if __name__ == '__main__':
    main()
