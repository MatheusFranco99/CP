#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

using namespace std;

map<string,int> freqOfSufix;
vector<string> lst(1000);

int findMaxPairs(int n){
        int ans = 0;
        int len = 0;
        int i = 0;
        for(int i = 0; i < n; i++){
                len = lst[i].size();
                for(int s = 0; s < len; s++){
                        if(freqOfSufix[lst[i].substr(s,len)] >= 2){
                                freqOfSufix[lst[i].substr(s,len)] = 0;
                                for(int j = s+1; j < len; j++){
                                        freqOfSufix[lst[i].substr(j,len)] -= 2;
                                }
                                ans+=2;
                                break;
                        }
                }
        }
        return ans;
}

void solve(){
        freqOfSufix.clear();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> lst[i];
        }
        int len;
        for(int i = 0; i < n; i ++){
                len = lst[i].size();
                for(int s = 0; s < len; s++){
                        freqOfSufix[lst[i].substr(s,len)]++;
                }
        }
        cout << findMaxPairs(n) << endl;
}

int main(){
        int t;
        cin >> t;
        int total = t;
        while(t-- > 0){
                cout << "Case #" << total-t << ": ";
                solve();
        }
        return 0;
}