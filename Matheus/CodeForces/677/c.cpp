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
    rep(i,0,n){cin >> a[i];}

    int max = 0;
    rep(i,0,n){
        if(a[max] < a[i]) max = i;
    }
    int r = max+1, l = max-1;
    ll v = a[max];
    while(r < n || l >= 0){
        if(r < n){
            if(a[r] < v) break;
        }
        if(l >= 0){
            if(a[l] < v) break;
        }
        l--;
        r++;
    }
    if(r >= n && l <= -1){
        cout << -1 << endl;
    }
    if(r < n && a[r] < v){cout << r << endl; return;}
    if(l >= 0 && a[l] < v){cout << l+2 << endl; return;}
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