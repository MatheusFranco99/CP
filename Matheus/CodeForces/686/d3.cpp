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

const ll N = 1e10+1;//1e10+1;

vector<int> isPrime(N+1);
vector<ll> primes(0);

void init_sieve(){

    rep(i,2,N+1) isPrime[i] = 1;
    for(ll i = 2; i*i <= N;i++){
        if(isPrime[i]){
            for(ll j = i*i; j <= N; j+=i ) isPrime[j] = 0;
        }
    }
    isPrime[0] = isPrime[1] = 0;
}

void solve(){
    ll n;
    cin >> n;
    if(isPrime[n] == 1) {cout << n << endl; return;}
    cout << " For " << n << ":" << endl;
    map<ll,int> factors;

    ll lim  = (ll) sqrt(n);
    cout << lim << endl;
    rep(i,0,primes.size()){
        if(primes[i] > lim) break;
        if(n%primes[i] == 0){
            int exp = 0;
            ll aux = n;
            while(aux%primes[i] == 0){
                exp++;
                aux = aux / primes[i];
            }
            factors[primes[i]] = exp;
        }
    }
    cout << "hi" << factors.size() << endl;
    for(auto it = factors.begin(); it != factors.end();++it){
        cout << it->first << " " << it->second << endl;
    }

    vector<ll> ans;
    while(factors.size() != 0){
        ll member = 1;
        for(auto &a : factors){
            member = member * a.first;
            a.second--;
        }
        for(auto &a : factors){
            if(a.second == 0) factors.erase(factors.find(a.first));
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
        init_sieve();

        // rep(i,0,20) cout << isPrime[i] << " ";
        // cout << endl;
        // rep(i,0,10) cout << primes[i] << " ";
        // cout << endl;
        while(t--){
            solve();
        }
        return 0;
}