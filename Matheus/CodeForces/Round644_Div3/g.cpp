#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)

/*

Thinking:

    

*/

void solve(){
    int a,b,m,n;
    cin >> n >> m >> a >> b;
    int i,j;

    float f1 = float(m)/n;
    float f2 = float(a)/b;
    if(f1 != f2){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int A[n][m];

    // init
    rep(i,0,n){
        rep(j,0,m)
            A[i][j] = 0;
    }


    int c = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < a; j++){
            A[i][(c)%m] = 1;
            c++;
        }
    }

    rep(i,0,n){
        rep(j,0,m)  cout << A[i][j];
        cout << endl;
    }
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