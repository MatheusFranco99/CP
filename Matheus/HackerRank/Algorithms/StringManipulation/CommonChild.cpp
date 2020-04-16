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


string s1(5000,0);
string s2(5000,0);
const int nMax = 5000;
int M[nMax][nMax];

void calculate(int i,int j){
        if(M[i][j] != -1){
                return;
        }
        else{
                if(s1[i] == s2[j]){
                        calculate(i-1,j-1);
                        M[i][j] = M[i-1][j-1]+1;
                        return;
                }
                else{
                        calculate(i-1,j);
                        calculate(i,j-1);
                        M[i][j] = max(M[i-1][j],M[i][j-1]);
                        return;
                }
        }
}

void solve(){
        cin >> s1;
        cin >> s2;
        int l1 = s1.size();
        int l2 = s2.size();
        if(s1[0]==s2[0]){
                M[0][0] = 1;
        }
        for(int i = 1; i < l1; i ++){
                if(s1[i] == s2[0]){
                        M[i][0] = 1;
                }
                else{
                        M[i][0] = M[i-1][0];
                }
        }
        for(int i = 1; i < l2; i++){
                if(s1[0] == s2[i]){
                        M[0][i] = 1;
                }
                else{
                        M[0][i] = M[0][i-1];
                }
        }
        for(int i = 1; i < l1; i++){
                for(int j = 1; j < l2; j++){
                        M[i][j] = -1;
                }
        }
        for(int i = 1; i < l1; i++){
                for(int j = 1; j < l2; j++){
                        calculate(i,j);
                }
        }
        cout <<M[l1-1][l2-1] << "\n";
}

int main(){
        solve();
        return 0;
}