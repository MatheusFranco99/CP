#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORe(i,a,b) for(int i=a;i<=b;i++)
#define FORr(i,a,b) for(int i=a;i>b;i--)
#define FORre(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

template <typename T>
struct FenwickTree{
    vector<T> bit;
    int n;
    FenwickTree(int nn){
        n = nn;
        bit = vector<T>(n+1,0);
    }
    FenwickTree(vector<T> v):FenwickTree(v.size()){
        for(int i = 0; i < v.size(); i++) add(i,v[i]);
    }
    T sum(int idx){
        idx++;
        T sum = 0;
        while(idx > 0){
            sum = sum + bit[idx];
            idx = idx - (idx&(-idx));
        }
        return sum;
    }
    void add(int idx, T v){
        idx++;
        while(idx <= n){
            bit[idx] += v;
            idx = idx + (idx&(-idx));
        }
    }
    T get(int idx){
        return sum(idx) - sum(idx-1);
    }
    void printRealList(){
        for(int i = 0; i < n; i++){
            cout << get(i) << " ";
        }
        cout << endl;
    }
    void print(){
        for(int i = 0; i <= n; i++){
            cout << bit[i] << " ";
        }
        cout << endl;
    }
};

void countInversions(){
    vector<int> a(5,0);
    a[0] = 4;
    a[1] = 2;
    a[2] = 3;
    a[3] = 1;
    a[4] = 0;
    FenwickTree<int> ft(5);
    int inv = 0;
    rep(i,0,5){
        inv += i - ft.sum(a[i]);
        ft.add(a[i],1);
    }
    cout << inv << endl;
}

void solve(){
    countInversions();
}

int main(){
        ios::sync_with_stdio(0);
	cin.tie(0);
        solve();
        return 0;
}


