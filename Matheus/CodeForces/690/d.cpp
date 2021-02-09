#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back



void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    int ans = 0;
    int size = n;
    while(size >= 2 && a[0] < a[1]){
        a[1] = a[1]+a[0];
        a.erase(a.begin());
        size--;
        ans++;
    }
    
    while(size >= 2 && a[size-1] < a[size-2]){
        a[size-2] += a[size-1];
        a.erase(a.begin()+size-1);
        size--;
        ans++;
    }

    ll sum = 0;
    rep(i,0,size) sum = sum + a[i];


    //rep(i,0,size) //cout << a[i] << " ";
    //cout << endl;

    int lim = sum;
    for(int i = 1; i <= lim; i++){
        if(sum%i == 0){ //&& size >= sum/i){ // test
            ll subsum = 0;
            ll expected_subsum = i;
            int worked = 1;
            //cout << "Testing with: sum = "<<sum<<", i = " << i << endl;
            int j= 0;
            rep(j,0,size){
                subsum = subsum + a[j];
                if(subsum > expected_subsum){
                    worked = 0;
                    //cout << "didnt work with: sum = "<<sum<<", i = " << i << endl;
                    break;
                }
                if(subsum == expected_subsum){
                    subsum = 0;
                }
            }
            if(worked == 1 && subsum == 0){
                //cout << "Succes with: sum = "<<sum<<", i = " << i << endl;
                cout << n - sum/i << endl;
                break;
            }
        }
    }
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