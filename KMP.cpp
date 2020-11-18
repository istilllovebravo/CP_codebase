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
#define pf push_front
#define M int(1e9+7)
#define endl '\n'
#define largest(a,b,c) (a>b?(a>c? a:c):(b>c? b:c))
#define smallest(a,b,c) (a<b?(a<c? a:c):(b<c? b:c))

using ll = int64_t; using vll = vector<ll>; using vvll = vector<vll>;
using pll = pair<ll, ll>; using vpll = vector<pll>; using vvpll = vector<vpll>;


vector <int> prefix_function(string str){
	int n = str.size();
	vector <int> pi(n);	pi[0]  =0;
	for(int i=1; i<n; i++){
		int j = pi[i-1];
		while(j>0 && str[i] != str[j])	j = pi[j-1];
		if(str[i] == str[j])	j++;
		pi[i] = j;
	}
	return pi;
}

int main() {
	fast_io; cout_precision;
	string text;	cin >> text;	
	string pat;	cin >> pat;	
	string str = pat+ "$" +text ;
	vector <int> pi = prefix_function(str);
	int count =0;
	for(int i=0; i<pi.size(); i++){
		if(pi[i] == pat.size())	count++;
	}
	cout << count << endl;


	return 0;
}
