#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string>
#include <bits/stdc++.h>
#include <set>
#define ll long long
#define ull unsigned long long int
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

using namespace std;

ull takeClosesMultiple(ull m, ull n){
    if(n%m == 0)    return n;
    else return (int(n/m))*m;
}

void solve(){
    ull n, d;
    cin >> n >> d;
    vector<ull> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    //vector<ll> day(n+1);
    //day[n] = d;
    ull lastDay = d;
    //puts("here");
    for(int i = n-1; i >= 0; i--){
        //cout << i << " " << p[i] << " " << day[i+1] << endl;
        lastDay = takeClosesMultiple(p[i],lastDay);
    }
    printf("%llu\n",lastDay);
}

int main(){
    int tt;
    cin >> tt;
    for(int i = 0; i < tt; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;
int n;
ll d, x[mxN];

bool chk(ll y) {
	ll s=x[0]*y;
	for(int i=1; i<n; ++i) {
		s=((s+x[i]-1)/x[i])*x[i];
		if(s>d)
			return 0;
	}
	return 1;
}

void solve() {
	cin >> n >> d;
	for(int i=0; i<n; ++i)
		cin >> x[i];
	ll lb=1, rb=d/x[0];
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		if(chk(mb))
			lb=mb;
		else
			rb=mb-1;
	}
	cout << lb*x[0] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, i=1;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}