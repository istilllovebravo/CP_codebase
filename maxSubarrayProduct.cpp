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

void printArray(int arr[], int n){
	for(int i=0; i<n; i++)	cout << arr[i] <<" ";
	cout <<endl;
}

void printVector(vector <int> v){
	for(int i=0; i<v.size(); i++)	cout << v[i] <<" ";
	cout <<endl;
}

pair <int,int> subarrayProduct(int arr[], int n){
	int currMaxProduct , currMinProduct , prevMaxProduct , prevMinProduct;
	currMaxProduct = currMinProduct = prevMaxProduct = prevMinProduct = arr[0];
	int globalMax = arr[0] , globalMin = arr[0];
	pair <int,int> res;
	for(int i=1; i<n; i++){
		currMaxProduct = largest(prevMaxProduct*arr[i] , prevMinProduct*arr[i] , arr[i]);
		currMinProduct = smallest(prevMinProduct* arr[i] , prevMaxProduct*arr[i] , arr[i]);
		globalMax  = max(globalMax , currMaxProduct);
		globalMin = min(globalMin , currMinProduct);
		prevMaxProduct = currMaxProduct;
		prevMinProduct = currMinProduct;
	}
	return {globalMax , globalMin};

}
 
int main(){
	fast_io; cout_precision;
	int n;	cin >>  n ; int arr[n];	for(int i=0; i<n; i++)	cin >> arr[i];
	pair <int, int>  res = subarrayProduct(arr,n);
	cout << res.fr <<" " <<res.sc<<endl;


	return 0;
}
