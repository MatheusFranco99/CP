#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>



int main(){
        int N, X, Y;
        scanf("%d %d %d",&N,&X,&Y);
        int numWays = 0;
        int j;
        for(int i = 1; i < N; i++){
                numWays = 0;
                for(j = 1; j <= X; j++){
                        if(j+i <= X){
                                numWays++;
                        }
                        else{
                                if( j + i < Y){
                                        numWays++;
                                }
                                if( j + i + (Y-1-X) <= N ){
                                        numWays++;
                                }
                        }
                }
                for(j = X+1; j<N; j++){
                        if(j + i <= N)
                                numWays++;
                }
                printf("%d\n",numWays);
        }
        return 0;
}