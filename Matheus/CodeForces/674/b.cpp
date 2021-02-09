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

struct matrix{
    int a,b,c,d;

    matrix(int a_, int b_, int c_, int d_){a = a_; b = b_; c = c_; d = d_;}
};

void solve(){
   int n, m;
   cin >> n >> m;
    int a,b,c,d;
    int flag = 0;
    rep(i,0,n){
        cin >> a >> b >> c >> d;
        if(b == c) flag = 1;
    }
    if(m&1 == 1){cout << "NO\n"; return;}
    if(flag) cout << "YES\n";
    else cout << "NO\n";
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