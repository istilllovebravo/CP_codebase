#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define cout_precision cout.setf(ios::fixed); cout.precision(18);
#define clr(a) memset(a,0,sizeof(a))
#define umap unordered_map
#define uset unordered_set
#define fr first
#define sc second
#define pb push_back
#define pf push_front
#define M int(1e9+7)
#define endl '\n'
#define largest(a,b,c) (a>b?(a>c? a:c):(b>c? b:c))
#define smallest(a,b,c) (a<b?(a<c? a:c):(b<c? b:c))
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


using ll = int64_t; using vll = vector<ll>; using vvll = vector<vll>;
using pll = pair<ll, ll>; using vpll = vector<pll>; using vvpll = vector<vpll>;

ll power(ll a, ll n){
	if(n == 0)	return 1;
	if(n == 1)	return a%M;
	if(n&1){
		return a*power(a,n-1);
	}
	ll res = power(a,n/2);
	return (res*res)%M;
}

int main() {
	fast_io; cout_precision;
	int n;	cin >> n;
	int k;	cin >> k;
	
	vector <int> arr(n, 0);
	for(int i=n-1; i>=n-k; i--){
		arr[i] = 1;
	}
	do{
		for(int i=0; i<n; i++){
			cout << arr[i];
		}
		cout << endl;
	}while(next_permutation(arr.begin() , arr.end()));
	

	return 0;
}
