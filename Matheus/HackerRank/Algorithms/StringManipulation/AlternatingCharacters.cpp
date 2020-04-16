#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#define ll long long

using namespace std;

void solve(){
        string c;
        cin >> c;
        int len = c.size();
        int deletions = 0;
        for(int i = 1; i < len; i++){
                if(c[i] == c[i-1])
                        deletions++;
        }
        cout << deletions << "\n";
}

int main(){
        int q;
        cin >> q;
        while(q-- > 0)
                solve();
        return 0;
}