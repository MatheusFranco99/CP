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


template<class T> void sort_unique(vector<T> &v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    sort(a.begin(),a.end());

    vector<int> v;
    rep(i,0,n){
        for(int k = 1; k * k <= a[i]; k++){
            if(a[i]%k == 0){
                if(k<=a[0]) v.pb(k);
                if(a[i]/k <= a[0]) v.pb(a[i]/k);
            }
        }
    }
    sort_unique(v);

    ll ans = 0;

    int len = v.size();
    rep(i,0,len){
        int factor = v[i];
        int g = 0;
        rep(j,0,n) if(a[j]%factor == 0) g = __gcd(g,a[j]);
        if(g == factor) ans++;
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