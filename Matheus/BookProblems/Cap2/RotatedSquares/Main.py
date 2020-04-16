
def main():
        while(True):
                [N,n]=input().split(" ")
                N = int(N)
                n = int(n)
                if N == 0 and n == 0:
                        break
                data = []
                for i in range(N):
                        data += [[]]
                        line = input()
                        for j in range(N):
                                data[i] += [line[j]]
                match = []
                for i in range(n):
                        match += [[]]
                        line = input()
                        for j in range(n):
                                match[i] += [line[j]]
                answer = [0,0,0,0]
                for i in range(4):
                        for j in range(N):
                                if j+n >= N:
                                        break
                                else:
                                        for k in range(N):
                                                if(k+n<=N):
                                                        if(match==data[j:j+n][k:k+n]):
                                                                answer[i]+=1
                                                else:
                                                        break
                print(answer[0],answer[1],answer[2],answer[3])

main()