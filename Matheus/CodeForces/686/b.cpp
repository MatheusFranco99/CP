#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

void solve(){
    int n;
    cin >> n;
    int freq[n+1];
    int position[n+1];
    int aux;
    rep(i,0,n+1){
        freq[i] = 0;
        position[i] = 0;
    }
    rep(i,0,n){
        cin >> aux;
        freq[aux]++;
        position[aux] = i+1;
    }
    rep(i,1,n+1){
        if(freq[i] == 1){
            cout << position[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
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