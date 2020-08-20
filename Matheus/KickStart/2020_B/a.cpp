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
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    ll ans = 0;
    for(int i = 1; i < n-1; i++){
        if(p[i] > p[i-1] && p[i] > p[i+1]){
            ans++;
        }
    }
    cout << ans << endl;
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