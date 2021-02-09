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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> g1,g2;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n){
        if(a[i] == a[0]) g1.pb(i);
        else g2.pb(i);
    }
    if(g2.size() == 0){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(auto b : g2){
        cout << g1[0]+1 << " " << b+1 << endl;
    }
    rep(i,1,g1.size()){
        cout << g1[i]+1 << " " << g2[0]+1 << endl;
    }
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