

def main():
    list = [1, 1, 3, 5]

    t = int(input())

    for tt in range(t):

        n = int(input())

        list = input().split() #['1','1','3','5']
        for i,v in enumerate(list):
            list[i] = int(v)


        list.sort(reverse=True)

        for i in range(len(list)):
            if i < len(list) - 1:
                print(list[i], end=" ")
        print(list[-1])


if __name__ == "__main__":
    main()