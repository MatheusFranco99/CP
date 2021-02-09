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

void solve2(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    int ans = 0;
    int solved = 0;
    int last_placement = -1;
    int j = 0;
    ll sum = 0;
    while(solved < n){
        solved++;
        sum = a[solved];
        for(j = solved-1; j > last_placement; j--){
            sum = sum + a[j];
            if(sum == 0){
                last_placement = solved-1;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}


void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    vector<int64_t> prefix_sums(n+1,0);
    rep(i,0,n) prefix_sums[i+1] = prefix_sums[i] + a[i];
    
    set<int64_t> current;
    int changes = 0;
    rep(i,0,n+1){
        if(!current.insert(prefix_sums[i]).second){ // sum already exists in set
            changes++;
            current.clear();
            current.insert(prefix_sums[i-1]);
            current.insert(prefix_sums[i]);
        }
    }
    cout << changes << endl;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        // cin >> t;

        t = 1;
        while(t--){
            solve();
        }
        return 0;
}