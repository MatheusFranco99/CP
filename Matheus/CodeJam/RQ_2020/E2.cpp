#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#define ll long long

using namespace std;

const int nMax = 50;
int M[nMax][nMax];
int possible[nMax];
int possibleaux[nMax];
int Mpossible[nMax][nMax];
int aux[nMax];

void setList(int lst[], int n, int elm){
        for(int i = 0; i < n; i++){
                lst[i] = elm;
        }
}

int takeMax(int lst[],int n){
        for(int i = n-1; i >= 0; i--){
                if(lst[i] == 1)
                        return i+1;
        }
        return -1;
}

void removePossibleRight(int possible[],int n,int row){
        for(int i = row; i < n; i++){
                possible[M[row][i]-1] = 0;
        }
}

void removePossibleTop(int possible[],int n,int row,int col){
        if(row == 0)
                return;
        for(int i = row -1; i >= 0; i--){
                possible[M[i][col]-1] = 0;
        }
}

void removePossibleTopIntoNew(int possible[],int n,int row,int col){
        if(row == 0)
                return;
        for(int i = row -1; i >= 0; i--){
                possible[M[i][col]-1] = 0;
        }
}

void printPossible(int possible[],int n){
        for(int i = 0; i < n; i++){
                cout << possible[i] << " ";
        }
        cout << "\n";
}

void copyLists(int from[],int to[], int n){
        for(int i = 0; i < n; i++){
                to[i] = from[i];
        }
}

void createPossibilityMatrix(int possible[],int n,int row){
        for(int i = 0; i < row; i++){
                copyLists(possible,Mpossible[i],n);
        }
}

void applyXorinLists(int i, int j){

}

void applyGaussianElimination(int n, int row){
        for(int i = )
}

void solveTest(){
        int n, k;
        cin >> n >> k;
        if(k > n*n){
                cout << "IMPOSSIBLE\n";
                return;
        }
        /*
        we want from part ((n-1)!) of all permutations (n!)
        such that the sum of all ith of ith row sum to k  
        */

        /* create diagonal */
        int kdecay = k-n;
        int elm = n;
        for(int i = 0; i < n; i++){
                M[i][i] = 1;
        }
        for(int i = 0; i < n; i++){
                if(kdecay == 0){
                        break;
                }
                elm = kdecay + M[i][i];
                if(elm > n) elm = n;
                M[i][i] = elm;
                kdecay -= elm-1;
        }

        /* create right triangle */
        for(int i = 0; i < n-1; i++){
                setList(possible,n,1);
                possible[M[i][i]-1] = 0;
                int k = n-1;
                for(int j = n-1; j > i; j--){
                        copyLists(possible,possibleaux,n);
                        possibleaux[M[k--][j]-1] = 0;
                        cout << i+1 << " " << j+1 << " " << M[k+1][j] << "\n";
                        removePossibleTopIntoNew(possible,n,i,j);
                        M[i][j] = takeMax(possibleaux,n);
                        if(M[i][j]==-1){
                                cout << "IMPOSSIBLE\n";
                                return;
                        }
                        possible[M[i][j]-1] = 0;
                }
        }

        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        cout << M[i][j] << " ";
                }
                cout << "\n";
        }

        setList(possible,n,1);
        removePossibleRight(possible,n,1);
        M[1][0] = takeMax(possible,n);
        setList(possible,n,1);
        removePossibleTop(possible,n,n-1,n-2);
        M[n-1][n-2] = takeMax(possible,n);

        for(int i = 2; i < n; i++){
                setList(possible,n,1);
                removePossibleRight(possible,n,i);
                createPossibilityMatrix(possible,n,i);
                for(int j = 0; j < i; j++){
                        removePossibleTopIntoNew(Mpossible[j],n,i,j); // removed elms from top
                        M[i][j] = takeMax(possibleaux,n);
                        if(M[i][j]==-1 && j = 0){
                                cout << "IMPOSSIBLE\n";
                                return;
                        }
                        else if(M[i][j] == -1 && j != 0){
                                int elmCant = M[i][j-1];
                                for(int k = 0; k < i; k++){
                                        Mpossible[k][M[i][j]-1] = 0;
                                }       
                        }
                        for(int k = 0; k < i; k++){
                                Mpossible[k][M[i][j]-1] = 0;
                        }
                }
        }

        for(int i = 2; i < n; i++){
                setList(possible,n,1);
                removePossibleRight(possible,n,i);
                createPossibilityMatrix(possible,n,i);
                for(int j = 0; j < i; j++){
                        removePossibleTopIntoNew(Mpossible[j],n,i,j); // removed elms from top
                }
                if(applyGaussianElimination(n,i)){
                        setElements(n,i);
                }else{
                        cout << "IMPOSSIBLE\n";
                        return;
                }
                
        }

        cout << "POSSIBLE\n";
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        cout << M[i][j] << " ";
                }
                cout << "\n";
        }
}

int main(){
        int T;
        cin >> T;
        for(int i = 1; i<= T; i++){
                cout << "Case #" << i << ": ";
                solveTest();
        }
        return 0;
}