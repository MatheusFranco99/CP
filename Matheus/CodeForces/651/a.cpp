#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)

/*

Thinking:


    if j | n, then j <= n/2, so for all j > n/2, j only divides j
    if j is even, then the answer is j/2
    else the answer is (n-1)/2

*/


void solve(){
    int n;
    cin >> n;
    int ans = 0;
    if(n%2 == 0){
        ans = n/2;
    }
    else{
        ans = (n-1)/2;
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