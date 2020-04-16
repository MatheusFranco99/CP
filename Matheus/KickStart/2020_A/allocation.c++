#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGE 1000

void countingSort(int A[],int len){
        int count[RANGE + 1];
        int answer[len], i = 0;
        memset(count, 0, sizeof(count));
        for(; i < len; i++){
                count[A[i]]++;
        }
        for(i = 1; i <= RANGE; i++){
                count[i] += count[i-1];
        }
        for(i = 0; i < len; i++){
                answer[count[A[i]]-1] = A[i];
                count[A[i]]--;
        }
        for(i = 0; i < len; i++){
                A[i] = answer[i];
        }

}

int main(){
        int T,N,B,i,answer,cases;
        scanf("%d",&T);
        int prices[100000];
        cases = 1;
        while(cases <= T){
                scanf("%d %d",&N,&B);
                for(i = 0; i < N; i++){
                        scanf("%d",&prices[i]);
                }
                prices[i] = -1;
                countingSort(prices,N);
                answer = 0;
                i = 0;
                while(prices[i] != -1){
                        if(prices[i]>B){
                                break;
                        }
                        B = B - prices[i];
                        answer++;
                        i++;
                }
                printf("Case #%d: %d\n",cases,answer);
                cases++;
        }
}