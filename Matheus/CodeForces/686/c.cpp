#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

void solve(){
    int n;
    cin >> n;
    vector<int> l(n);
    int freq[n+1];
    rep(i,0,n+1) freq[i] = -5;
    
    cin >> l[0];
    int aux = l[0];
    freq[aux]=1;
    int var_n = n;
    rep(i,1,var_n){
        cin >> l[i];
        if(aux == l[i]){
            l.erase(l.begin()+i);
            i--;
            var_n--;
        }
        else{
            aux = l[i];
            if(freq[aux] == -5) freq[aux] = 1;
            else{
                freq[aux]++;
            }
        }
    }
    int min_index = -1;
    freq[l[0]]--;
    freq[l[l.size()-1]]--;
    rep(i,0,n+1){
        if(min_index == -1){
            if(freq[i] != -5) min_index = i;
        }
        if(freq[i] != -5){
            if(l[0] == i||l[l.size()-1]==i){
                if(freq[min_index] >= freq[i]) min_index = i;
            }
            else{
                if(freq[min_index] > freq[i]) min_index = i;
            }
        }
    }
    cout << freq[min_index]+1 << endl;
    return;
    int ans = 0;
    int state = 0; // 0 - not started to cut; 1 - started
    rep(i,0,l.size()){
        if(state == 0){
            if(l[i] != min_index){
                state = 1;
                ans++;
            }
        }
        if(state == 1){
            if(l[i] == min_index) state = 0;
        }
    }
    cout << "l:"<<endl;
    rep(i,0,l.size()) cout << l[i] << " ";
    cout << endl;

    cout << "freq:"<<endl;
    rep(i,0,n+1) cout << freq[i] << " ";
    cout << endl;

    cout << imie(min_index) << endl;

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