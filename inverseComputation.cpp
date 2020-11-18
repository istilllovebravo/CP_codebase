#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define cout_precision cout.setf(ios::fixed); cout.precision(32);
#define M int(1e9+7)
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

int power(int a, int n){
    if(n == 0)  return 1;
    if(n == 1)  return a;
    if(n&1) return ((a%M) * (power(a,n-1)%M))%M;
    int res = power(a,n/2)%M;
    return (res*res)%M;
}




int extendedEuclid(int a, int b, int &x, int &y){
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

int _inverse(int a, int m){ // inverse of a modulo m
    if(__gcd(a,m) != 1) return -1; // inverse doesnt exist if a and m are not coprime
    int x,y;
    extendedEuclid(a,m,x,y); //here x is out modulo inverse
    x = (x%m+m)%m; // this is for cases like  (a,m) = (8,3) where x = -1 and y = 3
    return x;
}



void fastInverseComputation(){ // here inverse[i] gives inverse of i modulo M
    const int N = 1000001;
    int inverse[N];
    inverse[0] = inverse[1] = 1;
    for(int i=2; i<N; i++){
        inverse[i] = (inverse[M%i] * (M - M/i))%M;
    }
    return ;
}


int32_t main(){
    fast_io;    cout_precision;
    int a,m;
    cin >> a >> m;
    cout << __gcd(a,m) <<endl;
    cout << _inverse(a,m) <<endl;
    fastInverseComputation();
    
    return 0;
}

