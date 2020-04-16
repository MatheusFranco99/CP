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
    vector<string> s(9);
    for(int i = 0; i < 9; i ++){
        cin >> s[i];
    }
    vector<int> a = {0,3,6,1,4,7,2,5,8};
    for(int i = 0; i < 9; i++){
        s[i][a[i]] = s[i][a[i]] == '9' ? '1' : s[i][a[i]]+1;
    }
    for(int i = 0; i < 9; i ++){
        cout << s[i] << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        solve();
    }
    return 0;
}