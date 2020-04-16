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

const int nMax = 100000;
int o[nMax];
int h[nMax];
ll x[nMax];
ll y[nMax];
ll pR[nMax];
ll pL[nMax];
int m[nMax][nMax];

int partition(int l,int r){
        int pivot = o[r];
        int i = l;
        for(int j = l; j < r; j++){
                if(x[pivot] > x[o[j]]){
                        swap(o[j],o[i]);
                        i++;
                }
        }
        swap(o[i],o[r]);
        return i;
}

void quicksort(int l, int r){
        if(l < r){
                int p = partition(l,r);
                quicksort(l,p-1);
                quicksort(p+1,r);
        }
}

int partition2(int l,int r){
        int pivot = h[r];
        int i = l;
        for(int j = l; j < r; j++){
                if(y[pivot] > y[h[j]]){
                        swap(h[j],h[i]);
                        i++;
                }
        }
        swap(h[i],h[r]);
        return i;
}

void quicksort2(int l, int r){
        if(l < r){
                int p = partition2(l,r);
                quicksort2(l,p-1);
                quicksort2(p+1,r);
        }
}

void solve(){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> x[i] >> y[i] >> pR[i];
                pL[i] = pR[i];
                o[i] = i;
                h[i] = i;
        }

        //order by x
        quicksort(0,n-1);
        //order hight
        quicksort2(0,n-1);
        // create protection matrix
        for(int i = 0; i < n; i++){

                m[o[i]][o[i]] = 1;
                int j = i;
                for(int l = 1; l <= pR[o[i]]; l++){
                        j++;
                        if(j >= n){
                                break;
                        }
                        if(y[o[j]] > y[o[i]]){
                                break;
                        }
                        if(x[o[j]] <= x[o[i]] + pR[o[i]]){
                                m[o[i]][o[j]] = 1;
                        }
                        else{
                                break;
                        }
                }
                j = i;
                for(int l = 1; l <= pL[o[i]]; l++){
                        j--;
                        if(j < 0){
                                break;
                        }
                        if(y[o[j]] > y[o[i]]){
                                break;
                        }
                        if(x[o[j]] >= x[o[i]] - pR[o[i]]){
                                m[o[i]][o[j]] = 1;
                        }
                        else{
                                break;
                        }
                }
        }

        // try to eliminate
        int ans = n;
        for(int i = 0; i < n; i++){
                int elm = h[i];
                int canTakeOut = 1;
                for(int j = 0; j < n; j++){
                        if(m[elm][j] == 1){
                                // check if can take out
                                canTakeOut = 0;
                                for(int k = 0; k < elm; k++){
                                        if(m[k][j] == 1){
                                                canTakeOut = 1;
                                                break;
                                        }
                                }
                                for(int k = elm+1; k < n; k++){
                                        if(m[k][j] == 1){
                                                canTakeOut =1;
                                                break;
                                        }
                                }
                                if(canTakeOut == 0){
                                        break;
                                }
                        }
                }
                if(canTakeOut == 1){
                        for(int j = 0; j < n; j++){
                                m[elm][j] = 0;
                        }
                        ans--;
                }
        }
        cout << ans << endl;
}

/*
order by x
create matrix of protection
try to eliminate as most as possible
*/


int main(){
        solve();
        return 0;
}