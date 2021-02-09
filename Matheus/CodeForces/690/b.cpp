#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back



void solve(){
    int n;
    cin >> n;
    char c;
    string a;
    cin >> a;
    if(n < 4){ cout << "NO" << endl; return;}
    if(n == 4){
        if(a[0] == '2' && a[1] == '0' && a[2] == '2' && a[3] == '0'){
            cout << "YES" << endl; return;
        }
        else{cout << "NO" << endl; return;}
    }
    int ii = 0;
    int oo = 0;
    if(a[0] == '2'){
        ii++;
        if(a[1]=='0'){
            ii++;
            if(a[2] == '2'){
                ii++;
                if(a[3] == '0'){
                    ii++;
                }
            }
        }
    }
    if(a[n-1] == '0'){
        oo++;
        if(a[n-2]=='2'){
            oo++;
            if(a[n-3] == '0'){
                oo++;
                if(a[n-4] == '2'){
                    oo++;
                }
            }
        }
    }
    if(ii+oo >= 4){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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