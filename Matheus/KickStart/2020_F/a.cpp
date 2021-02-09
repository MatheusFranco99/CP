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
    int n, x;
    vector<int> l;
    vector<int> idx;
    cin >> n >> x;
    int i,aux;
    rep(i,0,n){
        cin >> aux;
        l.pb(aux);
        idx.pb(i+1);
    }
    rep(i,0,n){
        if(l[i]%x == 0){
            l[i] = l[i]/x;
        }
        else{
            l[i] = l[i]/x + 1;
        }
    }
    stable_sort(idx.begin(), idx.end(),[&l](int i1,int i2) {return l[i1-1] < l[i2-1];});
    for(auto c : idx){
        cout << c << " ";
    }
    cout << endl;
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