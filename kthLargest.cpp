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

bool comp(int a , int b){
	return (a > b);
}
 
int main(){
	fast_io; cout_precision;
	int n;	cin >>  n ; int arr[n];	for(int i=0; i<n; i++)	cin >> arr[i];
	int k;	cin >> k;
	nth_element(arr,arr+k-1, arr+n,comp);
	cout << arr[k-1] <<endl;


	return 0;
}
