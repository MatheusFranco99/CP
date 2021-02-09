#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mod(a,b) a%b

/*

Thinking:

    

*/

void solve(){
    int n;
    vector<int> lst;
    cin >> n;
    int aux;
    rep(i,0,n){
        cin >> aux;
        lst.push_back(aux);
    }
    int e_P = 0;
    int e_O = 0;
    rep(i,0,n){
        if(mod(i,2) != mod(lst[i],2)){
            if(mod(i,2) == 0)   e_P++;
            else                e_O++;
        }
    }
    if(e_P == e_O)
        cout << e_P << endl;
    else
        cout << "-1"<< endl;
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