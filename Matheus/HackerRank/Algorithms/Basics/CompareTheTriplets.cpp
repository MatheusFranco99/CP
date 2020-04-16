#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

using namespace std;


void solve(){
        int a[3];
        int b[3];
        for(int i = 0; i < 3; i++){
                cin >> a[i];
        }
        for(int i = 0; i < 3; i++){
                cin >> b[i];
        }
        int pta = 0;
        int ptb = 0;
        for(int i = 0; i < 3; i++){
                if(a[i]>b[i]) pta++;
                else if(b[i]>a[i]) ptb++;
        }
        cout << pta << " " << ptb << "\n";       
}

int main(){
        solve();
        return 0;
}