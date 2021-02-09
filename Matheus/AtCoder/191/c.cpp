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

void solve(){
    int h = 1,w = 1;
    cin >> h >> w;
    int s[h][w];

    char c;
    
    rep(i,0,h){
        rep(j,0,w) 
        {
            cin >> c;
            if(c == '.') s[i][j] = 0;
            else if(c == '#') s[i][j] = 1;
            else{
                cout << "ERROR : char unkown" << endl;
            }
        }
    }
    // rep(i,0,h){rep(j,0,w)cout << s[i][j];cout << endl;}
    int ans = 0;
    int same_side1 = 0;
    int same_side2 = 0;
    rep(j,0,w-1){
        same_side1 = 0;
        same_side2 = 0;
        rep(i,0,h){
            if(s[i][j] == 0 && s[i][j+1] == 0){
                same_side1 = 0;
                same_side2 = 0;
            }
            else if(s[i][j] == 0 && s[i][j+1] == 1){
                if(same_side1 == 0){
                    ans++;
                    same_side1 = 1;
                }
            }
            else if(s[i][j] == 1 && s[i][j+1] == 0){
                if(same_side2 == 0){
                    ans++;
                    same_side2 = 1;
                }
            }
            else if(s[i][j] == 1 && s[i][j+1] == 1){
                same_side1 = 0;
                same_side2 = 0;
            }
        }
    }
    rep(i,0,h-1){
        same_side1 = 0;
        same_side2 = 0;
        rep(j,0,w){
            if(s[i][j] == 0 && s[i+1][j] == 0){
                same_side1 = 0;
                same_side2 = 0;
            }
            else if(s[i][j] == 1 && s[i+1][j] == 0){
                if(same_side1 == 0){
                    ans++;
                    same_side1 = 1;
                }
            }
            else if(s[i][j] == 0 && s[i+1][j] == 1){
                if(same_side2 == 0){
                    ans++;
                    same_side2 = 1;
                }
            }
            else if(s[i][j] == 1 && s[i+1][j] == 1){
                same_side1 = 0;
                same_side2 = 0;
            }
        }
    }
    cout << ans << endl;
}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t;
        t = 1;
        while(t--){
            solve();
        }
        return 0;
}