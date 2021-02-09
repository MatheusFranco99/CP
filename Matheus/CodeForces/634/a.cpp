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
    ll n;
    cin >> n;
    if(n%2 == 0){
        ll ans = n-1 - n/2; // n/2 +1 -> n-1
        printf("%lld\n", ans);
    }
    else{
        ll ans = n-1 - (n-1)/2;
        printf("%lld\n",ans);
    }
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        solve();
    }
    return 0;
}