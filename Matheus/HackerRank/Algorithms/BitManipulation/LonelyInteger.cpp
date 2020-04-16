#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){
        int N;
        scanf("%d",&N);
        /*std::vector<int> *lst = new vector<int>(N);
        int i = 0;
        for(;i < N; i++){
                scanf("%d",&lst->at(i));
        }
        */
        int r = 0;
        int i = 0, u;
        for(;i < N; i++){
                scanf("%d",&u);
                r = r xor u;
        }
        printf("%d\n",r);

}