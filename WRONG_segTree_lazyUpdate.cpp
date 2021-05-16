#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define cout_precision cout.setf(ios::fixed); cout.precision(32);
#define pb push_back
#define pii pair <int,int>
#define INF LONG_LONG_MAX
#define endl '\n'
#define umap unordered_map

struct custom_hash { // umap <int,int , custom_hash > mp ;
    static uint64_t splitmix64(uint64_t x) {
        
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int n,h;
const int N = 100100;
int t[2*N];
int d[N];
void build(){
    for(int i=n-1; i>0; i--){
        t[i] = t[i<<1] + t[i<<1|1];
    }
    return ;
}

void build(int pos){
    while(pos> 1){
        pos >>= 1;
        t[pos] = t[pos<<1] + t[pos<<1|1] + d[pos];
    }
    return ;
}

void apply(int pos,  int val){
    t[pos] += val;
    if(pos < n) d[pos] += val;
    return ;
}

void push(int p){
    for(int s = h; s > 0; s--){
        int i = p >> s;
        if(d[i] != 0){ // IMP
            apply(i<<1 , d[i]);
            apply(i<<1|1 , d[i]);
            d[i] = 0;
        }
    }
}

void rangeIncrement(int l, int r, int val){
    l+=n;
    r+=n;
    int l0 = l , r0 = r;
    for( ; l < r; l>>= 1, r>>=1){
        if(l&1) apply(l++ , val);
        if(r&1) apply(--r, val);
    }
    build(l0);
    build(r0-1);
    return ;
}

int query(int l, int r){
    int res = 0;
    l+=n;
    r+=n;
    push(l);
    push(r-1);
    for( ; l < r; l>>=1 , r>>=1){
        if(l&1) res += t[l++];
        if(r&1) res += t[--r];
    }
    return res;
}

int32_t main(){
    fast_io;    cout_precision;
    memset(d, 0 , sizeof(d));
    for(int i=0; i<N; i++)  t[i]  =0;
    cin >> n;
    h =  64 - __builtin_clzll(n);
    for(int i=0; i<n; i++){
        cin >> t[i+n];  
    }
    build();
    int q;  cin >> q;
    while(q--){
        int type;   cin >> type;
        if(type == 1){
            int l,r,val;    cin >>  l >> r >> val;
            l--;r--;
            rangeIncrement(l,r+1,val);
        }
        else{
            int l,r;    cin >> l >> r;
            l--;r--;
            cout << query(l,r+1) <<endl;
        }

    }
    for(int i=n; i<2*n; i++){
        cout << t[i] <<" ";
    }


    return 0;
}

