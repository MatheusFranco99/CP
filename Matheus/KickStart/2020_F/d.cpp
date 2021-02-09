#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

/*

Thinking:
    3 6 2
    1
    2
    
    probability that can do in m:

        1 * (1/m)^(A1-1) * 1 * (1/m)^(A2-1)* ... * (1/m)^(Ak-1)
    
    probability that can do in m+1:
        1 * (1/m)^(A1-1) * 1 * (1/m)^(A2-1)* ... * (1/m)^(Ak-1) * (1 - 1/m)

*/

ll factorial(int x){
    ll prod = 1;
    rep(i,2,x+1){
        prod = prod * i;
    }
    return prod;
}

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> A(k);
    rep(i,0,k){
        cin >> A[i];
    }
    double prob = 1.0;
    double ratio = 1.0/m;
    for(auto c : A){
        prob = prob * pow(ratio,c-1);
    }
    double ans = 0;
    double ratio_c = 1.0 - A.size() * 1.0/m;
    rep(i,0,400){
        ans += prob * (m+i);
        prob = prob * ratio_c;
    }
    cout << ans << endl;
}

void solve2(){
    int n,m,k;
    vector<int> A(k);
    rep(i,0,k){
        cin >> A[i];
    }
    double prob = factorial(n)/pow(m,n);
    for(auto c : A){
        prob = prob / factorial(c);
    }
    double ans = prob * m;
    double sup = m;
    double inf = 0;
    double ratio = A.size()/m;
    double ratio_c = 1 - ratio;
    rep(i,1,2){
        sup++;
        inf++;
        prob = prob * sup /inf * ratio_c;
        ans += prob * (m+i);
    }
    cout << ans << endl;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t,x;
        cin >> t;
        x = 1;
        while(x <= t){
            cout << "Case #" << x << ": ";
            solve();
            x++;
        }
        return 0;
}