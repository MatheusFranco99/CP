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
    vector<pair<char,int>> l;
    int n;
    cin >> n;
    char last = '\0';
    char now;
    int lIterator = -1;
    for(int i = 0; i < n; i++){
        cin >> now;
        if(now != last){
            pair<char,int> novo;
            novo.first = now;
            novo.second = 1;
            l.push_back(novo);
            lIterator++;
            last = now;
        }
        else{
            l[lIterator].second++;
        }
    }
    ll ans = 0;
    int len = lIterator+1;
    for(int i = 0; i < len; i++){ // alone : n + n-1 + n-1 + ... + 1 = n(n+1)/2
        ans+= (l[i].second+1)*(l[i].second)/2;
    }
    for(int i = 0; i < len-2; i++){ // combinations of a...aba...a
        if(l[i].first == l[i+2].first && l[i+1].second == 1){
            int m = min(l[i].second,l[i+2].second);
            ans+= m;
        }
    }
    cout << ans << endl;
}

int main(){
        solve();
        return 0;
}