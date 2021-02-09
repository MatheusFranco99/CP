#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back



void solve(){
    int n;
    cin >> n;
    vector<int> l(n);
    int a = 0;
    int b = n-1;
    rep(i,0,n){
        cin >> l[i];
    }
    vector<int> ans(n);
    rep(i,0,n){
        if(i%2 == 0){
            ans[i] = l[a];
            a++;
        }
        else{
            ans[i] = l[b];
            b--;
        }
    }
    rep(i,0,n) cout << ans[i] << " ";
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