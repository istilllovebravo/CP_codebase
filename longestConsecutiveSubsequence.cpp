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
 
void longestConsecutiveSubsequence(int arr[], int n){
	sort(arr,arr+n);
	int maxLength = 0 , length = 0; int startIndex = 0 , endIndex= 0;
	for(int i=1; i<n; i++){
		if(arr[i] - arr[i-1] == 1){
			length++; 
			if(maxLength < length){
				maxLength = length;
				endIndex = i;
			}
		}
		else{
			startIndex  = i;
			length =  1;
		}
	}
	cout << maxLength <<endl;
	for(int i =startIndex ; i<=endIndex ; i++)
		cout << arr[i] <<" ";
	cout << endl;
}

int main(){
	fast_io; cout_precision;
	int n; cin >>n; int arr[n];	for(int i=0; i<n; i++)	cin >> arr[i];
	longestConsecutiveSubsequence(arr,n);


	return 0;
}
