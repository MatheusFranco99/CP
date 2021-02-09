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
    string a;
    cin >> a;
    int len = a.size();
    cout << a[0];
    for(int i = 1; i < len; i++){
        cout << a[i];
        i++;
    }
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