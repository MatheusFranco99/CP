#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORe(i,a,b) for(int i=a;i<=b;i++)
#define FORr(i,a,b) for(int i=a;i>b;i--)
#define FORre(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "



void solve(){
    ull n, original_n;
    int s = 0;
    cin >> n >> s;
    original_n = n;
    vector<int> vec;
    while(n > 0){
        vec.pb(n%10);
        n = n / 10;
    }
    vec.pb(0);
    // find smaller number bigger then n that has sum equals to s, print the difference
    int sum = 0;
    rep(i,0,vec.size()){
        sum += vec[i];
    }
    for(int i = 0; i< vec.size();i++){

        if(sum <= s) break;
        
        sum -= vec[i];
        vec[i] = 0;

        int j = i+1;
        while(vec[j] == 9){
            vec[j] = 0;
            sum -= 9;
            j++;i++;
        }
        sum += 1;
        vec[i+1]++;
    }
    ull result = 0;
    for(int i = vec.size()-1; i>= 0; i--){
        result = result * 10 + vec[i];
    }
    cout << result - original_n << endl;
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