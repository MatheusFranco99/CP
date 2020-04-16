#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n, sum = 0, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        sum += x;
    }
    cout << sum;
    return 0;
}