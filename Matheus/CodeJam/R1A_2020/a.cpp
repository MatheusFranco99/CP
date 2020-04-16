#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <string>
#include <bits/stdc++.h>
#include <set>
#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

using namespace std;

vector<string> l;

int adjust(int a, int b){
    //cout << l[a] << endl;
    //cout << l[b] << endl;
    string nova;
    string A = l[a];
    string B = l[b];
    int i = A.size()-1;
    int j = B.size()-1;
    while(i != 0 && j != 0){
        //cout << "comparing : " << A[i] << " " << B[j] << endl;
        if(A[i] == B[j]){
            nova.push_back(A[i]);
            i--;
            j--;
            continue;
        }
        if(A[i] != B[j]){
            if(A[i] == '*'){
                nova.push_back(B[j]);
                j--;
                continue;
            }
            else if(B[j] == '*'){
                nova.push_back(A[i]);
                i--;
            }
            else if(i < A.size() -1 && A[i+1] == '*'{

            }
            else{
                return 0;
            }
        }
    }
    if( i == 0 && j == 0){
        if(A[i] == B[j]){
            nova.push_back(A[i]);
        }
    }
    else if(j > 0){
        while(j >= 0){
            nova.push_back(B[j]);
            j--;
        }
    }
    else if(i > 0){
        while(i >= 0){
            nova.push_back(A[i]);
            i--;
        }
    }
    reverse(nova.begin(),nova.end()); 
    l[a].clear();
    l[b].clear();
    l[a] = nova;
    l[b] = nova;
    //cout << "nova : " << nova << endl;
    //cout << l[a] << endl;
    //cout << l[b] << endl;
    return 1;
}


void solve(){
    int n;
    cin >> n;
    l.clear();
    string aux;
    for(int i = 0; i < n; i++){
        cin >> aux;
        l.push_back(aux);
    }
    int ans = 1;
    for(int i = 0; i < n-1; i++){
        if(adjust(i,i+1) == 0){
            ans = 0;
            break;
        }
    }
    if(ans == 0){
        cout << "*\n";
    }
    else{
        string ans;
        for(auto c : l[n-1]){
            if(c!='*'){
                ans.push_back(c);
            }
        }
        cout << ans << endl;
    }
    
}

int main(){
        int t;
        cin >> t;
        for(int i = 1; i <= t; i++){
            cout << "Case #" << i << ": ";
            solve();
        }
        return 0;
}




/**
 *    author:  tourist
 *    created: 11.04.2020 03:52:40       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
      cin >> strs[i];
    }
    string pref = "";
    string suf = "";
    vector<string> sub;
    bool ok = true;
    for (string& s : strs) {
      int last = -1;
      for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '*') {
          if (last == -1) {
            string other_pref = s.substr(0, i);
            if (other_pref.size() > pref.size()) {
              swap(pref, other_pref);
            }
            if (pref.substr(0, other_pref.size()) != other_pref) {
              ok = false;
              break;
            }
          } else {
            sub.push_back(s.substr(last + 1, i - last - 1));
          }
          last = i;
        }
      }
      if (!ok) {
        break;
      }
      string other_suf = s.substr(last + 1);
      if (other_suf.size() > suf.size()) {
        swap(suf, other_suf);
      }
      if (suf.substr(suf.size() - other_suf.size()) != other_suf) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "*" << '\n';
    } else {
      cout << pref;
      for (auto& s : sub) {
        cout << s;
      }
      cout << suf << '\n';
    }
  }
  return 0;
}



/**
 *    author:  tourist
 *    created: 11.04.2020 04:17:10       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ":\n";
    int n;
    cin >> n;
    int rows = min(30, n);
    n -= rows;
    vector<int> a(rows);
    for (int row = rows - 1; row >= 0; row--) {
      if (n >= (1 << row) - 1) {
        a[row] = 1;
        n -= (1 << row) - 1;
      }
    }
    rows += n;
    a.resize(rows);
    int side = 0;
    for (int row = 0; row < rows; row++) {
      if (a[row] == 1) {
        if (side == 0) {
          for (int j = 0; j <= row; j++) {
            cout << row + 1 << " " << j + 1 << '\n';
          }
        } else {
          for (int j = row; j >= 0; j--) {
            cout << row + 1 << " " << j + 1 << '\n';
          }
        }
        side ^= 1;
      } else {
        if (side == 0) {
          cout << row + 1 << " " << 1 << '\n';
        } else {
          cout << row + 1 << " " << row + 1 << '\n';
        }
      }
    }
  }
  return 0;
}