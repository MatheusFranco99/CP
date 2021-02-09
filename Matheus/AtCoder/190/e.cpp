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

const ll inf = 1e9+7;

unsigned int countSetBits(unsigned int n){
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

struct graph{
    int n;
    vector<vector<int> > adj;
    graph(int nn){
        n = nn;
        adj = vector<vector<int> >(n);
    }
    void addEdge(int from, int to){adj[from].pb(to);}
    void print(){
        rep(i,0,n){
            cout << i << ": ";
            for(auto a : adj[i]) cout << a << ", ";
            cout << endl;
        }
    }
    ll findPath(vector<int> &c){
        vector<vector<int> > bfss(c.size(),vector<int>(n,inf));
        for(int i = 0; i < c.size(); i++){
            int source = c[i];
            queue<pair<ll,int> > q;
            q.push(pair<ll,int>(0,source));
            vector<int> visited(n,0);
            visited[c[i]] = 1;
            while(!q.empty()){
                pair<ll,int> p = q.front();
                q.pop();
                bfss[i][p.second] = p.first;
                for(auto a : adj[p.second]){
                    if(!visited[a]){
                        q.push(pair<ll,int>(p.first + 1,a));
                        visited[a] = 1;
                    }
                }
            }
        }
        // rep(i,0,c.size()){
        //     cout << c[i] << endl;
        //     rep(j,0,n){
        //         cout << bfss[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<vector<int> > subg(c.size(),vector<int> (c.size(),0));
        rep(i,0,c.size()){
            rep(j,0,c.size()){
                if(bfss[i][c[j]] == inf) return -1;
                subg[i][j] = bfss[i][c[j]];
            }
        }
        // rep(i,0,c.size()){
        //     cout << i << endl;
        //     rep(j,0,c.size()){
        //         cout << subg[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // return 0;

        // vector<vector<int> > dp(c.size(),vector<int> (c.size(),1));
        vector<int> dp((1<<c.size()),inf);
        dp[0] = 0;
        for(int mask = 0; mask < (1<<c.size()); mask++){
            int x = countSetBits(mask);
            for(int j = 0; j < c.size(); j++){
                if(mask&(1<<j) == 0){
                    dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask]+subg[j][x]);
                }
            }
        }
        return dp[(1<<c.size())-1];

        // vector<vector<int> > dp(c.size(),vector<int> (c.size(),0));
        // for(int i = 0; i < c.size(); i++){
        //     vector<int> visited(c.size(),0);
        //     queue<ll,int> q;
        //     q.push(pair<ll,int>(0,i));
        //     visited[i] = 1;
        //     while(!q.empty()){
        //         pair<ll,int> p = q.front();
        //         q.pop();
        //         for(auto a: bfss[p.second]){
        //             if(!visited[a]){
        //                 q.push(pair<ll,int> (p.first+bfss[p.second][a],a));
        //                 visited[a] = 1;
        //             }
        //         }
        //     }
        // }

    }
    ll findPath2(vector<int> &c){
        int i = 0;
        int len = c.size();
        ll ans = 0;
        vector<int> visited(n,0);
        queue<pair<int,int> > q;
        int found = 0;
        while(i < len){
            if(i == len-1) break;
            cout << "Position: " << c[i] << endl;

            // find minimum path from c[i] to c[i+1]
            rep(j,0,n) visited[j] = 0;
            queue<pair<int,int> > q;

            visited[c[i]] = 1;
            q.push(pair<int,int>(c[i],0));
            found = 0;
            while(!q.empty()){
                pair<int,int> p = q.front();
                q.pop();
                for(auto a : adj[p.first]){
                    if(a == c[i+1]){
                        ans += p.second+1;
                        found = 1;
                        break;
                    }
                    else{
                        if(!visited[a]){
                            q.push(pair<int,int>(a,p.second+1));
                            visited[a] = 1;
                        }
                    }
                }
                if(found){
                    break;
                }
            }
            if(found) i++;
            else return -1;
        }
        return ans+1;
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    graph g(n);
    int ax1,ax2;
    rep(i,0,m){
        cin >> ax1 >> ax2;
        ax1--;
        ax2--;
        g.addEdge(ax1,ax2);
        g.addEdge(ax2,ax1);
    }
    int k; cin >> k;
    vector<int> c(k);
    rep(i,0,k) cin >> c[i];
    rep(i,0,k) c[i]--;
    // g.print();
    // rep(i,0,k) cout << c[i] << " "; cout << endl;
    ll ans = g.findPath(c);
    cout << ans << endl;
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