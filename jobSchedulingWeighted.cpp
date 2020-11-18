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

struct Job{
	int start , finish , profit;
} ;

bool comp(Job j1 , Job j2){
	return j1.finish < j2.finish;
}

int latestNonConlfictJob(Job arr[], int index){ 
	int l = 0 , r = index -1 ;
	while(l<=r){
		int mid = (l+r)/2;
		if(arr[mid].finish <= arr[index].start){
			if(arr[mid+1].finish <= arr[index].start)	l = mid+1;
			else	return mid;
		}
		else{
			r = mid-1;
		}
	}
	return -1;
}

int getMaxProfit(Job arr[], int n){
	if(n == 1)	return arr[0].profit;

	int includingProfit = arr[n-1].profit;
	int index = latestNonConlfictJob( arr,  n-1);
	if(index != -1)	includingProfit+=getMaxProfit(arr,index+1);

	int excludingProfit = getMaxProfit(arr,n-1);

	return max(includingProfit , excludingProfit);
}

int maxProfit(Job arr[], int n){
	sort(arr,arr+n,comp);
	return getMaxProfit(arr,n);
}

int maxProfitByDP(Job arr[], int n){
	int dp[n];	dp[0] = arr[0].profit;
	for(int i=1; i<n; i++){
		int includingProfit = arr[i].profit;
		int index = latestNonConlfictJob(arr,i);
		if(index != -1)	includingProfit += dp[index];
		dp[i] = max(dp[i-1] , includingProfit);
	}
	return dp[n-1];
}

int main(){
	fast_io; cout_precision;
	int n;	cin >> n;	
	Job arr[n];
	for(int i=0; i<n; i++)	cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
	cout << maxProfitByDP(arr,n) <<endl;

	return 0;
}
