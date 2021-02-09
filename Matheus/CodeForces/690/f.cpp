#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b){ 
    return (a.second < b.second); 
}

void solve(){
    ll n;
    cin >> n;
    pair<ll,ll>p[n];
    ll l[n],r[n];
    rep(i,0,n){
        cin >> p[i].first >> p[i].second;
        l[i] = p[i].first;
        r[i] = p[i].second;
    }

    sort(l,l+n);
    sort(r,r+n);

    ll ans = 1e9+10;
    ll x,y = -1;
    rep(i,0,n){
        x = lower_bound(r,r+n,p[i].first)-r; // take the ones which end before it starts 
        y = l + n -upper_bound(l,l+n,p[i].second); // take the ones which start after it ends

        // cout << "p: " << p[i].first << " " << p[i].second << endl;
        // cout << "number of ones which ends before it starts: " << x << endl;
        // cout << "number of ones which start after it ends: " << y << endl;
        ans = min(ans,x+y);
    }

    cout << ans << endl;

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