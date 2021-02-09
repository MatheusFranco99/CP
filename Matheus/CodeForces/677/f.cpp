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

const int inf = 1e9 + 5;

void solve2(){
    int n,m,k;
    cin >> n >> m >> k;
    vector< int> dp(k,-inf);
    dp[0] = 0;
    int H = m/2;
    while(n--){
        vector<int> A(m);
        for(auto &a:A) cin >> a;
        vector< vector<int> > row_dp(H+1, vector<int>(k,-inf));
        row_dp[0][0] = 0;
        for(auto &a: A){
            for(int h = H-1; h>= 0; h--){
                for(int x = 0; x < k; x++){
                    if(row_dp[h+1][(x+a)%k] < row_dp[h][x]+a){
                        row_dp[h+1][(x+a)%k] = row_dp[h][x]+a;
                    }
                }
            }
        }
        vector<int> next_dp(k,-inf);
        for(int x = 0; x < k; x++){
            for(int h = 0; h <= H; h++){
                for(int y = 0; y < k; y++){
                    if(next_dp[(x+y)%k] < dp[x] + row_dp[h][y]){
                        next_dp[(x+y)%k] = dp[x] + row_dp[h][y];
                    }
                }
            }
        }
        dp = next_dp;
    }
    cout << dp[0] << endl;
}

void solve(){
    int N,M,K;
    cin >> N >> M >> K;
    int H = M/2;
    vector<int> dp(K,-inf);
    dp[0] = 0;
    while(N-- > 0){
        vector<int> A(M);
        FOR(i,0,M){cin >> A[i];}
        vector< vector<int> > row_dp(H+1, vector<int>(K,-inf));
        row_dp[0][0] = 0;
        /*
        row_dp: for 0 to H elements stores the max sum with remainder k
        for each element update position h of vector by adding element to position h-1 
        */
        for(auto a: A){
            for(int h = H-1; h >= 0; h--){
                for(int k = 0; k < K; k++){
                    int new_sum = row_dp[h][k] + a;
                    if(row_dp[h+1][(k+a)%K] < new_sum) row_dp[h+1][(k+a)%K] = new_sum; 
                }
            }
        }
        vector<int> new_dp(K,-inf);
        /*
        update dp with row_dp
        for 0 to K remainders, calculates new_dp[k] by maximum between old_dp[k] and
            old_dp[k-i] + dp[i]
        */
       rep(i,0,K) new_dp[i] = dp[i];
        for(int k = 0; k < K; k++){
            for(int h = 0; h <= H; h++){
                for(int k2 = 0; k2 < K; k2++){
                    int new_sum = dp[k] + row_dp[h][k2];
                    if(new_dp[(k+k2)%K] < new_sum) new_dp[(k+k2)%K] = new_sum;
                }
            }
        }
        dp = new_dp;
    }
    cout << dp[0] << endl;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        //cin >> t;
        t = 1;
        //prep();
        while(t--){
            solve();
        }
        return 0;
}