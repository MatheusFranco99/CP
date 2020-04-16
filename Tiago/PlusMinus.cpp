#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, el; float pos = 0, neg = 0, nul = 0;
    cin >> n;
    cin >> el;

    for (int i = 0; i < n; i++, cin >> el) {
        if(el > 0){
            pos++;
        }
        else if(el < 0){
            neg++;
        }
        else nul++;
    }
    cout << pos/n << endl << neg/n << endl << nul/n << endl;

    return 0;
}