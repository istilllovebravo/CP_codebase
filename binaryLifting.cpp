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

int n,l;
int timer ;
int tin[100];
int tout[100];
int up[1000][1000];
vector < int> adj[1000];

void dfs(int u, int parent){
	tin[u] = ++timer;
	up[u][0] = parent;
	for(int i=1; i<=l; i++)	up[u][i] = up[up[u][i-1]][i-1];

	for(auto v : adj[u])
		if(v != parent)	dfs(v,u);


	tout[u] = ++timer;


}

bool isAncestor(int u, int v){// 1 if u is ancestor of v
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){ // gives LCA of u and v
	if(isAncestor(u,v))	return u;
	if(isAncestor(v,u))	return v;
	for(int i=l ; i>=0; i--){
		if(!isAncestor(up[u][i] , v))
			u = up[u][i];
	}
	return up[u][0];
}

void preprocess(int root){
	clr(tin);	clr(tout);	for(int i=0; i<1000; i++)	clr(up[i]);
	timer  =0;	
	//Set l as max height of tree
	l = 50; // im setting a feault value. If i give a tree such that its height is greater than this l
	//  then it will give Seg error. Actually l is not the height. 2^l is the max path length from root to a leaf
	dfs(root,root);
}

int main() {
	fast_io; cout_precision; 
	cin >> n; // n nodes and n-1 edges as it is  a tree
	int root;	cin >> root;
	for(int i=0; i<n-1; i++){
		int u,v;	cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	preprocess(root);
	//cout <<"Enter nodes jinka LCA pata krna"<<endl;
	int u,v;	cin >> u >> v;
	cout << lca(u,v) <<endl;
	return 0;
}
