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
    int n,k;
    string s;
    cin >> n >> k;
    cin >> s;
    int a = 0, ans = 0, start = 0;
    while(a < n){
        while(a < n){
            if(s[a] == '1'){
                break;
            }
            a++;
        }
        if(a != n){
            int space = a - k - start; 
            if(space > 0){
                ans += space/(k+1);
                if(space%(k+1) != 0)    ans++;
            }
            a = a + k + 1;
            start = a;
        }
        if(a == n){
            int space = a - start;
            ans += space/(k+1);
            if(space%(k+1)!= 0) ans++;
            break;
        }
    }
    cout << ans << endl;
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