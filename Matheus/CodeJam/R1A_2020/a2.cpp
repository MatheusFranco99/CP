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

vector<string> l;

int adjust(int a, int b){
    string nova;
    string A = l[a];
    string B = l[b];
    int j = 0;
    int i = 0;
    for(i = 0; i < A.size(); i++){
        cout << "comparing : " << A[i] << " " << B[j] << endl;
        if(j >= B.size()){
            break;
        }
        if(A[i] == B[j]){
            nova.push_back(A[i]);
            j++;
            continue;
        }
        if(A[i] == '*'){
            continue;
        }
        if(B[j] == '*'){
            j++; continue;
        }
        if(A[i] != B[j]){
            if(A[i-1] == '*'){
                nova.push_back(B[j]);
                i--; // compensate
                continue;
            }
            else if(B[i-1] == '*'){
                nova.push_back(A[i]);
                continue;
            }
            else{
                return 0;
            }
        }
    }
    if(j < B.size()){
        if(A[i-1] == '*'){
            while(j < B.size()){
                nova.push_back(B[j]);
                j++;
            }
        }
    }
    else if(i < A.size()){
        if(B[j-1] == '*'){
            while(i < A.size()){
                nova.push_back(A[i]);
                i++;
            }
        }
    }
    l[a] = nova;
    l[b] = nova;
    return 1;
}


void solve(){
    int n;
    cin >> n;
    l.clear();
    string aux;
    for(int i = 0; i < n; i++){
        cin >> aux;
        l.push_back(aux);
    }
    int ans = 1;
    for(int i = 0; i < n-1; i++){
        if(adjust(i,i+1) == 0){
            ans = 0;
            break;
        }
    }
    if(ans == 0){
        cout << "*\n";
    }
    else{
        cout << l[n-1] << endl;
    }
    
}

int main(){
        int t;
        cin >> t;
        for(int i = 1; i <= t; i++){
            cout << "Case #" << i << ": ";
            solve();
        }
        return 0;
}