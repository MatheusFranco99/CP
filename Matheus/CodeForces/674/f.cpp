#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORe(i,a,b) for(int i=a;i<=b;i++)
#define FORr(i,a,b) for(int i=a;i>b;i--)
#define FORre(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

ull mod = 1e9 + 7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<ull> p3(n+1,1);
    rep(i,0,n) p3[i+1] = (3 * p3[i])%mod;

    vector<ull> q(n,0);
    vector<ull> sq(n,0);
    vector<ull> a(n,0);
    vector<ull> c(n,0);

    rep(i,1,n){
        q[i] = q[i-1] + (s[i-1] == '?');
    }
    FORre(i,n-2,0){
        sq[i] = sq[i+1] + (s[i+1]=='?');
    }

    rep(i,1,n){
        if(s[i-1] == 'a'){
            a[i]+= (a[i-1] + p3[q[i-1]])%mod;
        }
        else if(s[i-1] == '?'){
            a[i] = ((a[i-1] * 3)%mod + p3[q[i-1]])%mod;
        }
        else a[i] = a[i-1];
    }
    FORre(i,n-2,0){
        if(s[i+1] == 'c'){
            c[i] += (c[i+1] + p3[sq[i+1]])%mod;
        }
        else if(s[i+1] == '?'){
            c[i] = ((c[i+1] * 3)%mod + p3[sq[i+1]])%mod;
        }
        else c[i] = c[i+1];
    }
    ll ans = 0;
    rep(i,0,n){
        if(s[i] == 'b' || s[i] == '?'){
            ans = (ans + (a[i] * c[i]) % mod) % mod;
        }
    }
    cout << ans << endl;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        // cin >> t;

        t = 1;
        while(t--){
            solve();
        }
        return 0;
}