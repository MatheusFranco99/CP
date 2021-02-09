
class graph:
    def __init__(self,nn):
        self.n = nn
        self.e = []
        for i in range(self.n):
            self.e += [[]]
    
    def addEdge(self,f,to):
        self.e[f] += [to]
        self.e[to] += [f]
    
    def dfss(self,v,visiteds):
        ans = 0
        visiteds += [v]
        print("v,visiteds:",v,visiteds)
        print("e[v]:",self.e[v])
        for i in range(len(self.e[v])):
            if(self.e[v][i] not in visiteds):
                ans = ans + 1
        
        for i in range(len(self.e[v])):
            if(self.e[v][i] not in visiteds):
                ans = ans + 2 * self.dfss(self.e[v][i],visiteds.copy())
        print("ans:",ans)
        return ans

    def findCycles(self):
        ans = self.dfss(0,[])
        print(ans)

def solve():
    n = int(input())
    g = graph(n)
    for i in range(n):
        a,b = input().split()
        a = int(a)
        b = int(b)
        g.addEdge(a-1,b-1)
    
    g.findCycles()

def main():
    t = int(input())
    for i in range(t):
        solve()
    return 0

main()