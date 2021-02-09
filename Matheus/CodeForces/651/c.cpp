#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back

/*

Thinking:

    players: A - Ashishgup; F - FastestFinger; A starts;

    n:
    divide by odd divisors greather than 1
    dec 1 of n if it's greather than 1
    
    someone loses if find 1

    if n is odd, just divide it by itself and it will be 1

    if n is even ??
    ex: 2 -> dec 1
    4 -> dec 1, theres no divisors
    6 -> if div by 3 loses
    8 -> dec 1
    10 -> if divs by 5 loses

    when you dec a EVEN it will be odd and YOU WILL LOSE so you cant dec a even number
    (only it's 2);
    so you MUST divide by the ODD part, because the other will have a 2^n and will lose

    A starts -> if is odd, A wins
                if is even : if there's no odd divisors F wins
                             if ther's odd divisors:
                                if even dividir is > 2, A wins


    who has 1 loses
    who has 2 wins
    who has odd wins
    who has even with no odd divisors loses
    who has even with odd divisors and even div != 2, wins
    who has even with odd divisors and even = 2, loses the one who divides the odd by last
        if there are more then 1 divisors, win
        if there's only one odd, loses
*/

string A = "Ashishgup";
string F = "FastestFinger";

void solve(){
    int n;
    cin >> n;
    
    string ans = "";
    if(n == 1){
        ans = F;
        cout << ans << endl;
        return;
    }
    if(n == 2){
        ans = A;
        cout << ans << endl;
        return;
    }
    if(n%2 == 1){
        ans = A;
        cout << ans << endl;
        return;
    }
    int oddPart = n;
    while(oddPart%2 == 0){
        oddPart = oddPart/2;
    }
    if(oddPart == 1){
        ans = F;
        cout << ans << endl;
        return;
    }
    if((n/2)%2 == 0){
        ans = A;
        cout << ans << endl;
        return;
    }
    int t = n/2;
    // if t is prime, A loses, else A wins 
    int i = 3;
    while(i*i <= t){
        if(t%i == 0){
            ans = A;
            cout << ans << endl;
            return;
        }
        i+=2;
    }
    ans = F;
    cout << ans << endl;
    return;
}

void solve3(){
    int n;
    cin >> n;

    int winner = 1; // F
    while(true){
        if(n == 1){
            break;
        }
        if(n == 2){
            n = 1;
            winner = (winner +1)%2;
            continue;
        }
        if(n%2 == 1){
            n = 1;
            winner = (winner +1)%2;
            continue;
        }
        else{
            int oddPart = n;
            while(oddPart%2 == 0){
                oddPart = oddPart/2;
            }
            if(oddPart == 1){
                n = n-1;
                winner = (winner +1)%2;
            }
            else{
                n = n / oddPart;
                winner = (winner +1)%2;
            }
        }
    }
    if(winner == 0){
        cout << A;
    }
    if(winner == 1){
        cout << F;
    }
    cout << endl;
}

void solve2(){
    int n;
    cin >> n;
    
    string ans = "";
    if(n == 1){
        ans = F;
    }
    if(n == 2){
        ans = A;
    }
    else if(n%2 == 1 && n != 1){
        ans = A;
    } else{
        int oddPart = n;
        while(oddPart%2 == 0){
            oddPart = oddPart/2;
        }
        if(oddPart == 1){
            ans = F;
        }
        else{
            ans = A;
        }
    }
    cout << ans << endl;
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