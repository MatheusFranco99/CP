#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string>
#include <bits/stdc++.h>
#include <set>
#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

using namespace std;


void solve(){
    int n,k;
    cin >> n >> k;

    int i, ans = INT_MAX;
    for(i = 1; (i*i <= n && i <= k) ; i++){
        if(n%i == 0){ // divides
            int x = n/i;
            if(x <= k){ // if exists such box return i
                cout << i << endl;
                return;
            }
            else{
                // can deliver m box of size i; while i++, m-- so we dont have to compare
                ans = x;
            }
        }
    }
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