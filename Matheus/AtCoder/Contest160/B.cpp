#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>



int main(){
        long long Yen = 0;
        scanf("%lld",&Yen);
        int a = int(Yen/500);
        Yen -= a*500;
        int b = int(Yen/5);
        printf("%d\n", a*1000 + b * 5);
        return 0;
}