#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


/*
    if n = a * b
    then answer of n is
    answer of a + answer of b

    360 - 2 2 90

    360 = 2 * 2 * 2 * 3 * 3 * 5
*/

const ll N = 1e6+1;//1e10+1;

vector<map<ll,int> > factors(N+1);

void sieve_step(ll a){
    if(factors[a].size() == 0){
        factors[a][a] = 1;
        ll c = a, b = a;
        int i = 1;
        while(c <= N){
            b = c;
            while(b <= N){
                factors[b][a] = i;
                b = b+c;
            }
            c = c * a;
            i++;
        }   
    }
}

void continue_sieve(ll until){
    for(ll i = 2; i <= until;i++){
        sieve_step(i);
    }
}

void solve(){
    ll n;
    cin >> n;
    if(factors[n].size() == 0){
        continue_sieve(n);
    }
    int min = -1, max = -1;
    for(auto a : factors[n]){
        if(min == -1){
            min = a.first;
            max = a.first;
        }
        if(factors[n][min] > a.second) min = a.first;
        if(factors[n][max] < a.second) max = a.first;
    }
    map<ll,int> aux;
    for(auto a : factors[n]){
        aux[a.first] = a.second;
    }
    vector<ll> ans;
    while(aux.size() != 0){
        ll member = 1;
        for(auto a : aux){
            member = member * a.first;
            a.second--;
        }
        for(auto a : aux){
            if(a.second == 0) aux.erase(aux.find(a.first));
        }
        ans.pb(member);
    }
    for(int i = ans.size()-1; i>0; i--){
        cout << ans[i] << " ";
    }
    cout << ans[0] << endl;
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