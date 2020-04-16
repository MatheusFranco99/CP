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

const int nMax = 10000;

map <int,vector<int>> map1;
map <int,vector<int>> map2;
int aux[nMax];

const int tMax = 1000;
int freq[tMax];

int numDigits(int n){
        int numDigits = 0;
        while(n!= 0){
                numDigits++;
                n = int(n/10);
        }
        return numDigits;
}

void countsort(vector<int>* vec){
        int n = vec->size();
        for(int i = 0; i < tMax; i++){
                freq[i] = 0;
        }
        for(int i = 0; i < n; i++){
                aux[i] = vec->at(i);
                freq[vec->at(i)]++;
        }
        for(int i = 1; i < tMax; i++){
                freq[i] += freq[i-1];
        }
        for(int i = 0;i < n; i++){
                vec->at(freq[aux[i]]-1) = aux[i];
                freq[aux[i]]--;
        }
}

void solve(){
        int n1,n2;
        cin >> n1;
        int max = 0;
        int inp;
        for(int i = 0; i < n1;i++){
                cin >> inp;
                if(max < inp){
                        max = inp;
                }
                map1[int(inp/10)].push_back(inp%10);
        }
        cin >> n2;
        for(int i = 0; i < n2;i++){
                cin >> inp;
                if(max < inp){
                        max = inp;
                }
                map2[int(inp/10)].push_back(inp%10);
        }
        max = int(max/10);
        int maxDigits = numDigits(max);
        int maxElms = 0;
        for(auto c: map2){
                if(int(c.second.size()) > maxElms)
                        maxElms = c.second.size();
        }
        int sizePts = 0;
        for(int i = 0; i <= max; i++){
                if(map1[i].size() + map2[i].size() == 0){
                        continue;
                }
                sizePts = maxElms - map2[i].size();
                for(int j = 0; j < sizePts; j++){
                        cout << '.';
                }
                countsort(&map2[i]);
                reverse(map2[i].begin(),map2[i].end());
                for(auto j: map2[i]){
                        cout << j;
                }
                cout << ".|";
                sizePts = maxDigits - numDigits(i);
                for(int j = 0; j < sizePts; j++){
                        cout << '.';
                }
                cout << i;
                cout << "|.";

                countsort(&map1[i]);
                for(auto j: map1[i]){
                        cout << j;
                }
                cout << endl;
        }
}

int main(){
        solve();
        return 0;
}