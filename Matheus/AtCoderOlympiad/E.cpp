#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int main(){
        int X,Y,A,B,C;
        scanf("%d %d %d %d %d",&X,&Y,&A,&B,&C);
        std::vector<long long> *red = new vector<long long>(A);
        std::vector<long long> *green = new vector<long long>(B);
        std::vector<long long> *colorless = new vector<long long>(C);
        int i = 0;
        for(; i < A; i++){
                scanf("%d",&red->at(i));
        }
        for(i = 0; i < B; i++){
                scanf("%d",&green->at(i));
        }
        for(i = 0; i < C; i++){
                scanf("%d",&colorless->at(i));
        }
        
        return 0;
}