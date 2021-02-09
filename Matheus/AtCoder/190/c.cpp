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

/*
go through conditions, if impossible take out
go through people
*/

int ans = 0;

int check(vector<pair<int,int> >&c, vector<int>&d){
    int possible_ans = 0;
    for(auto a: c){
        if(d[a.first]>0 && d[a.second]>0) possible_ans++;
    }
    return possible_ans;
}

void ok(int i, vector<pair<int,int> >&c, vector<pair<int,int> >&p, vector<int>&d){
    if(i == p.size()){
        ans = max(ans,check(c,d));
    }
    else{
        d[p[i].first]++;
        ok(i+1,c,p,d);
        d[p[i].first]--;
        d[p[i].second]++;
        ok(i+1,c,p,d);
        d[p[i].second]--;
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> d(n,0);
    vector<vector<int> > cond(n);
    vector<pair<int,int> >c(m);
    int aux1,aux2;
    rep(i,0,m){
        cin >> aux1 >> aux2;
        aux1--;aux2--;
        cond[aux1].pb(i);
        cond[aux2].pb(i);
        c[i] = pair<int,int> (aux1,aux2);
    }
    vector<pair<int,int> >p;
    int k; cin >> k;
    rep(i,0,k){ // take people and if no condition on one of them simply take out
        cin >> aux1 >> aux2;
        aux1--; aux2--;
        if(cond[aux1].empty()) d[aux2]++;
        else if(cond[aux2].empty()) d[aux1]++;
        else{
            p.pb(pair<int,int> (aux1,aux2));
        }
    }

    // rep(i,0,n) cout << d[i] << " "; cout << endl;
    // rep(i,0,m) cout << c[i].first << " " << c[i].second << "; "; cout << endl;
    // rep(i,0,p.size()) cout << p[i].first << " " << p[i].second << "; "; cout << endl;

    ok(0,c,p,d);
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