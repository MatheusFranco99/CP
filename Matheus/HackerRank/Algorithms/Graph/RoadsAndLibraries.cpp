#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;

vector <list<int>> g;
vector <bool> visited;

ll DFS(ll i){
        visited[i] = true;
        ll ans = 1;
        for(auto j : g[i]){
                if(!visited[j]){
                        ans+= DFS(j);
                }
        }
        return ans;
}

int main(){
        ll q,n,m,clib,croad,u,v;
        cin >> q;
        while(q--){
                cin >> n >> m >> clib >> croad;
                g.clear();
                visited.clear();
                g.resize(n);
                visited.resize(n);
                while(m--){
                        cin >> u >> v;
                        --u;
                        --v;
                        g[u].push_front(v);
                        g[v].push_front(u);
                }
                ll ans = 0;
                if(clib <= croad){
                        ans = n*clib;
                        cout << ans << "\n";
                        continue;
                }
                for(ll i = 0; i < n; i++){
                        if(visited[i]==false){
                                ans += clib;
                                ans += croad * (DFS(i)-1);
                        }
                }
                cout << ans << "\n";
        }
        return 0;
}
