#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int side(int x,int L){
        if(x <= L/2)
                return 1;
        if(x <= L/2 + L)
                return 2;
        if(x <= L/2 + 2*L)
                return 3;
        if(x <= L/2 + 3*L)
                return 4;
        return 5;
}

int sideMax(int x,int K){
        if(x == 1)
                return K/2;
        if(x==5)
                return K*4;
        return K/2 + (x-1)*K;
}
int sideMin(int x,int K){
        if(x == 1)
                return 0;
        if(x==5)
                return K/2 + 3*K;
        return K/2 + (x-2)*K;
}

int main(){
        int K, N;
        scanf("%d %d",&K,&N);
        long long a = 0;
        long long b = 0;
        long long d = 0;
        long long starter = 0;
        scanf("%lld",&a);
        starter = a;
        scanf("%lld",&b);
        d = b - a;
        a = b;
        for(int i = 2; i < N; i++){
                scanf("%lld",&b);
                if(b - a > d)
                        d = b-a;
                a = b;
        }
        if( K -(b - starter) > d){
                d = b-starter;
        }
        printf("%lld\n",K-d);
        return 0;
}