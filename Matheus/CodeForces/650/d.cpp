#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mod(a,b) a%b

/*

Thinking:

    every b list has a zero corresponding to the highest element
    find 0, assing the highest letter
    

*/

void solve(){
    string s;
    int m;
    vector<int> b;
    cin >> s >> m;
    
    int i, aux;
    rep(i,0,m){
        cin >> aux;
        b.push_back(aux);
    }
    //sort s string
    sort(s.begin(),s.end());

    // j will be an iterator to the s string
    int j = s.size()-1;
    string ans;
    ans = s;
    vector<int> queue; // will store 0 indexes in B list
    
    // Below : auxiliar; store element to be placed in the 0; store number of 0 already found
    int k, elm = 0, u = 0;
    while(u < m){

        // take b elements that are 0 and increments u
        for(i = 0;i < m; i++){
            if(b[i] == 0){
                b[i] = -1;
                queue.push_back(i);
                u++;
            }
        }

        // take first element of s that appears queue.size() times or more
        int found = 0;
        int y = 0;
        while(found != 1){
            elm = s[j--];
            for(y = 1; y < queue.size(); y++){
                if(elm != s[j--]){
                    j++;
                    break;
                }
            }
            if(y >= queue.size()){
                found = 1;
            }
        }
        // upgrade answer
        for(auto y : queue){
            ans[y] = elm;
        }
        // take out if elm appear more than queue.size()
        while(s[j] == elm){
            j--;
        }
        // upgrade b values 
        rep(k,0,m){
            for(auto i : queue){
                b[k] -= abs(i-k);
            }
        }

        queue.clear();
    }

    rep(i,0,m)
        cout << ans[i];
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