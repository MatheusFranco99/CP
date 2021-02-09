#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back


/*


*/

vector<int> memory(51);

void solve(){
    int x;
    cin >> x;
    if(memory[x] != -1){
        cout << memory[x] << endl;
        return;
    }
    int d = 9;
    string ans;
    ans = "";
    int n = x;
    while(x > 0 && d > 0){
        d = min(d,x);
        x = x - d;
        ans = to_string(d) + ans;
        d--;
    }
    int a = 0;
    rep(i,0,ans.size()){
        a = a*10 + (ans[i]-'0');
    }
    if(x == 0){
        cout << a << endl;
        memory[n] = a;
    }
    else{
        cout << "-1" << endl;
    }
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        cin >> t;
        rep(i,0,51){
            memory[i] = -1;
        }
        while(t--){
            solve();
        }
        return 0;
}