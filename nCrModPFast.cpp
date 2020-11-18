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

const int M = 1e9 + 7;

int power(int a, int n){
    if(n == 0)  return 1;
    if(n == 1)  return a%M;
    if(n&1){
        return ((a%M) * (power(a,n-1))%M)%M;
    }
    int res = power(a,n/2)%M;
    return (res*res)%M;
}

const int N = 1000001;
int f[N];
int inverse[N];
int finverse[N];

void precomputation(){
    f[0] = f[1] = 1;
    for(int i=2; i<N; i++){
        f[i] = (f[i-1] * i)%M;
    }
    inverse[0] = inverse[1] = 1;
    for(int i=2; i<N; i++){
        inverse[i] = inverse[M%i] * (M - M/i)%M;
    }
    finverse[1] =1;
    for(int i=2; i<N; i++){
        finverse[i] = (finverse[i-1]%M * inverse[i]%M)%M;
    }
    return ;
}

int compute(int n, int r){ // returns nCr % M 
    if(n <r)    return -1;
    if(n == r)  return 1;
    if(r == 0)  return 1;
    int res = f[n];
    res  = (res * finverse[n-r])%M;
    res = (res  * finverse[r])%M;
    return res;
}

int32_t main(){
    fast_io;    cout_precision;
    precomputation();
    int q;  cin >> q;
    while(q--){
        int n,r;    cin >> n >> r;
        cout << compute(n,r) <<endl;
    }
    




    return 0;
}

