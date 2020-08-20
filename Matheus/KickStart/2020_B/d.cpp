#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string>
#include <bits/stdc++.h>
#include <cstdlib>
#include <set>
#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

#define N 'N'

#define lim 1000000000
/*
N: Move one unit north.
S: Move one unit south.
E: Move one unit east.
W: Move one unit west.
*/

using namespace std;


ll w, h, l, u, r, d;

int runTest(){
    ll x = 1, y = 1;
    int nextStep;
    while(x <= r && y <= d){
        nextStep = rand()%2 +1;
        if(nextStep == 1) x++;
        else if(nextStep == 2) y++;
        
        if(x >= l && y >= u){
            return 0;
        }
    }
    return 1;
}

void solve(){
    cin >> w >> h >> l >> u >> r >> d;
    ll succes = 0;
    ll total = 150000;
    for(int i = 0; i < total; i++){
        if(runTest()){
            succes++;
        }
    }
    double s = succes;
    double t = total;
    double ans = s/t;
    cout.precision(6);
    cout << fixed << ans << endl;
}

int main(){
    int tt;
    cin >> tt;
    char c;
    for(int i = 0; i < tt; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}