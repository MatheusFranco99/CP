#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#define ll long long
#include <stack>

using namespace std;

const int highestTime = 24*60;
const int nMax = 1000;
int s[nMax];
int e[nMax];
int saux[nMax];
int eaux[nMax];
int freq[highestTime];
int reversePermutation[nMax];

void countsort(int n){
        for(int i = 0; i < n; i++){
                saux[i] = s[i];
                eaux[i] = e[i];
        }
        for(int i = 0; i < highestTime; i++){
                freq[i] = 0;
        }
        for(int i = 0; i < n; i++){
                freq[saux[i]]++;
        }
        for(int i = 1; i < highestTime; i++){
                freq[i] += freq[i-1];
        }
        for(int i = 0; i < n; i++){
                s[freq[saux[i]]-1] = saux[i];
                e[freq[saux[i]]-1] = eaux[i];
                reversePermutation[freq[saux[i]]-1] = i;
                freq[saux[i]]--;
        }
}

string applyPermutation(string *answer){
        int len = answer->size();
        string nova(len,0);
        for(int i = 0; i < len; i++){
                nova[reversePermutation[i]] = answer->at(i);
        }
        return nova;
}

void solveTest(){
        int n;
        string answer;
        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> s[i] >> e[i];
        }
        countsort(n);


        int C = 0, J = 1;
        answer.append("CJ");
        for(int i = 2; i < n; i++){
                if(e[C] <= s[i]){
                        C = i;
                        answer.append("C");
                }
                else if(e[J] <= s[i]){
                        J = i;
                        answer.append("J");
                }
                else{
                        cout << "IMPOSSIBLE\n";
                        return;
                }
        }
        cout << applyPermutation(&answer) << "\n";

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