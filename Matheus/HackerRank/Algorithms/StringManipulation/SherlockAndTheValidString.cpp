#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#define ll long long

using namespace std;

string c(100000,0);

void solve(){
        cin >> c;
        int len = c.size();
        vector<int> freq(26,0);
        // count frequencies
        for(auto a : c){++freq[a - 'a'];}
        /*
        for(auto a : freq)
                cout << a << " ";
        cout << "\n";
        */
        // find min
        int mostFrequency = 0;
        int mostFreq = 0;
        for(auto a : freq){
                if(a != 0){
                        int fq = 0;

                        for(auto b : freq){
                                if(a == b)
                                        fq++;
                        }
                        if(fq > mostFrequency ||(fq == mostFrequency && a > mostFreq)){
                                mostFrequency = fq;
                                mostFreq = a;
                        }
                }
        }
        //cout << "most freq " << mostFreq << "\n";
        // check validity
        int alreadySup = 0;
        for(auto a : freq){
                if(a != 0 && a > mostFreq+1 ){
                        puts("NO");
                        return;
                }
                else if(a!= 0 && a < mostFreq - 1 && a!= 1){
                        puts("NO");
                        return;
                }
                else if(a != mostFreq && a == 1){
                        if(alreadySup){
                                puts("NO");
                                return;
                        }
                        alreadySup = 1;
                }
                else if(a!= 0 && (a == mostFreq+1 || a == mostFreq - 1)){
                        if(alreadySup){
                                puts("NO");
                                return;
                        }
                        alreadySup = 1;
                }
        }
        puts("YES");
        return;
}

int main(){
        solve();
        return 0;
}