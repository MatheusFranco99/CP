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
    vector<int> e;
    vector<int> o;
    int aux;
    for(int i = 0; i < n; i++){
        cin >> aux;
        if(aux%2 == 0)  e.push_back(aux);
        else            o.push_back(aux);
    }
    if(e.size()%2 == 0 && o.size()%2 == 0){
        cout << "YES" << endl;
        return;
    }
    if((e.size()%2 == 1 && o.size()%2 == 0) || (e.size()%2 == 0 && o.size()%2 == 1)){
        cout << "NO" << endl;
        return;
    }
    for(auto i: e){
        for(auto j: o){
            if(abs(i - j) == 1){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    return;
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