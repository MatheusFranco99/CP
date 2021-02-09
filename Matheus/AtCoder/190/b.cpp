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

void solve(){
    ll n,s,d;
    ll x,y;
    cin >> n >> s >> d;
    int flag = 0;
    rep(i,0,n){
        cin >> x >> y;
        if(x < s && y > d) flag = 1;
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        t = 1;
        while(t--){
            solve();
        }
        return 0;
}