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
    ll a,b;
    cin >> a >> b;
    ll rest = a%b;
    cout << (b - rest)%b << endl;
}

int main(){
    int tt;
    cin >> tt;
    while(tt-- > 0){
        solve();
    }
    return 0;
}