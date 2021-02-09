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
    string r,b;
    cin >> r;
    cin >> b;

    int counter = 0;
    rep(i,0,n){
        if(b[i] > r[i]) counter--;
        if(r[i] > b[i]) counter++;
    }

    if(counter > 0) cout << "RED" << endl;
    if(counter < 0) cout << "BLUE" << endl;
    if(counter == 0) cout << "EQUAL" << endl;
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