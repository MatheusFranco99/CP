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

const int maxL = 1e6 + 5;
char a[maxL];

void solve(){
    cin >> a;
    int n = strlen(a);
    vector<int> l(n);
    for (int i = 0; i+3 < n; i++){
        if(i > 0){
            l[i] += l[i-1];
        }
        if(string(a + i, a + i + 4) == "KICK"){
            l[i]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i + 4 < n; i++){
        if(string(a + i, a + i + 5) == "START"){
            ans += l[i];
        }
    }
    cout << ans << endl;
}

void solve2(){
    string a;
    cin >> a;
    vector<int> l;
    for(auto e : a)
        l.pb(int(e));
    int start_pattern = 100*'K' + 10*'I' + 'C';
    int end_pattern = 100*'S' + 10* 'T' + 'A';

    vector<int> token;
    int module = 400;
    rep(i,0,l.size()-2){
        token.pb((l[i]*100 + l[i+1] * 10 + l[i+2])%module);
    }
    int start_module = start_pattern%module;
    int end_module = end_pattern%module;

    vector<int> starts;
    vector<int> ends;
    rep(i,0,token.size()){
        if(start_module == token[i]){
            if((i+3 < l.size()) && (a[i] == 'K') && (a[i+1] == 'I') && (a[i+2] == 'C') + (a[i+3]=='K')){
                starts.pb(i);
            }
        }
        if(end_module == token[i]){
            if((i+4 < l.size()) && (a[i] == 'S') && (a[i+1] == 'T') && (a[i+2] == 'A') + (a[i+3]=='R') && (a[i+4]=='T')){
                ends.pb(i);
            }
        }
    }
    int ans = 0;
    for(auto e : starts){
        for(auto j : ends){
            if(e < j)
                ans++;
        }
    }
    cout << ans << endl;
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