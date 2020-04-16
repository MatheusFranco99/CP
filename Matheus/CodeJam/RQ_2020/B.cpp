#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#define ll long long
#include <stack>

using namespace std;

const int sMax = 100;
string c(sMax,0);

void solveTest(){
        string answer;
        c.clear();
        cin >> c;
        int diff;
        int stack = 0;
        for(char a : c){
                diff = int(a) - 48 - stack;
                if(diff > 0){ // number is bigger
                        answer.append(diff,'(');
                        stack += diff;
                }
                else if(diff < 0){ //number is smaller
                        answer.append(-diff,')');
                        stack += diff; //diff is negative
                }
                answer.append(1,a);
        }
        if(stack > 0){
                answer.append(stack,')');
        }
        cout << answer << "\n";
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