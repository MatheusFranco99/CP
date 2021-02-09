#include <bits/stdc++.h>
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
    int n,k;
    cin >> n >> k;
    vector<int> idx;
    vector<int> S;
    vector<int> E;
    int i, s, e;
    rep(i,0,n){
        cin >> s >> e;
        idx.pb(i); S.pb(s); E.pb(e);
    }
    stable_sort(idx.begin(),idx.end(),[&S](int i, int j){return S[i] < S[j];});

    int expiration = 0;
    int num_deploy = 0;
    int iterator = 0;
    int delta = 0;
    int aux = 0;
    for(auto t : idx){
        if(expiration < S[t]){
            expiration = S[t];
        }
        if(expiration < E[t]){
            delta = E[t] - expiration;
            aux = delta/k;
            if(delta%k != 0){
                aux++;
            }
            expiration += k * aux;
            num_deploy += aux;
        }
    }
    cout << num_deploy << endl;
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