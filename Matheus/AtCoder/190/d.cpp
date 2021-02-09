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

/*
a + a+1 + a+2 + ... + a+k = (k+1) * a + (k+1) * k/2 = (k+1) * (a+k/2) = (k+1) * (2a+k) / 2

a + a+1 + a+2 + ... + a+k-1 = (k) * a + (k-1) * k/2 = (k) * (a+(k-1)/2) = (k) * (2a+k-1) / 2 = N

2 * N = (k) * (2a+k-1)
*/

void solve2(){
    int64_t n; cin >> n;
    int ans = 0;
    int k = 0;
    int n2 = 2 * n;
    while(k+1 <= n2){
        if(n2%(k+1) == 0){
            if((n2/(k+1)-k)%2 == 0) ans++;
        }
        k++;
    }
    cout << ans << endl;
}

void solve(){
    int64_t n; cin >> n;
    int64_t a = 1;
    int64_t n2 = 2*n;
    int64_t ans = 0;
    while(a*a <= n2){
        if(n2%a == 0){
            if((n2/a-(a-1))%2 == 0) ans++;
            int64_t k = n2/a;
            if((n2/k - (k-1))%2 == 0) ans++;
        }
        a++;
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