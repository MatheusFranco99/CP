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

struct graph{
    vector<vector<int> > adj;
    int n;
    graph(int _n){
        n = _n;
        adj.resize(n);
    }
    void addEdge(int u,int v){
        adj[u-1].pb(v-1);
    }
    void print(){
        rep(i,0,n){
            cout << i << ": ";
            for(auto e: adj[i]) cout << e << " ";
            cout << endl;
        }
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    int u,v;
    graph g(n);
    rep(i,0,m){
        cin >> u >> v;
        g.addEdge(u,v);
    }
    g.print();
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