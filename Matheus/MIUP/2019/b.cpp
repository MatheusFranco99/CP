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

#define POINT '.'
#define PLANT 'P'
#define DRAGON 'D'

using namespace std;

string trajec;

void solve(){
    int dl,dh,E,j,p,l;
    ll x,a,b,m;
    scanf("%d %d %lld %lld %lld %lld %d %d %d %d",&dl,&dh,&x,&a,&b,&m,&E,&j,&p,&l);
    cin >> trajec;
    int energy = E;
    int energyConsumed = 0;
    int totalWalk = 0;
    int position = 0;
    int delta = 0;
    int forward = 1;
    int previous = 0;
    while(energy > 0){
        x = (a * x + b)%m;
        delta = (dl + (x%(dh-dl+1)));

        previous = position;

        if(energy >= j){
            position += forward*delta;
            if(position > l){
                totalWalk += l-previous;
                break;
            }
            else if(position < 0){
                totalWalk+= previous;
                position = 0;
            }
            else{
                totalWalk+= delta;
            }
            energy -= j;
            energyConsumed+= j;
        }
        else{
            energyConsumed += energy;
            energy = 0;
        }
        if(forward == -1){
        }
        forward = 1;

        if(position >= l){
            break;
        }
        if(position < 0){
            position = 0;
        }
        if(trajec[position] == PLANT){
            energy += p;
            trajec[position] = POINT;
        }
        else if(trajec[position] == DRAGON){
            forward = -1;
        }
    }
    cout << totalWalk << endl << energyConsumed << endl;
    if(energy > 0){
        puts("yes");
    }
    else{
        puts("no");
    }
}



int main(){
        solve();
        return 0;
}