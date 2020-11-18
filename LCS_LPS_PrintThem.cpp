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

int lcs(string a, string b){
    int m = a.size() , n = b.size();
    int dp[m+1][n+1];   memset(dp, 0 , sizeof(dp));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1] == b[j-1])    dp[i][j] = 1 + dp[i-1][j-1];
            else    dp[i][j] = max(dp[i-1][j]  , dp[i][j-1]);
        }
    }
    //now print the lcs 
    int i = m , j = n;
    string res = "";
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]){
            res += a[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]  > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(res.begin() , res.end());
    cout << res <<endl;

    return dp[m][n];
}

int lps2(string str){ // lps = lcs(str, reverse of str)
    int n = str.size();
    string str_rev = str;   reverse(str_rev.begin() , str_rev.end());
    return lcs(str,  str_rev);
}

int lps1(string str){
    int n = str.size();
    int dp[n+1][n+1];   memset(dp, 0 , sizeof(dp));
    for(int i=0; i<n; i++)  dp[i][i] = 1;
    for(int len = 2; len <= n ; len++){
        for(int i=0; i<n; i++){
            int j = i+len-1;
            if(j >=n )  break;
            if(str[i] == str[j]){
                if(len == 2)    dp[i][j] = 2;
                else    dp[i][j] = 2 + dp[i+1][j-1];
            }
            else{
                dp[i][j] = max(dp[i+1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}   


int32_t main(){
    fast_io;    cout_precision;
    string a; cin >> a;
    cout << lps1(a) <<" "<<lps2(a) <<endl;




    return 0;
}

