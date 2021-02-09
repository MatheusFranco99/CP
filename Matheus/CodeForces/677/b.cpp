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

    int a[n+1];
    FORe(i,1,n){
        a[i] = 0;
        cin >> a[i];
    }

    int ans = 0;
    int l = 0;
    int r = 0;
    FORe(i,1,n){
        if(a[i] == 1){
            l = i;
            break;
        }
    }
    FORre(i,n,1){
        if(a[i] == 1){
            r = i;
            break;
        }
    }
    while(l != r){
        l++;
        if(a[l] == 0) ans++;
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