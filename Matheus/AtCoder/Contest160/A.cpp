#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>



int main(){
        char *c = (char*)malloc(sizeof(char)*10);
        scanf("%s",c);
        printf("%s\n", ((c[2] == c[3] && c[4]==c[5]) ? "Yes":"No" ) );
        free(c);
        return 0;
}