#include <bits/stdc++.h>
using namespace std;
	 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define cout_precision cout.setf(ios::fixed); cout.precision(32);
#define clr(a) memset(a,0,sizeof(a))
#define umap unordered_map
#define uset unordered_set
#define fr first
#define sc second
#define pb push_back
#define M int(1e9+7)
#define endl '\n'
	
using ll = int64_t; using vll = vector<ll>; using vvll = vector<vll>;
using pll = pair<ll, ll>; using vpll = vector<pll>; using vvpll = vector<vpll>;
 
int main(){
	fast_io; cout_precision;
	int n;	cin >> n;	int arr[n];	for(int i=0; i<n; i++)	cin >> arr[i];
	double res = 0; // finds the median
	if(n&1){
		nth_element(arr,arr+(n-1)/2,  arr+n);
		res = arr[(n-1)/2];
	}

	else{
		nth_element(arr,arr+(n)/2,  arr+n);
		nth_element(arr,arr+(n-2)/2,  arr+n);
		res = (double)(arr[n/2] + arr[(n-2)/2])/2;
	}

	cout << res <<endl;

	return 0;
}
