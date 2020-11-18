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

bool comp(pair <int,int> p1 , pair <int,int> p2){
	return p1.sc < p2.sc;
} 

void sortByValue(unordered_map <int,int> &mp){
	vector < pair <int, int> > v;
	for(auto i = mp.begin(); i!= mp.end(); i++)
		v.pb({i->fr ,i->sc});	
	sort(v.begin() , v.end() , comp);
	mp.clear();
	for(int i=0; i<v.size(); i++)	mp[v[i].fr] = v[i].sc;
}

int main(){
	fast_io; cout_precision;
	unordered_map <int,int> mp;
	mp[3] = 1;
	mp[2]  = 4;
	mp[1]   = 2;
	sortByValue(mp);
	for(auto i = mp.begin(); i!= mp.end(); i++)
		cout <<i->sc <<",";
	cout << endl;

	return 0;
}
