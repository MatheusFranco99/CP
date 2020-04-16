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

vector<string> vec;

int compare(int a,int b){
        if(vec[a].size() > vec[b].size()){
                return 1;
        }
        else if(vec[a].size() == vec[b].size()){
                int len = vec[a].size();
                for(int i = 0; i < len; i++){
                        if(vec[a][i] > vec[b][i]){
                                return 1;
                        }
                        else if(vec[b][i] > vec[a][i]){
                                return 0;
                        }
                }
        }
        return 0;
}

int partition(int l, int r){

        int i = l - 1; // Index of smaller element

        for(int j = l; j <= r- 1; j++)
        {
                if(compare(r,j)){
                        i++;
                        swap(vec[i],vec[j]);
                }
        }
        swap(vec[i+1],vec[r]);
        return i + 1;
}

void quicksort(int l,int r){
        if(l <= r){
                int p = partition(l,r);
                quicksort(l,p-1);
                quicksort(p+1,r);
        }
}

void sort(int n){
        quicksort(0,n-1);
}

void solve(){
        ll n;
        cin >> n;
        string g;
        for(int i = 0; i < n; i++){
                cin >> g;
                vec.push_back(g);
        }
        sort(n);
        for(int i = 0; i < n ; i++){
                cout << vec[i] << "\n";
        }
}

int main(){
        solve();
        return 0;
}