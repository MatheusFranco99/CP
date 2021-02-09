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
4
7 5 3
6 1 1
6 6 1
5 2 2

7 5 3
aaaaaaa
abcabca

6 1 1
aaaaaa
aaaaaa

6 6 1
aaaaaa
aaaaaa

5 2 2
ababa
*/

void solve(){
    int n;
    cin >> n;
    map<int,int> freq;
    int i1;
    for(int i = 0; i < n; i++){
        cin >> i1;
        freq[i1] +=1;
    }
    int _max = -1;
    int num_diff_elms = 0;
    for(auto c : freq){
        num_diff_elms++;
        if(c.second > _max){
            _max = c.second;
        }
    }
    int ans = 0;
    if(_max < num_diff_elms){
        ans = _max;
    }
    if(_max == num_diff_elms){
        ans = num_diff_elms - 1;
    }
    if(_max > num_diff_elms){
        ans = num_diff_elms;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        solve();
    }
    return 0;
}