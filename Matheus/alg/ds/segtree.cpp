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

const ll INF = 1e9+10;

template <typename T>
struct SegmentTreeRMQ{
    int n;
    vector<T> tree;
    vector<int> m_index;
    bool compare(T a, T b){
        // Maximum Query
        if(a >= b) return 1;
        else return 0;
        /* Minimum Query
        if(a <= b) return 1;
        else return 0;
        */
    }
    SegmentTreeRMQ(vector<T> &v){
        n = v.size();
        tree = vector<int>(n*2,0);
        m_index = vector<int>(n*2,0);

        for(int i = n; i < 2 * n; i++){
            tree[i] = v[i-n];
            m_index[i] = i-n;
        }

        for(int i = n-1; i > 0; i--){
            if( compare(tree[2*i],tree[2*i+1]) ){
                tree[i] = tree[2*i];
                m_index[i] = m_index[2*i];
            }
            else{
                tree[i] = tree[2*i+1];
                m_index[i] = m_index[2*i+1];
            }
        }
    }
    void update(int i, T v){
        i += n;
        tree[i] = v;
        while(i > 1){
            i = i/2;
            T newV = 0;
            if(compare(tree[2*i],tree[2*i+1]))  newV = tree[2*i];
            else                                newV = tree[2*i+1];

            if(compare(tree[2*i],tree[2*i+1]))  m_index[i] = m_index[2*i];
            else                                m_index[i] = m_index[2*i+1];

            if(tree[i] != newV) tree[i] = newV;
            else return;
        }
    }
    int queryIndex(int from, int to){
        int ans_index = from;
        from += n;
        to += n;
        T ans = -INF;
        while(from < to){
            if(from&1){ // if from is odd, we go to next even
                if(compare(tree[from],ans)) ans_index = m_index[from];
                if(compare(tree[from],ans)) ans = tree[from];

                from++;
            }
            if(to&1){ // if to is odd, we can also use the parent
                to--;
                if(compare(tree[to],ans)) ans_index = m_index[to];
                if(compare(tree[to],ans)) ans = tree[to];
            }
            from /= 2; // go to next level
            to /= 2;
        }
        return ans_index;
    }
    T queryValue(int from,int to){ // form inclusive, to exclusive
        return tree[queryIndex(from,to) + n];
    }
    void print(){
        for(int i = 0; i < 2 * n; i++) cout << tree[i] << " ";
        cout << endl;
    }

};

void solve(){
    // int v1[10] = {4,6,1,4,2,7,-15,80,26,50};
    // vector<int> v(10,0);
    // rep(i,0,10) v[i] = v1[i];
    // SegmentTreeRMQ<int> a(v);
    // a.print();
    // cout << a.queryIndex(3,7) << endl;
    // cout << a.queryValue(3,7) << endl;
}

int main(){
        ios::sync_with_stdio(0);
	cin.tie(0);
        solve();
        return 0;
}
