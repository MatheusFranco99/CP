#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORe(i,a,b) for(int i=a;i<=b;i++)
#define FORr(i,a,b) for(int i=a;i>b;i--)
#define FORre(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

ll sq(ll x){ return x * x;}

void solve(){
    long double a;
    cin >> a;    ll x = llround(a*10000);
    cin >> a;    ll y = llround(a*10000);
    cin >> a;    ll r = llround(a*10000);

    ll r2 = sq(r);
    ll pos = x - r;
    ll high = y+1;
    ll low = y-1;
    while(pos%10000) pos++;
    while(high%10000) high++;
    while(low%10000) low--;

    ll ans = 0;

    for(;pos <= x + r; pos+=10000){
        ll xdif = sq(pos-x);

        while(high >= y && xdif + sq(high - y) > r2) high -= 10000;
        while(high <= y || xdif + sq(high-y) <= r2) high += 10000;

        while(low <= y && xdif + sq(y-low) > r2) low+= 10000;
        while(low >= y || xdif+sq(y-low) <= r2) low-=10000;

        ll inc = (high-low)/10000 -1;
        if(inc > 0) ans += inc;
    }
    cout << ans << endl;

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
// 500002.45 600007.34 100333.50