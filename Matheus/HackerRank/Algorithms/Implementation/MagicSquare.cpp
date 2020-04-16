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

int m[9];


int possible[8][9]=
{
{2,9,4,7,5,3,6,1,8},
{2,7,6,9,5,1,4,3,8},
{8,3,4,1,5,9,6,7,2},
{8,1,6,3,5,7,4,9,2},
{4,9,2,3,5,7,8,1,6},
{4,3,8,9,5,1,2,7,6},
{6,7,2,1,5,9,8,3,4},
{6,1,8,7,5,3,2,9,4}
};

void solve(){
    for(int i = 0; i < 9; i++){
        cin >> m[i];
    }
    int diff[8] = {0};
    for(int i = 0; i < 8; i++){
        diff[i] = 0;
        for(int j = 0; j < 9; j++){
            diff[i] += abs(m[j] - possible[i][j]);
        }
    }
    int min = diff[0];
    for(int i = 1; i < 8; i++){
        if(diff[i] < min){
            min = diff[i];
        }
    }
    cout << min << endl;
}

int main(){
        solve();
        return 0;
}