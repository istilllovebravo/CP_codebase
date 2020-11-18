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

const int N = 100000;

int tree[2*N];
int n;

void build(){
	for(int i=n-1; i>0; i--)	tree[i] =	min(tree[i<<1] , tree[i<<1|1]);
	return ;
}

void printTree(){
	for(int i=1; i<2*n; i++)	cout << tree[i] <<",";
	cout << endl;
}

int rangeMin(int l, int r){
	int res=  INT_MAX;
	l+=n;	r+=n;
	for( ; l<r; l>>=1 , r>>=1){
		if(l&1)	res= min(res , tree[l++]);
		if(r&1)	res = min(res , tree[--r]);
	}
	return res;
}

void update(int p, int val){
	p+=n;
	tree[p] = val;
	for(int i=p; i>1; i>>=1)	tree[i>>1] = min(tree[i] , tree[i^1]);
	return ;
}
 
int main(){
	fast_io; cout_precision;
	cin >> n;
	for(int i=0; i<n; i++)	cin >> tree[n+i];
	build();
	int index,value;	cin >> index >> value;
	update(index , value);
	//printTree();
	int l,r;	cin >> l >> r;
	cout << rangeMin(l,r+1) <<endl;

	return 0;
}
