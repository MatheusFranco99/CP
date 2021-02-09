#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

/*

Thinking:

    given a_1,...,a_2n
    remove 2 and selects any two to append a_i + a_j to b until a is empty
    b should have gcd > 1

    you will have E evens and O odds, you have that 2 | even+even and 2 | odd+odd then
    it's just necessary to put the combination of evens and odds that appear first
*/


void solve(){
    int n;
    cin >> n;
    vector<int> lst;
    int aux;
    int e = 0; int o = 0;
    rep(i,0,2*n){
        cin >> aux;
        lst.pb(aux);
    }
    int numberPrints = n-1;
    int e1 = -1; int e2 = -1; int o1 = -1; int o2 = -1;
    int en = 0; int on = 0;
    int i = 0;
    while(numberPrints > 0){
        if(lst[i]%2 == 0){
            if(e1 == -1){
                e1 = i;
            }
            else{
                e2 = i;
            }
            en++;
        }
        else{
            if(o1 == -1){
                o1 = i;
            }
            else{
                o2 = i;
            }
            on++;
        }
        i++;
        if(en == 2){
            cout << e1+1 << " " << e2+1 << endl;
            numberPrints--;
            e1 = -1;
            e2 = -1;
            en = 0;
        }
        if(on == 2){
            cout << o1+1 << " " << o2+1 << endl;
            numberPrints--;
            o1 = -1;
            o2 = -1;
            on = 0;
        }
    }
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
}