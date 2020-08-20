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

#define N 'N'

#define lim 1000000000
/*
N: Move one unit north.
S: Move one unit south.
E: Move one unit east.
W: Move one unit west.
*/

using namespace std;

void solve(){
    ll w = 0;
    ll h = 0;
    ll no = 0, so = 0, we = 0, ea = 0;
    ll rep = 1;
    vector<int>r;
    char c;
    scanf("%c",&c);
    while(c!='\n'){
        if(c == 'N') no+=rep;
        else if(c == 'S') so+=rep;
        else if(c == 'W') we+=rep;
        else if(c == 'E') ea+=rep;
        else if('0' <= c && c <= '9'){
            r.push_back(c-'0');
            rep = (c-'0')*rep;
            scanf("%c",&c);
        }
        else if(c == ')'){
            rep = (int) rep/r[r.size()-1];
            r.pop_back();
        }
        scanf("%c",&c);
    }

    no = no%lim;
    so = so%lim;
    we = we%lim;
    ea = ea%lim;
    h = (h - no + so);
    w = (w - we + ea);
    while(h < 0) h += lim;
    while(h >= lim) h -= lim;
    while(w < 0) w += lim;
    while(w >= lim) w -= lim;

    cout << w+1 << " " << h+1 << endl;
}

int main(){
    int tt;
    cin >> tt;
    char c;
    scanf("%c",&c);
    for(int i = 0; i < tt; i++){
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}