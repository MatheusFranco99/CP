#include "stdlib.h"
#include "stdio.h"

int main(){
        int N, success, i, a, b, d;
        while((scanf("%d",&N)) == 1){
                int table[N];
                success = 1;
                for(i = 1; i < N; i++){
                        table[N]=i;
                }
                scanf("%d",&a);
                for(i = 1; i < N; i++){
                        scanf("%d",&b);
                        d = abs(b-a);
                        if(d>0 && d < N) table[d]=0;
                        else{
                                printf("Not Jolly\n");
                                success = 0;
                                break;
                        }
                        a = b;
                }
                if(success==1){
                        for(i = 1; i <N;i++){
                                if(table[i]!=0){
                                printf("Not Jolly\n");
                                success = 0;
                                break;}
                        }
                }
                if(success==1){
                        printf("Jolly\n");
                }
        }
}