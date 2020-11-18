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
#define largest(a,b,c) (a>b?(a>c? a:c):(b>c? b:c))
#define smallest(a,b,c) (a<b?(a<c? a:c):(b<c? b:c))	

using ll = int64_t; using vll = vector<ll>; using vvll = vector<vll>;
using pll = pair<ll, ll>; using vpll = vector<pll>; using vvpll = vector<vpll>;

int prefixCountAND[32][1000000];
int prefixCountOR[32][1000000];

int query(int arr[], int l, int r , int s , int t){
	int res = 0;
	for(int R = l+s-1; R<=r; R++){
		int num = 0;
		for(int bit=0; bit<32; bit++){
			int count = 0;
			if(l == 0)	count = prefixCountAND[bit][R];
			else	count = prefixCountAND[bit][R] - prefixCountAND[bit][l-1];
			if(count == R-l+1)	num  = ((num) | (1 << bit));
		}
		if(num >= t)	res++;	
	}

	return res;
}

int rangeOR(int arr[], int l , int r){
	int res = 0;
	for(int i=0; i<32; i++){
		int count = 0;
		if(l == 0)	count = prefixCountOR[i][r];
		else	count = prefixCountOR[i][r] - prefixCountOR[i][l-1];
		if(count)	res = ((res) | (1 << i));
	}
	return res;
}

int rangeAND(int arr[], int l , int r){
	int res = 0;
	for(int i=0; i<32; i++){
		int count = 0;
		if(l == 0)	count = prefixCountAND[i][r];
		else	count = prefixCountAND[i][r] - prefixCountAND[i][l-1];
		if(count == r-l+1)	res = ((res)|(1<<i));
	}
	return res;
}
 
int main(){
	fast_io; cout_precision;
	int n;	cin >> n; int arr[n];	for(int i=0; i<n; i++)	cin >> arr[i];
	for(int i=0; i<32; i++){
		prefixCountAND[i][0] = ((arr[0]>>i)&1);
		for(int j=1; j<n; j++){
			prefixCountAND[i][j]  = ((arr[j] >> i)&1);
			prefixCountAND[i][j] += prefixCountAND[i][j-1];
		}
	}
	for(int i=0; i<32; i++){
		prefixCountOR[i][0] = ((arr[0]>>i)&1);
		for(int j=1; j<n; j++){
			prefixCountOR[i][j]  = ((arr[j] >> i)&1);
			prefixCountOR[i][j] += prefixCountOR[i][j-1];
		}
	}
	/*int q;	cin >> q;
	while(q--){
		int l,r,s,t;	cin >> l >> r >> s >> t;
		cout << query(arr,l,r, s , t)<<endl;
	}*/
	int l,r;	cin >> l >> r;	cout << rangeAND(arr,l,r)<<endl;

	return 0;
}
