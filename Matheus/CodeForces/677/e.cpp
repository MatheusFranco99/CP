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
   int n;
   cin >> n;

   if(n == 2){
       cout << 1 << endl;
       return;
   }

    // (combination of n in n/2) / 2 * (n/2!/n/2)^2
   ll ans = factorials[n] / (2 * factorials[n/2] * factorials[n/2]) * pow(factorials[n/2-1],2);
   cout << ans << endl;
   return;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        //cin >> t;
        t = 1;
        prep();
        while(t--){
            solve();
        }
        return 0;
}