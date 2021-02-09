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



void solve(){
    int n, k; cin >> n >> k;
    string s,t;
    cin >> s >> t;

    vector<int> prefix(n,0);
    rep(i,1,n){
        prefix[i] = prefix[i-1];
        if(s[i-1] == t[0]) prefix[i]++;
    }
    vector<int> suffix(n,0);
    FORre(i,n-2,0){
        suffix[i] = suffix[i+1];
        if(s[i+1] == t[1]) suffix[i]++;
    }

    vector<int> prefix_index(n,0);
    vector<int> suffix_index(n,0);
    rep(i,0,n){
        prefix_index[i] = i;
        suffix_index[i] = i;
    }


    std::sort(prefix_index.begin(), prefix_index.end(), [&](size_t a, size_t b) {
        if(prefix[a] < prefix[b]) return true;
        else return a > b;
    });
    std::sort(suffix_index.begin(), suffix_index.end(), [&](size_t a, size_t b) {
        if(suffix[a] > suffix[b]) return true;
        else return a < b;
    });

    cout << "prefix\n";
    rep(i,0,n) cout << prefix[i] << " "; cout << endl;
    cout << "suffix\n";
    rep(i,0,n) cout << suffix[i] << " "; cout << endl;
    cout << "prefix index\n";
    rep(i,0,n) cout << prefix_index[i] << " "; cout << endl;
    cout << "suffix index\n";
    rep(i,0,n) cout << suffix_index[i] << " "; cout << endl;

    int best_0 = 0, best_1 = 0;
    int num = 0;
    while(num < k){
        num++;
        while(best_0 < n && s[suffix_index[best_0]] == t[0]) best_0++;
        while(best_1 < n && s[prefix_index[best_1]] == t[1]) best_1++;
        cout << imie(best_0) << imie(best_1) << endl;
        if(best_0>= n && best_1 >= n) break;
        if(best_0 >= n){
            cout << "case1\n";
            best_1++;
            // we will put t[1] for prefix index
            // if(s[prefix_index[best_1]] == t[0]){
            //     for(int i = prefix_index[best_1]; i>= 0; i--)suffix[i]--;
            // }
            s[prefix_index[best_1]] = t[1];
        }
        else if(best_1 >= n){
            cout << "case2\n";
            best_0++;
            // we will put t[0] for suffix index
            // if(s[suffix_index[best_0]] == t[1]){
            //     for(int i = suffix_index[best_0]; i< n; i++)prefix[i]--;
            // }
            s[suffix_index[best_0]] = t[0];
        }
        else{
            if(suffix[suffix_index[best_0]] > prefix[prefix_index[best_1]]){
            cout << "case3\n";
                
                best_0++;
                // we will put t[0] for suffix index
                if(s[suffix_index[best_0]] == t[1]){
                    for(int i = suffix_index[best_0]; i>= 0; i--)suffix[i]--;
                }
                s[suffix_index[best_0]] = t[0];
            }
            else{
            cout << "case4\n";
                best_1++;

                // we will put t[1] for prefix index
                if(s[prefix_index[best_1]] == t[0]){
                    for(int i = prefix_index[best_1]; i< n; i++)prefix[i]--;
                }
                s[prefix_index[best_1]] = t[1];
            }
        }
        cout << imie(s) << endl;
        cout << "prefix\n";
        rep(i,0,n) cout << prefix[i] << " "; cout << endl;
        cout << "suffix\n";
        rep(i,0,n) cout << suffix[i] << " "; cout << endl;
        cout << "prefix index\n";
        rep(i,0,n) cout << prefix_index[i] << " "; cout << endl;
        cout << "suffix index\n";
        rep(i,0,n) cout << suffix_index[i] << " "; cout << endl;
        cout << imie(best_0) << imie(best_1) << endl;
        cout << endl << endl;
    }
    cout << s << endl;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }
        return 0;
}