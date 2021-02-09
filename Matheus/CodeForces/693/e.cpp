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

const ll INF = 1e9+10;

struct person{
    ll h,w;
    int index;
    bool operator<(const person &other) const{
        return h < other.h; 
    }
};

void solve(){
    int n;
    cin >> n;
    vector<person> l(n);
    ll min = INF;
    rep(i,0,n){
        cin >> l[i].h >> l[i].w;
        if(l[i].h > l[i].w) swap(l[i].h,l[i].w);
        l[i].index = i;
    }
    sort(l.begin(),l.end());
    
    vector<int> ans(n);
    rep(i,0,n) ans[i] = -1;

    int min_w_index = -1;

    for(int i = 0, j = 0; i < n; i = j){
        while(j < n && l[j].h == l[i].h) j++;
        if(min_w_index >= 0){
            rep(k,i,j){
                if(l[min_w_index].w < l[k].w) ans[l[k].index] = l[min_w_index].index+1;
            }
        }
        rep(k,i,j){
            if(min_w_index < 0 || l[min_w_index].w > l[k].w) min_w_index = k;
        }
    }

    rep(i,0,n) cout << ans[i] << " ";
    cout << endl;
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