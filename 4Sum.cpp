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

bool commonIndex(int a, int b, int c, int d){
	if(a != b && a != c && a!= d && b!=c && b!= d && c != d)	return 0;
	return 1;
}

vector < vector <int> > fourSumV2(int arr[], int n, int sum){
	unordered_map <int, pair <int,int> > pairSum;
	set < vector <int> > s;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			pairSum[arr[i] + arr[j]] = {i,j};
		}
	}
	int l = 0 , r = (n*(n-1))/2;
	while(l  < r){
		int currSum = sum - arr[l] - arr[r];
		if(pairSum.find(currSum) != pairSum.end()){
			if(!commonIndex(l, r, pairSum[currSum].fr , pairSum[currSum].sc)){
				vector <int> temp;
				int i1 =  pairSum[currSum].fr , i2  =  pairSum[currSum].sc;
				temp.pb(arr[l]); temp.pb(arr[r]); temp.pb(arr[i1]); temp.pb(arr[i2]);
				for(int k = 0 ;k<4; k++){
					if(k!=3)	cout << temp[k] <<" ";
					else	cout << temp[k] <<endl;
				}

				s.insert(temp);
				temp.clear();
			}
		}
	}
	vector < vector <int> > res;
	for(auto i = s.begin(); i!= s.end(); i++)
		res.pb(*i);
	return res;

}
 
vector < vector <int> >  fourSum1(int arr[], int n, int sum){
	vector < vector <int> > res;
	set < vector <int> > resSet;
	for(int i=0; i<n-3; i++){
		for(int j=i+1; j<n-2; j++){
			int l = i+2 , r = n-1;
			int currSum = sum - arr[i] - arr[j];
			while(l < r){
				int s = arr[l] + arr[r];
				if(s == currSum){
					vector <int> temp;	temp.pb(arr[l]); temp.pb(arr[r]);	temp.pb(arr[i]); temp.pb(arr[j]);
					sort(temp.begin() , temp.end());
					resSet.insert(temp);
					l++; r--;
				}
				else if(s > currSum)
					r--;
				else	l++;
			}
		}
	}
	for(auto i = resSet.begin(); i!= resSet.end(); i++)
		res.pb(*i);
	return res;
}

int main(){
	fast_io; cout_precision;
	int n;	cin >> n;	int arr[n];	for(int i=0; i<n; i++)	cin >> arr[i];	
	int sum;	cin >> sum;
	vector < vector <int> > res ;
	res = fourSumV2(arr,n,sum);

	for(int i=0; i<res.size(); i++){
		for(int j=0; j<4; j++){
			cout << res[i][j] <<" ";
		}
		cout << endl;
	}


	return 0;
}
