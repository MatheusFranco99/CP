#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORe(i,a,b) for(int i=a;i<=b;i++)
#define FORr(i,a,b) for(int i=a;i>b;i--)
#define FORre(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int inf = 1e9 + 5;

struct triple{
    int first,second,third;
    triple(int x1,int x2,int x3){
        first = x1;
        second = x2;
        third = x3;
    }
    bool operator<(const triple &other) const {
            return first > other.first;
    }
 
};

struct graph{
    int n;
    vector< vector<pair<int,int> > > adj;
    vector<vector<ll> > sp;
    vector<vector<int> > pred;
    graph(int size){
        n = size;
        adj.resize(n);
        sp.resize(n);
        rep(i,0,n){sp[i].resize(n);rep(j,0,n){sp[i][j] = inf;}sp[i][i] = 0;}
        pred.resize(n);
        rep(i,0,n){pred[i].resize(n);rep(j,0,n){pred[i][j] = -1;}pred[i][i] = i;}
    }
    void addEdge(int to, int from, int w){
        adj[to].pb(pair<int,int>(from,w));
    }
    void updateSP(int a){
        priority_queue<triple> pq;
        pq.push(triple(0,a,a));
        triple node(0,0,0);
        while(!pq.empty()){
            node = pq.top();
            pq.pop();
            if(sp[a][node.second] < node.first){continue;}
            sp[a][node.second] = node.first;
            pred[node.second][a] = node.third;
            for(auto neighbor : adj[node.second]){
                if(node.first + neighbor.second < sp[a][neighbor.first]){
                    pq.push(triple(node.first + neighbor.second,neighbor.first,node.second) );
                }
            }
        }
    }
    ll getOptimalCost(vector<pair<int,int> >&p){
        ll ans = 0;
        for(auto a : p) ans += sp[a.first][a.second];
        rep(i,0,n){
            for(auto edge : adj[i]){
                if(edge.first > i){
                    // test
                    ll possible_ans = 0;
                    ll factor = 0;
                    for(auto a : p){
                        factor = min(sp[a.first][a.second], sp[a.first][i] + sp[edge.first][a.second]);
                        factor = min(factor, sp[a.first][edge.first] + sp[i][a.second]);
                        possible_ans += factor;
                    }
                    if(possible_ans < ans) ans = possible_ans;
                }
            }
        }
        return ans;
    }
    void printG(){
        rep(i,0,n){
            cout << i << ": ";
            for(auto a : adj[i]){
                cout << "(" << a.first << " " << a.second << "),";
            }
            cout << endl;
        }
    }
    void printSP(){
        rep(i,0,n){
            rep(j,0,n){
                cout << sp[i][j] << " ";
            }
            cout << endl;
        }
    }
    void printPRED(){
        rep(i,0,n){
            rep(j,0,n){
                cout << pred[i][j] << " ";
            }
            cout << endl;
        }
    }
};

void solve(){
    ll n,m,k;
    cin >> n >> m >> k;
    graph g(n);
    int x,y,w;
    rep(i,0,m){
        cin >> x >> y >> w;
        g.addEdge(x-1,y-1,w);
        g.addEdge(y-1,x-1,w);
    }

    vector<pair<int,int> > p(k);
    rep(i,0,k){
        cin >> p[i].first >> p[i].second;
        p[i].first--;
        p[i].second--;
    }
    // g.printG();
    rep(i,0,n){g.updateSP(i);}
    ll ans = g.getOptimalCost(p);
    cout << ans << endl;
    // g.printSP();
    // g.printPRED();
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        //cin >> t;
        t = 1;
        //prep();
        while(t--){
            solve();
        }
        return 0;
}