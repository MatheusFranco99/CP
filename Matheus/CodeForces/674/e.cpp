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

void solve(){
    int64_t n;
    cin >> n;
    
    vector<int64_t> A(3),B(3);
    rep(i,0,3) cin >> A[i];
    rep(i,0,3) cin >> B[i];

    int64_t maximum = min(A[0],B[1]) + min(A[1],B[2]) + min(A[2],B[0]);

    int64_t minimum = n - (min(A[1],B[0] + B[1]) + min(A[2],B[1]+B[2]) + min(A[0],B[2]+B[0]));

    cout << minimum << " " << maximum << endl;
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