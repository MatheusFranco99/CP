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

/*
160195 160195 30800 30800 30800 30800 3464
1        1     2      2      2    1     2
*/



void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> l(n);
    int last = -1;
    int inp;
    int next = -1;
    for(int i = 0; i < n ; i++){
        cin >> inp;
        if(inp == last){
            l[next].second++;
        }
        else{
            next++;
            l[next].first = inp;
            l[next].second = 1;
            last = inp;
        }
    }
    
}

int main(){
    int tt;
    cin >> tt;
    while(tt-- > 0){
        solve();
    }
    return 0;
}