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

const ll N = 1e9+2;

struct cell {
    int r, c;
 
    int get_parity() const {
        return (r + c) & 1;
    }
 
    bool operator<(const cell &other) const {
        return c < other.c;
    }
};

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<cell> blocked(m);
    ll r = 0, c = 0;
    for(ll i = 0; i < m; i++){
        cin >> r >> c;
        blocked[i].r = r;
        blocked[i].c = c;
    }
    if(m%2 == 1){
        cout << "NO" << endl;
        return;
    }
    sort(blocked.begin(),blocked.end());
    int state = -1;
    for(ll i = 0; i < m; i++){
        //cout << state << " "<< blocked[i].c << " " << blocked[i].r << endl;
        if(i+1 < m && blocked[i].c == blocked[i+1].c){
            if(state != -1){
                cout << "NO" << endl;
                return;
            }
            i++;
            continue;
        }
        else if(state == -1){
            state = blocked[i].r; // take the other side
        }
        else{
            if((blocked[i].c-blocked[i-1].c)%2 == 0){
                if(state == 1) state = 2;
                else state = 1;
            }
            if(state == blocked[i].r){
                state = -1;
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
    }
    if(state == -1){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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