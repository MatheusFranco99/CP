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

    if(n%2 == 0){
        // n/2 to right or n/2 to left
        int basis = (n/2 -(-n/2-1)+1)/2;
        cout << basis * basis << endl;
        return;
    }
    else{
        cout << 2 * (n/2+1) *(n/2+2) << endl;
        return;
    }

}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        solve();
        return 0;
}