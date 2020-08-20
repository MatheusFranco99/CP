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
    string aux;
    int m[n][n];
    int i,j;
    for(i = 0; i < n; i++){
        cin >> aux;
        j = 0;
        for(auto c : aux){
            m[i][j] = ((int) c) - 48;
            j++;
        }
    }
    /*
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    */
    int ones = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(m[i][j] == 1)    ones++;
        }
    }

    for(i = n-1; (i >= 0 && ones > 0);i--){
        // test m[i][i]
        if(m[i][i] == 1){
            if(i == n-1) ones --;
            else if(m[i+1][i] == 1) ones --;
            else if(m[i][i+1] == 1) ones --;
            else{
                cout << "NO" << endl;
                return;
            }
        }
        for(j = i-1; ( j>= 0 && ones > 0); j--){
            // test m[i][j]
            if(m[i][j] == 1){
                if(i == n-1) ones--;
                else if( m[i+1][j] == 1)    ones--;
                else if( m[i][j+1] == 1)    ones--;
                else{
                    cout << "NO" << endl;
                    return;
                }
            }
            // test m[j][i]
            if(m[j][i] == 1){
                if(i == n-1) ones --;
                else if( m[j][i+1] == 1)    ones--;
                else if( m[j+1][i] == 1)    ones--;
                else{
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
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