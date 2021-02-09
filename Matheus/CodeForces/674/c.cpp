#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORe(i,a,b) for(int i=a;i<=b;i++)
#define FORr(i,a,b) for(int i=a;i>b;i--)
#define FORre(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

/*

42:
1 -> 42/1 - 1 -> necessários 41 (+ 0)
2 -> 42/2 - 1 -> necessários 20 (+ 1)
3 -> 42/3 - 1 -> necessários 13 (+ 2)
4 -> 42/4 - 1 -> necessários 10 (+ 3)
5 -> 42/5 - 1 -> necessários 8  (+ 4)
6 -> 42/6 - 1 -> necessários 6  (+ 5)
7 -> 42/7 - 1 -> necessários 5  (+ 6)
8 -> 42/8 - 1 -> necessários 5  (+ 7)

n:
minimum between
n-1, n/2 + 1, 2 + n/3,

*/

void solve(){
   ll n;
   cin >> n;
   ll sum = 1;
   int minimum_steps = n-1;
   int next = 0;
   int i = 2;
   while(1){
       if(i > n) break;
       if(n%i == 0){
           next = i-1 + n/i-1;
       }
       else{
           next = i-1 + (n/i)+1-1;
       }
       if(next < minimum_steps) minimum_steps = next;
       if(next > minimum_steps) break;
       i++;
   }
   cout << minimum_steps << endl;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
}