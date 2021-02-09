#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mod(a,b) a%b



int repetitions(int size, int k){
    int a = k%size;
    int ans = 1;
    while(a != 0){
        ans++;
        a = (a+k)%size;
    }
    return ans;
}

void solve(){
    //cout << endl << endl;
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> lst;
    vector<int> freq;
    rep(i,0,26){
        freq.push_back(0);
    }
    for(auto c : s){
        freq[int(c) - 97] += 1;
    }
    for(auto c : freq){
        if(c != 0){
            lst.push_back(c);
        }
    }

    int ans = -1;
    sort(lst.begin(),lst.end());
    for(int i = n; i >= 1; i--){
        int r = repetitions(i,k);
        int couldGet = 0;
        int shouldGet = i/r;
        for(int j = lst.size()-1; j >= 0; j--){
            int c = lst[j];
            if(c < r){
                break;
            }
            int plus = c/r;
            couldGet += plus;
        }
        if(couldGet >= shouldGet){
            ans = i;
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



