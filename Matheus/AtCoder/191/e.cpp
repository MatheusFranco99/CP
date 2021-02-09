#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORe(i,a,b) for(int i=a;i<=b;i++)
#define FORr(i,a,b) for(int i=a;i>b;i--)
#define FORre(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const ll inf = 1e9+10;

template <typename T>
struct graph{
    int n;
    vector<vector<pair<int,T> > > adj;
    graph(int nn){
        n = nn;
        adj = vector<vector<pair<int,T> > >(n);
    }
    void addEdge(int from, int to,T c){adj[from].pb(pair<int,T>(to,c));}
    void print(){
        rep(i,0,n){
            cout << i << ": ";
            for(auto a : adj[i]) cout << a.first << "(c:" << a.second << ")" << ", ";
            cout << endl;
        }
    }
    void dijkstra(int source){
        vector<int> visited(n,0);
        vector<T> ans(n,inf);
        priority_queue<pair<T,int>, vector<pair<T,int> >, greater<pair<T,int> > > q;

        rep(j,0,n) visited[j] = 0;

        q.push(pair<int,T>(0,source));
        while(!q.empty()){
            pair<int,T> p = q.top();
            q.pop();
            if(visited[p.second]) continue;
            visited[p.second] = 1;
            ans[p.second] = p.first;
            for(auto a : adj[p.second]){
                if(visited[a.first] == 0){
                    q.push(pair<int,T>(p.first+a.second,a.first));
                }
            }
        }
        rep(i,0,n){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    void dijkstraAll(vector<int> &preanswer){
        vector<vector<T> > ans(n,vector<T>(n,inf));
        rep(source,0,n){
            vector<int> visited(n,0);
            priority_queue<pair<T,int>, vector<pair<T,int> >, greater<pair<T,int> > > q;
            rep(j,0,n) visited[j] = 0;

            q.push(pair<int,T>(0,source));

            while(!q.empty()){
                pair<int,T> p = q.top();
                q.pop();
                if(visited[p.second]){
                    continue;
                }
                visited[p.second] = 1;
                ans[source][p.second] = p.first;
                for(auto a : adj[p.second]){
                    if(visited[a.first] == 0){
                        q.push(pair<int,T>(p.first+a.second,a.first));
                    }
                }
            }
        }
        // rep(i,0,n){
        //     rep(j,0,n) cout << ans[i][j] << " ";
        //     cout << endl;
        // }
        rep(i,0,n){
            T minimum = inf;
            rep(j,0,preanswer.size()){
                if(preanswer[j] == i){
                    for(auto a: adj[i]){
                        if(a.first == i) minimum = std::min(minimum,a.second);
                    }
                }
            }
            rep(j,0,n){
                if(i == j) continue;
                minimum = std::min(minimum, ans[i][j] + ans[j][i]);
            }
            if(minimum == inf) cout << "-1" << endl;
            else cout << minimum << endl;
        }
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    int a,b,c;
    vector<vector<pair<int,int> > > adj(n);
    graph<int> g(n);
    vector<int> preanswer;
    rep(i,0,m){
        cin >> a >> b >> c;
        g.addEdge(a-1,b-1,c);
        if(a == b){
            preanswer.pb(a-1);
        }
    }
    // g.print();

    g.dijkstraAll(preanswer);

}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        t = 1;
        while(t--){
            solve();
        }
        return 0;
}