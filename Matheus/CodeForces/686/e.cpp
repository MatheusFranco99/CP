#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define forr(i,a,b) for(i = a; i < b; i++)
#define forrRev(i,a,b) for(i = a; i >= b; i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

struct graph{
    ll n;
    vector< vector<int> > E;
    graph(int _n){
        n = _n;
        E.assign(n,vector<int>());
    }
    void add_edge(int f, int t){E[f].pb(t);E[t].pb(f);}
    void print(){
        rep(i,0,n){
            cout <<i<<":";
            for(auto j : E[i]) cout << " " << j;
            cout << endl;
        }
    }
    void getLinks(){
        vector<ll> value(n,1);
        queue<ll> q;
        ll i= 0;
        forr(i,0,n){
            if(E[i].size() == 1) q.push(i);
        }
        while(!q.empty()){
            ll u = q.front();
            q.pop();
            ll v = E[u][0];
            value[v] += value[u];
            value[u] = 0;
            ll location = 0;
            rep(i,0,E[v].size()){
                if(E[v][i] == u){ location = i; break;}
            }
            E[v].erase(E[v].begin() + location);
            E[u].clear();
            if(E[v].size() == 1) q.push(v);
        }
        ll ans = 0;
        forr(i,0,n){
            ans += value[i]*(value[i]-1)/2;
            ans += value[i] * (n - value[i]);
        }
        cout << ans << endl;
    }
};

void solve(){
    int n;
    cin >> n;
    graph g(n);
    int a,b;
    rep(i,0,n){
        cin >> a >> b;
        g.add_edge(a-1,b-1);
    }

    g.getLinks();
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