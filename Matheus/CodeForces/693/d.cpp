#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORe(i,a,b) for(int i = a; i <= b; i++)
#define FORr(i,a,b) for(int i = a; i > b; i--)
#define FORre(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

void solve(){
    int n;
    cin >> n;
    vector<ll> e;
    vector<ll> o;
    ll aux = 0;
    rep(i,0,n){
        cin >> aux;
        if(aux%2 == 0) e.pb(aux);
        else o.pb(aux);
    }
    sort(e.begin(),e.end());
    sort(o.begin(),o.end());
    ll a = 0;
    ll b = 0;
    int turn = 0; //a
    int ep = e.size()-1;
    int op = o.size()-1;
    rep(i,0,n){
        if(turn == 0){
            if(op < 0){
                a+= e[ep];
                ep--;
            }
            else if(ep < 0){
                op--;
            }
            else if(e[ep] > o[op]){
                a+= e[ep];
                ep--;
            }else{
                op--;
            }
        }
        else{
            if(op < 0){
                ep--;
            }
            else if(ep < 0){
                b += o[op];
                op--;
            }
            else if(o[op] > e[ep]){
                b += o[op];
                op--;
            }
            else{
                ep--;
            }
        }
        turn = (turn+1)%2;
    }
    if(a>b) cout << "Alice" << endl;
    else if(a < b) cout << "Bob" << endl;
    else cout << "Tie" << endl;

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