#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

/*

Thinking:

    The answer will be exactly like lst[0] except by 1 char (not necessarily).
    Thus, go through lst[0] changing one char and test for all string in lst.

    Brute force can be done since n,m <= 10.

*/



bool valid(string& a, vector<string>& lst){
    for(string s : lst){
        int diff = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != a[i]){
                diff++;
            }
        }
        if(diff > 1)
            return false;
    }
    return true;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<string> lst;
    int i,j;
    string aux;
    for(i = 0; i < n; i++){
        cin >> aux;
        lst.push_back(aux);
    }

    for(i = 0; i < m; i++){
        char t = lst[0][i];
        for(char c = 'a'; c <= 'z'; c++){
            lst[0][i] = c;
            if(valid(lst[0],lst)){
                cout << lst[0] << endl;
                return;
            }
        }
        lst[0][i] = t;
    }
    cout << "-1" << endl;
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