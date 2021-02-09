#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

/*

Thinking:

         11
         22
       21  23

*/


void solve(){
    int s,ra,pa,rb,pb,c;
    cin >> s >> ra >> pa >> rb >> pb >> c;
    if(ra == 1 && pa == 1){
        pa = 2;
    }
    if(rb == 1  && pb == 1){
        pb = 2;
    }
    ra--;
    rb--;
    pa--;
    pb--;
    // s = 2
    vector<pair<int,int>> uc(c);
    rep(i,0,c){
        cin >> uc[i].first >> uc[i].second;
    }
    if(c == 2){
        cout << 0 << endl;
        return;
    }
    int grid[2][3] = {{-1,0,-1},{0,0,0}};
    grid[ra][pa] = 1;
    grid[rb][pb] = 2;
    for(auto p : uc){
        grid[p.first-1][p.second-1] = -1;
    }
    int ans = 0;
    // firstt
    if(ra-1 >=0){
        if(grid[ra-1][pa] == 0){
            ans++;
            ra--;
            grid[ra][pa] = 1;
        }
    }
    if(ra+1 < 2){
        if(grid[ra+1][pa] == 0){
            ans++;
            ra++;
            grid[ra][pa] = 1;
        }
    }
    if(pa+1<=2){
        if(grid[ra][pa+1] == 0){
            ans++;
            pa++;
            grid[ra][pa] = 1;
        }
    }
    if(pa-1>=0){
        if(grid[ra][pa-1] == 0){
            pa--;
            ans++;
            grid[ra][pa] = 1;
        }
    }

    //second
    if(rb-1 >=0){
        if(grid[rb-1][pb] == 0){
            ans--;
            rb--;
            grid[rb][pb] = 2;
        }
    }
    if(rb+1 < 2){
        if(grid[rb+1][pb] == 0){
            ans--;
            rb++;
            grid[rb][pb] = 2;
        }
    }
    if(pb+1<=2){
        if(grid[rb][pb+1] == 0){
            ans--;
            pb++;
            grid[rb][pb] = 2;
        }
    }
    if(pb-1>=0){
        if(grid[rb][pb-1] == 0){
            pb--;
            ans--;
            grid[rb][pb] = 2;
        }
    }

    // firstt
    if(ra-1 >=0){
        if(grid[ra-1][pa] == 0){
            ans++;
            ra--;
            grid[ra][pa] = 1;
        }
    }
    if(ra+1 < 2){
        if(grid[ra+1][pa] == 0){
            ans++;
            ra++;
            grid[ra][pa] = 1;
        }
    }
    if(pa+1<=2){
        if(grid[ra][pa+1] == 0){
            ans++;
            pa++;
            grid[ra][pa] = 1;
        }
    }
    if(pa-1>=0){
        if(grid[ra][pa-1] == 0){
            pa--;
            ans++;
            grid[ra][pa] = 1;
        }
    }

    //second
    if(rb-1 >=0){
        if(grid[rb-1][pb] == 0){
            ans--;
            rb--;
            grid[rb][pb] = 2;
        }
    }
    if(rb+1 < 2){
        if(grid[rb+1][pb] == 0){
            ans--;
            rb++;
            grid[rb][pb] = 2;
        }
    }
    if(pb+1<=2){
        if(grid[rb][pb+1] == 0){
            ans--;
            pb++;
            grid[rb][pb] = 2;
        }
    }
    if(pb-1>=0){
        if(grid[rb][pb-1] == 0){
            pb--;
            ans--;
            grid[rb][pb] = 2;
        }
    }
    cout << ans << endl;

}

int main(){
        ios::sync_with_stdio(0);
	    cin.tie(0);
        int t,x;
        cin >> t;
        x = 1;
        while(x <= t){
            cout << "Case #" << x << ": ";
            solve();
            x++;
        }
        return 0;
}