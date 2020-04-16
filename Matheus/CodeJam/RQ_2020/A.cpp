#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#define ll long long

using namespace std;

const int nMax = 100;
int M[nMax][nMax];

void solveTestI(){
        int N;
        cin >> N;
        for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                        cin >> M[i][j];
                }
        }
        ll trace = 0;
        for(int i = 0; i < N; i++){
                trace+= M[i][i];
        }
        
        int repRow = 0, repCol = 0;

        for(int i = 0; i < N; i++){
                set<int> s;
                for(int j = 0; j < N; j++){
                        if(s.find(M[i][j]) != s.end()){
                                repRow++;
                                break;
                        }
                        s.insert(M[i][j]);
                }
        }
        for(int i = 0; i < N; i++){
                set<int> s;
                for(int j = 0; j < N; j++){
                        if(s.find(M[j][i]) != s.end()){
                                repCol++;
                                break;
                        }
                        s.insert(M[j][i]);
                }
        }
        cout << trace << " " << repRow << " " << repCol << "\n";
}

int main(){
        int T;
        cin >> T;
        for(int i = 1; i<= T; i++){
                cout << "Case #" << i << ": ";
                solveTestI();
        }
        return 0;
}