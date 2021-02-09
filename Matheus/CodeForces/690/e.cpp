#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


ll mod = 1000000007;

const int MAX = 200005;

ll f[200005],inv[200005];

ll powInv(ll b,ll p){
    if(p==0) return 1;
    ll h = powInv(b,p/2);
    ll r = h*h%mod;
    if(p%2) r = r*b%mod;
    return r;
}

void solve2(){
    ll n,m,k;
    cin >> n>>m>>k;
    ll a[n];

    rep(i,0,n){
        cin >> a[i];
    }
    sort(a,a+n);
    ull ans = 0;
    ll mini = n-2;
    ll maxi = n-1;
    ull inc = 0;

    while(maxi >= m-1){
        while(mini >= 0 && a[maxi] - a[mini] <= k) mini--;
        mini++;
        
        
        // 2combination of set maxi-1, maxi-2,...,mini (# = maxi-mini)
        if(maxi-mini >= m-1){
            ll inc = f[maxi-mini]*inv[m-1]%mod*inv[maxi-mini - m + 1]%mod;
            ans = (ans + inc)%mod;
        }
        //cout << imie(maxi) << imie(a[maxi]) << imie(mini) << imie(a[mini]) << imie(inc) << endl;
        
        maxi--;
    }
    cout << ans << endl;
}
int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);

        f[0] = 1, inv[0] = 1;
        for(ll i = 1; i < MAX; i++){
            f[i] = (f[i-1]*i)%mod;
        }
        for(ll i = 1; i < MAX; i++){
            inv[i] = powInv(f[i],mod-2);
        }
        ll t;
        cin >> t;
        while(t--){
            solve2();
        }
        return 0;
}