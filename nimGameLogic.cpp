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


int32_t main(){
    fast_io;    cout_precision;
    srand(time(0));
    int n;  cin >> n;
    vector <int> a(n);
    int nimsum = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        nimsum = (nimsum) ^ (a[i]);
        sum += a[i];
    }
    string res = "Second";
    if(nimsum)  res = "First";
    cout << res <<endl;
    int turn = 0;
    while(1){
        if(nimsum == 0){
            //remove any number of stones from any pile
            for(int i=0; i<n; i++){ // Here i just removed 1 from the first non-zero pile
                // In general ,u can remove any number of stones from any piles.
                if(a[i]){
                    a[i]--;
                    break;
                }
            }
            for(int i=0; i<n; i++){
                nimsum = (nimsum) ^ (a[i]);
            }
        }
        else{
            //let i-th pile where bit at position p is set where p is the most signi bit of nimsum
            // then change a[i] -> a[i] ^ nimsum
            int pos = 64 - __builtin_clzll(nimsum);
            for(int i=0; i<n; i++){
                if((a[i] >> (pos-1))&1){
                    //change a[i] to a[i] ^ nimsum
                    a[i] = (a[i]) ^ (nimsum);
                    nimsum = 0;
                    // cout << "Change pile : "<<i<<" from "<<prev<<" to "<<newVal<<endl;
                    break;
                }
            }
        }
        bool flag = 1;
        for(int i=0; i<n ; i++){
            if(a[i])    flag = 0;
            cout << a[i] <<" ";
        }
        cout << endl;
        if(flag)    break;
    }

    



    return 0;
}

