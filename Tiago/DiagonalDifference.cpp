#include <bits/stdc++.h>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i][i] - arr[i][arr.size()-(i+1)];
    }
    return fabs(sum);
}

int main()
{
    int n, k;
    cin >> n;
    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> k;
            arr[i][j] = k;
        }
    }

    int result = diagonalDifference(arr);
    cout << result;
    return 0;
}