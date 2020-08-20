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
    vector<int> lst;
    int aux = 0;
    for(int i = 0; i < n; i++){
        cin >> aux;
        lst.push_back(aux);
    }
    sort(lst.begin(),lst.end());
    
    int minDif = lst.back();
    for(int i = 1; i < n; i++){
        if(minDif > (lst[i] - lst[i-1])){
            minDif = lst[i] - lst[i-1];
        }
        if(minDif == 0) break;
    }
    cout << minDif << endl;

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