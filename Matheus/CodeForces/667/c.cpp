#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORe(i,a,b) for(int i=a;i<=b;i++)
#define FORr(i,a,b) for(int i=a;i>b;i--)
#define FORre(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "



void solve2(){
    int n,x,y;
    cin >> n >> x >> y;

    int r = y - x;
    int below_x = max(0,x/r - 1);

    cout << imie(below_x) << imie(r) << endl;

    rep(i,0,min(below_x+1,n-2)){
        cout << x - r * i << " ";
    }
    cout << x << " ";
    cout << y << " ";
    for(int i = 1; i<= n-2-below_x; i++){
        cout << y + i * r << " ";
    }
    cout << endl;
}

vector<int> getDivisors(int x){
    vector<int> ans;
    for(int i = 1; i * i <= x; i++){
        if(x%i == 0){
            ans.pb(i);
            if(x/i != i) ans.pb(x/i);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

void solve(){
    int n,x,y; cin >> n >> x >> y;
    int dif = y-x;
    vector<int> ratios = getDivisors(dif);
    // rep(i,0,ratios.size()) cout << ratios[i] << " ";
    // cout << endl;
    int smaller_ratio = ratios[0];
    for(int i = ratios.size()-1; i>= 0; i--){
        if(y - (n-1) * ratios[i] > x){
            // cout << y -(n-1)*ratios[i] << endl;
            // cout << i << endl;
            smaller_ratio = ratios[i+1];
            break;
        }
    }
    // cout << smaller_ratio << endl;
    int num = 0;
    ll v = y;
    while(v > 0 && num < n){
        num++;
        cout << v << " ";
        v -= smaller_ratio;
    }
    v = y+smaller_ratio;
    while(num < n){
        cout << v << " ";
        num++;
        v += smaller_ratio;
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