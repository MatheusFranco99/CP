#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORe(i,a,b) for(int i = a; i <= b; i++)
#define FORr(i,a,b) for(int i = a; i > b; i--)
#define FORre(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

void solve(){
    int n;
    cin >> n;
    ll a[n];
    rep(i,0,n) cin >> a[i];
    ll scores[n];
    scores[n-1] = a[n-1];
    ll place = 0;
    FORre(i,n-2,0){
        scores[i] = a[i];
        place = i + a[i];
        if(place < n) scores[i] += scores[place];
    }
    ll maxx = scores[0];
    rep(i,1,n) if(maxx < scores[i]) maxx = scores[i];
    cout << maxx << endl;
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