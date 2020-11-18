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

bool dp[1001][1001];

void display(vector <int> a){
	int n = a.size();
	for(int i=0; i<n; i++){
		cout << a[i] <<" ";
	}
	cout << endl;
}

//here v stores the indexes and not the actual values
vector <int> getSubset(vector <int> a , int num , int sum ,  vector <int> &v){
	if(num == 1 && sum == 0){
		return v;	
	}
	if(num == 1 && sum != 0 && dp[num][sum]){
		v.pb(num-1);
		return v;
	}
	if(dp[num-1][sum]){
		vector <int> _v = v;
		// display(v);
		return getSubset(a, num-1, sum, _v);
	}
	if(sum - a[num-1] >=0 && dp[num-1][sum- a[num-1]]){
		v.pb(num-1);
		return getSubset(a, num-1 , sum - a[num-1] , v);
	}
	vector <int> temp;
	
	return temp;
}

bool subsetSum(vector <int> a , int sum){ // returns whether there exist a subset in a whose sum is sum
	memset(dp , 0 , sizeof(dp));
	int n = a.size();
	for(int i=0; i<=n; i++){
		dp[i][0] = 1;
	}
	for(int j=1; j<=sum; j++){
		dp[0][j] = 0;
	}

	for(int i=1; i<=n; i++){
		for(int j=0; j<=sum; j++){
			dp[i][j] = dp[i-1][j];
			if(j - a[i-1] >=0 )	dp[i][j] |= dp[i-1][j-a[i-1]];
		}
	}
	vector <int> temp;
	vector <int> v = getSubset(a, n , sum , temp);
	display(v); // print the indexes required to get given sum

	return dp[n][sum];

}


int32_t main(){
	fast_io;	cout_precision;
	int n;	cin >> n;
	vector <int> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int sum;	cin >> sum;
	cout << subsetSum(a,sum) <<endl;	

	return 0;
}

