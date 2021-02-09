#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


/*
    if n = a * b
    then answer of n is
    answer of a + answer of b

    360 - 2 2 90

    360 = 2 * 2 * 2 * 3 * 3 * 5
*/

const ll N = 1e8+1;//1e10+1;

void solve(){
    ll n;
    cin >> n;
    map<ll,int> f;
    while(n%2!=1){
        n = n/2;
        f[2]++;
    }
    for(ll i = 3; i <= sqrt(n); i += 2){
        while(n%i == 0){
            f[i]++;
            n = n/i;
        }
    }
    if(n>1) f[n] = 1;
    // for(auto it: f){
    //     cout << it.first << " " << it.second << endl;
    // }

    int k = 1;
    for(auto it : f) k = max(k,it.second);

    vector<ll> ans(k,1);
    for(auto it: f){
        int i = k-1;
        while(it.second > 0){
            ans[i] *= it.first;
            i--;
            it.second--;
        }
    }
    cout << k << endl;
    for(int i = 0; i< k; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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