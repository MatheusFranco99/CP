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



void solve(){
    ll a,b,x,y,n; cin >> a >> b >> x >> y >> n;
    ll ans1 = (a-n)*b, ans2 = (b-n)*a;
    if(a-n < x){ ans1 = x * (b-(n - (a-x)));}
    if(b-n < y) ans2 = y * (a - (n - (b - y)));
    ans1 = max(ans1,x*y);
    ans2 = max(ans2,x*y);
    cout << min(ans1,ans2) << endl;
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