#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxXorBetween(int l,int r){
        int i = l, j, max = 0;
        for(; i < r;i++){
                for(j = i+1; j <= r; j++){
                        max = ( max > (i xor j) ? max : i^j );
                }
        }
        return max;
}

int maxXorBetweenFaster(int l, int r){
        return (1 << int(log2(l xor r)+1))-1;
}

int main(){
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",maxXorBetweenFaster(l,r));
        return 0;
}