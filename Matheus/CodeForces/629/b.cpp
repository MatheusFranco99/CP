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
5
bbaaa
babaa
baaba
baaab
abbaa
ababa
abaab
aabba se for 2 ocupa posicao 5 - 2 - 1 e 5 - 1 + 1
aabab se for 1 ocupa posicao 5 - 2 - 1 e 5 - 1 + 0
aaabb se for zero ocupa posicao 5 - 2 - i e 5 - 1 + 0
*/


void solve(){
    int n, k;
    cin >> n >> k;
    k;
    string a;
    for(int i = 0; i < n; i++){
        a.append(1,'a');
    }
    int sum = 0;
    for(int i = 1; i < n ; i++){
        sum = sum + i;
        if(sum >= k){
            a.at(n - 2 - i + 1) = 'b';
            k = sum - k + 1 ;
            a.at(n - 2 - i + 1 + k) = 'b';
            cout << a << endl;
            return;
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