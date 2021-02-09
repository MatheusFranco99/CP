#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forrRev(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

void solve(){
    ll w,h,n;
    cin >> w >> h >> n;

    int maxN = 1;
    while(w%2 == 0){
        maxN*=2;
        w = w/2;
    }
    while(h%2 == 0){
        maxN*=2;
        h = h/2;
    }
    if(maxN >= n) cout << "YES\n";
    else cout << "NO\n";
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