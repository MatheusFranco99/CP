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

vector<vector<int> > m(2);

void solve(){
    ll n,r;
    cin >> n >> r;
    rep(i,0,n){
        m[0][i] = 0;
        m[1][i] = 0;
    }
    ll x = 0, y = 0;
    rep(i,0,r){
        cin >> x >> y;
        m[x-1][y-1] = 1;
    }
    /*
    rep(i,0,n){
        cout << m[0][i] << " ";
    }
    cout << endl;
    rep(i,0,n){
        cout << m[1][i] << " ";
    }
    cout << endl;
    */

    /*
    // forced lines middle
    rep(i,1,n-1){
        if(m[0][i] == 0 && m[0][i-1] == 1 && m[0][i+1] == 1){
            if(m[1][i] == 1){
                cout << "NO" << endl;
                return;
            }
            m[0][i] = 2;
            m[1][i] = 2;
        }
    }
    rep(i,1,n-1){
        if(m[1][i] == 0 && m[1][i-1] == 1 && m[1][i+1] == 1){
            if(m[0][i] == 1){
                cout << "NO" << endl;
                return;
            }
            m[0][i] = 2;
            m[1][i] = 2;
        }
    }
    // forced lines on limits
    if(m[0][0] == 0 && m[0][1] == 1){
        if(m[1][0] == 1){
            cout << "NO" << endl;
            return;
        }
        m[0][0] = 2;
        m[1][0] = 2;
    }
    if(m[1][0] == 0 && m[1][1] == 1){
        if(m[0][0] == 1){
            cout << "NO" << endl;
            return;
        }
        m[0][0] = 2;
        m[1][0] = 2;
    }*/
    FORre(i,n-1,1){
        if(m[0][i] == 0 && m[1][i] == 0){ // last column all white
            m[0][i] = 2;
            m[1][i] = 2;
            continue;
        }
        else if(m[0][i]!= 0 && m[1][i] != 0){ // last column all busy = black or tied
            continue;
        }
        else{
            if(m[0][i] != 0){ // up is busy
                if(m[1][i-1] != 0){
                    cout << "NO" << endl;
                    return;
                }
                else{
                    m[1][i-1] = 2;
                    m[1][i] = 2;
                    continue;
                }
            }
            else{
                if(m[0][i-1] != 0){
                    cout << "NO" << endl;
                    return;
                }
                else{
                    m[0][i-1] = 2;
                    m[0][i] = 2;
                }
            }
        }
    }
/*
    rep(i,0,n){
        cout << m[0][i] << " ";
    }
    cout << endl;
    rep(i,0,n){
        cout << m[1][i] << " ";
    }
    cout << endl;
*/
    if((m[0][0] == 0 || m[1][0] == 0) && !(m[0][0] == 0 && m[1][0] == 0)){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        cin >> t;
        m[0].resize(N);
        m[1].resize(N);
        while(t--){
            solve();
        }
        return 0;
}