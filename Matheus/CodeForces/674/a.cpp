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

vector<ll> factorials(21);

void prep(){
    factorials[0] = 1;
    factorials[1] = 1;
    rep(i,2,21) factorials[i] = i*factorials[i-1];
}

void solve(){
   int n, x;
   cin >> n >> x;
   if(n <= 2){ cout << 1 << endl; return;}
   n = n - 2-1;
   int d = n/x;
   cout << d+2 << endl;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        cin >> t;
        prep();
        while(t--){
            solve();
        }
        return 0;
}