#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#define ll long long

using namespace std;

void solve(){
        vector<int> freq(26,0);
        string a,b;
        cin >> a;
        cin >> b;
        for(auto c : a){++freq[c - 'a'];}
        for(auto c : b){--freq[c - 'a'];}
        int min = 0;
        for(auto c : freq){min += abs(c);}
        cout << min << "\n";
}

int main(){
        solve();
        return 0;
}