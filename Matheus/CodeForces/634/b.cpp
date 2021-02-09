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
    int n, a, b;
    cin >> n >> a >> b;
    string r(n,' ');
    for(int i = 0; i < n; i ++) r[i] = 'a' + i%b;
    cout << r << endl;
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        solve();
    }
    return 0;
}