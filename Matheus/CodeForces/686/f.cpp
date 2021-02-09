#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forrRev(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

/*
1 2 3 3 3 4 4 3 4 2 1

2 9 1 7 3 9 4 1

*/

const ll INF = 1e9+10;


template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<T> values;
    vector<vector<int> > range_low;
 
    RMQ(const vector<T> &_values) {
        if (!_values.empty())
            build(_values);
    }
 
    static int largest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }
 
    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }
 
    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = largest_bit(n) + 1;
        range_low.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);
 
        for (int i = 0; i < n; i++)
            range_low[0][i] = i;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }
 
    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        b = b+1;
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }
 
    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};
 

ll lmax(ll a[],int l, int r){
    ll ans = a[l];
    rep(i,l+1,r+1){
        if(ans < a[i]) ans = a[i];
    }
    return ans;
}

ll lmin(ll a[],int l, int r){
    ll ans = a[l];
    rep(i,l+1,r+1){
        if(ans > a[i]) ans = a[i];
    }
    return ans;
}

void dp(vector< vector<ll> > &m, ll a[], int n){
    /*
    (1,2) (2,3)
    (1,1) (2,2) (1,2)
    (2,2) (3,3) (2,3)
    (1,2) (2,3) (1,3)
    */
    rep(i,1,n+1) m[i][i] = a[i];

    rep(j,2,n+1){
        rep(i,j,n+1){
            m[i-(j-1)][i] = min(m[i-(j-2)][i],a[i-(j-1)]);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n+1);
    rep(i,1,n+1) cin >> a[i];

    //vector< vector<ll> > m(n+1);
    RMQ<ll> m(a);
    //rep(i,1,n+1){m[i] = vector<ll>(n+1);;rep(j,1,n+1) m[i][j] = 0;}
    //dp(m,a,n);

    vector<ll> prefix_max(n+1,-INF);
    vector<ll> suffix_max(n+1,-INF);
    rep(i,1,n+1){
        prefix_max[i] = max(prefix_max[i-1],a[i]);
    }
    suffix_max[n] = a[n];
    forrRev(i,n-1,1){
        suffix_max[i] = max(suffix_max[i+1],a[i]);
    }
    // rep(i,1,n+1) cout << prefix_max[i] << " ";
    // cout << endl;
    // rep(i,1,n+1) cout << suffix_max[i] << " ";
    // cout << endl;
    forrRev(b,n,3){
        ll v = suffix_max[b];
        int start = int(lower_bound(prefix_max.begin()+1,prefix_max.begin()+b,v)-prefix_max.begin());
        int end = int(upper_bound(prefix_max.begin()+1,prefix_max.begin()+b,v)-prefix_max.begin());

        //cout << imie(b) << imie(v) << imie(start) << imie(end) << endl;

        if(end <= start) continue;

        int l = start, r = end-1;
        if(end == b) r = r-1;
        if(l!=r){
            //cout << imie(l) << imie(r) << endl;
            while(l<=r){
                int mid = (l+r)/2;
                //cout << imie(mid)<<endl;
                if(m.query_value(mid+1,b-1) == v){
                    l = mid; break;
                }
                if(mid == b || m.query_value(mid+1,b-1) < v) l = mid+1;
                else r = mid-1;
                //cout << imie(l) << imie(r) << endl;
            }
        }
        if(l < b-1 && m.query_value(l+1,b-1) == v){ cout <<"YES" << endl << l << " " << b-l-1 << " " << n-b+1 << endl; return;}
    }
    cout << "NO" << endl;
    
}


void solve2(){
    int n;
    cin >> n;
    ll a[n+1];
    rep(i,1,n+1) cin >> a[i];
    ll max = lmax(a,1,n);
    ll min = lmin(a,1,n);
    cout << imie(max) << imie(min) << endl;

    vector< vector<ll> > m(n+1);
    rep(i,1,n+1){m[i] = vector<ll>(n+1);;rep(j,1,n+1) m[i][j] = 0;}
    dp(m,a,n);
    rep(i,1,n+1){
        rep(j,1,n+1) cout << m[i][j] << " ";
        cout << endl;
    }
    return;

    ll b[n+1];
    rep(i,1,n+1) b[i] = a[i];
    sort(a+1,a+n+1);
    int pointer = n;
    int rep = 1;
    int v = -1;
    /*
    while(pointer > 0){
        if(a[pointer] == a[pointer+1]){
            rep++;
        }
        else{
            rep = 0;
        }
        if(rep >= 3){
            v = a[pointer];
            while(pointer > 0 && a[pointer] == v){
                rep++;
                pointer--;
            }
            pointer++;
            
            vector<int> indexes;
            rep(i,1,n+1){if(a[i] == v)indexes.pb(i);}

            int x = 0, y = 0, z = 0;
            int occ = 0;
            int occx = 0;
            int j = 1;
            while(j <= n){
                if(x == 0){
                    if(a[j] ==  v) occ++;
                    if(a[j] > v){
                        if(occ == 0){ // cant with v
                            while(pointer > 0 && a[pointer] == v) pointer--;
                            break:
                        }
                        if(occ > 0){
                            x = indexes[occ];
                            occx = occ;
                        }
                    }
                }
                else if(y == 0){
                    if(a[j] ==  v) occ++;
                    if(a[j] < v){
                        if(occ == occx){ // cant with v
                            while(pointer > 0 && a[pointer] == v) pointer--;
                            break:
                        }
                        else{
                            y = indexes[occ];
                        }
                    }
                }
            }
        }
        pointer--;
    }*/
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