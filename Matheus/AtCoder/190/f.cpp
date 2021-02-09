#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORe(i,a,b) for(int i=a;i<=b;i++)
#define FORr(i,a,b) for(int i=a;i>b;i--)
#define FORre(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

template <typename T>
struct FenwickTree{
    vector<T> bit;
    int n;
    FenwickTree(int n){
        this->n = n;
        bit = vector<T>(n,0);
    }
    FenwickTree(vector<T> a):FenwickTree(a.size()){
        for(int i = 0; i < a.size(); i++)add(i,a[i]);
    }
    int sum (int r){
        T ans = 0;
        while(r >= 0){
            ans += bit[r];
            r = (r & (r+1) - 1);
        }
        return ans;
    }
    void add(int idx,int v){
        while(idx < n){
            bit[idx]+=v;
            idx = idx | (idx+1);
        }
    }
};

template <typename T>
struct binary_indexed_tree{
	int N;
	vector<T> BIT;
	binary_indexed_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		BIT = vector<T>(N + 1, 0);
	}
	void add(int i, T x){
		i++;
		while (i <= N){
			BIT[i] += x;
			i += i & -i;
		}
	}
	T sum(int i){
		T ans = 0;
		while (i > 0){
			ans += BIT[i];
			i -= i & -i;
		}
		return ans;
	}
};

ll count_inv(int l,int r,vector<int> &a){
    int i = l;
    ll ans = 0;
    multiset<int> s;
    s.insert(a[i++]);
    while(i <= r){
        s.insert(a[i]);
        ans += distance(s.upper_bound(a[i]),s.end());
        i++;
    }
    return ans;
}

void solve(){
    ll n; cin >> n;
    vector<int> a(n);
    vector<int> adj_fac(n,0);
    adj_fac[0] = n-1;
    rep(i,1,n) adj_fac[i] = adj_fac[i-1] - 2;
    rep(i,0,n) cin >> a[i];
    //ll ans = count_inv(0,n-1,a);
    ll ans = 0;
    binary_indexed_tree<int> b(n);
    rep(i,0,n){
        ans += i - b.sum(a[i]);
        b.add(a[i],1);
    }

    cout << ans << endl;
    rep(i,1,n){
        // ans = ans + (n-1)-elm - (elm);
        ans += adj_fac[a[i-1]];
        // rep(j,i,i+n){
        //     if(a[j] < elm) ans--;
        //     if(a[j] > elm) ans++;
        // }
        cout << ans << endl;
    }
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        t = 1;
        while(t--){
            solve();
        }
        return 0;
}