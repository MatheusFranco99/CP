#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

ll g(ll a, ll b){
    if(b > a) return g(b,a);
    while(b != 0){
        ll t = b;
        b = a%b;
        a = t;
    }
    return a;
}

void solve(){
    int n,m;
    cin >> n>>m;
    ll a[n];
    ll b = 0;
    rep(i,0,n) cin >> a[i];
    sort(a,a+n);
    if(n == 1){
        rep(i,0,m){
            cin >> b;
            cout << a[0]+b << endl;
        }
        return;
    }
    ll g = a[1]-a[0];
    rep(i,2,n){
        g = __gcd(g,a[i]-a[0]);
    }
    rep(i,0,m){
        cin >> b;
        cout << abs(__gcd(g,b+a[0])) << " ";
    }
    cout << endl;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
            solve();
        return 0;
}