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

const ll inf = 1e9+7;

void solve(){
    int n,k; cin >> n >> k;
    vector<int> x(n);
    rep(i,0,n) cin >> x[i];
    int y;
    rep(i,0,n) cin >> y;
    sort(x.begin(),x.end());
    vector<int>suffix(n+1,0);
    int best = 0;
    for(int i = n-1, j = n; i >= 0; i--){
        while(j > i && x[j-1] > x[i] + k) j--;
        best = max(best,j-i + suffix[j]);
        suffix[i] = max(j-i,suffix[i+1]);
    }
    cout << best << endl;
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