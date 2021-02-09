#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

/*

N = 10

9 1 - 2 (would be 8)
9 2 - 3 (would be 7)
9 3 - 4 (would be 6)
9 4 - 5 (would be 5)
9 5 - 4 (would be 4)
9 6 - 3
9 7 - 2
9 8 - 1
9 10 - 1

Thinking:

	if better is m
	then ans is
	sum:
		min(|key[i] - m|, |m+N - key[i]|)
		or
		factor = key[i]-m
		if( factor > N/2)
			factor = N - factor

*/

void solve(){
	int w,n;
	cin >> w >> n;
	vector<int> key(w);
	rep(i,0,w){
		cin >> key[i];
	}

	ll A = -1;
	rep(j,0,w){
		int best = key[j];
		int factor = 0;
		ll ans = 0;
		double mid = n/2;
		for(int i = 0; i < w; i++){
			factor = abs(key[i] - best);
			if(factor > mid){
				factor = n - factor;
			}
			ans += factor;
		}
		if(A == -1) A = ans;
		if(A > ans) A = ans;
	}
	cout << A << endl;
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