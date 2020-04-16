#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){
        int N, i;
        scanf("%d",&N);
        vector<int> lst(N);
        for(i = 0; i < N; i++){
                scanf("%d",&lst[i]);
        }
        int sum = 0;
        for(i = 0; i < N;i++){
                sum += (lst[i]);
        }
        cout << sum << endl;
        return 0;
}