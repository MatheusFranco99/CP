#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

/*

Thinking:

    4 2
    1 2 3 4

    {1,4}

    4 3
    1 2 3 4

    {1,2,3}

    5 3
    5 3 4 2 6

    {4,2,6}

    6 4
    5 3 50 2 4 5

    {5,3,50,2}



*/

int minLst(int lst[],int start,int end){
    if(start > end){
        return -1;
    }
    int min = lst[start];
    rep(i,start,end){
        if(lst[min] > lst[i]){
            min = i;
        }
    }
    return min;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int lst[n];
    rep(i,0,n){
        cin >> lst[i];
    }
    int m = minLst(lst,0,n);
    cout << m << endl;
    vector<int> ans;
    ans.pb(lst[m]);
    int size = 1;
    while(size < k){
        
    }
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        solve();
        return 0;
}