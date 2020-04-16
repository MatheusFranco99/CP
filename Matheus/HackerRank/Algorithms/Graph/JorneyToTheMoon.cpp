#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <bits/stdc++.h>
#include <bitset>
#define ll long long

using namespace std;

vector<list<ll>> graph;
vector<bool> visited;
vector <int> occurrences;

int DFS(ll i){
    visited[i]=true;
    ll sum = 1;
    for(auto j: graph[i])
        if(!visited[j])
            sum+= DFS(j);
    return sum;
}
int main(){
    ll n,e,u,v;
    cin>>n>>e;
    graph.resize(n);
    occurrences.resize(n);
    visited.resize(n,false);
    vector<int> M;
    while(e--){
        cin>>u>>v;
        graph[u].push_front(v); graph[v].push_front(u);
    }
    ll vertices = 0;
    for(long long i=0;i<n;i++){
        if(!visited[i]){
            occurrences[i] = DFS(i);
        }
    }
    ll ans = 0;
    for(ll i = 0; i < n-1; i++){
        ans += occurrences[i]*occurrences[i+1];
        occurrences[i+1]+=occurrences[i];
    }
    cout<<ans<<"\n";
    return 0;
}