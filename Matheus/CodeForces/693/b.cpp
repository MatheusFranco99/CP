#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forrRev(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

void solve(){

    int n;
    cin >> n;
    ll ones = 0, twos = 0;
    ll sum = 0;
    int aux = 0;
    rep(i,0,n){
        cin >> aux;
        if(aux == 1) ones++;
        else twos++;
        sum += aux;
    }
    if(sum%2 != 0){
        cout << "NO" << endl;
        return;
    }
    if(twos%2 != 0){
        if(ones < 2){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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