#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define cout_precision cout.setf(ios::fixed); cout.precision(32);
#define M int32_t(13)
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



int extendedEuclid(int a, int b, int &x, int &y){ // can be used to find inverse as well
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int g = extendedEuclid(b, a%b , x1,y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;

}

int inverse(int a, int m){ // inverse of a modulo m
    if(__gcd(a,m) != 1) return -1;
    int x,y;
    extendedEuclid(a,m,x,y);
    return x;
}



int32_t main(){
    fast_io;    cout_precision;
    int a,b;    cin >> a >> b;
    int x,y;
    int g = extendedEuclid(a,b,x,y);
    cout << a <<"*"<<x<<" + "<<b<<"*"<<y<<" = "<<g <<endl;
    
    return 0;
}

