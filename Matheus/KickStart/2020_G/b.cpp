#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

/*

Thinking:

*/

void solve(){

    ll n = 0;
    cin >> n;
    vector<ll> lst(n + n-1);
    ll aux = 0;
    rep(i,0,n){
        rep(j,0,n){
            cin >> aux;
            lst[(i-j) + n-1] += aux;
        }
    }
    ll max = lst[0];
    rep(i,1,n+n-1){
        if(lst[i] > max){
            max = lst[i];
        }
    }
    cout << max << endl;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t,x;
        cin >> t;
        x = 1;
        while(x <= t){
            cout << "Case #" << x << ": ";
            solve();
            x++;
        }
        return 0;
}