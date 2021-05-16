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

vector < vector <int> > triplets(vector <int> v , int sum){
	vector < vector <int> > res;
	set < vector < int> > s;
	int n = v.size();
	for(int i=0; i<n-2; i++){
		int newSum = sum - v[i];
		unordered_map <int,int> indexOf;
		for(int j=i+1; j<n; j++)	indexOf[v[j]] = j;
		for(int j=i+1; j<n; j++){
			if(indexOf.find(newSum - v[j]) != indexOf.end() ){
				if(indexOf[newSum - v[j]] != j){
					vector <int> temp;
					temp.pb(v[i]);  temp.pb(v[j]);	temp.pb(newSum - v[j]);
					sort(temp.begin() , temp.end());
					s.insert(temp);
				}
					
			}
		}
	}
	for(auto i = s.begin(); i!= s.end(); i++)
		res.pb(*i);
	return res;
}
 
int main(){
	fast_io; cout_precision;
	int n;	cin >> n; vector <int> v;
	for(int i=0; i<n; i++){
		int num;
		cin >> num;	v.pb(num);
	}
	int sum;	cin >> sum;
	vector < vector <int> > res = triplets(v, sum);
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<3; j++){
			cout << res[i][j] <<",";
		}
		cout << endl;
	}

	return 0;
}
