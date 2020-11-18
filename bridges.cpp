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

int id = 0;
int ids[1000000];	
int low[1000000];	
bool visited[1000000];
vector <int> adj[1000000];
bool isArt[1000000];
int outEdgeCount;

void dfs(int u, int parent, vector < pair <int,int> > &bridges){
	id++;
	ids[u] = id;	low[u] = id;
	visited[u] = 1;
	for(auto i = adj[u].begin(); i!= adj[u].end(); i++){
		int v = *i;
		if(v == parent)	continue;
		if(!visited[v]){
			dfs(v,u,bridges);
			low[u] = min(low[u] , low[v]);
			if(ids[u] < low[v]){
				bridges.pb({u,v});
			}
		}
		else	low[u] = min(low[u] , ids[v]);
	}
}

vector < pair <int,int> > findBridges(int n, int m){
	vector < pair <int,int> > bridges;
	clr(visited);
	for(int i=0; i<n; i++){
		if(!visited[i]){
			dfs(i,-1,bridges);
		}
	}
	return bridges;
}

void dfs(int root, int u, int parent){
	if(parent == root)	outEdgeCount++;
	id++;
	ids[u] = id;	low[u] = id;
	visited[u] = 1;
	for(auto i = adj[u].begin(); i!= adj[u].end(); i++){
		int v = *i;
		if(v == parent)	continue;
		if(!visited[v]){
			dfs(root , v , u);
			low[u] = min(low[u] , low[v]);
			if(ids[u] < low[v]){
				isArt[u] = 1;
			}
			if(ids[u] == low[v])	isArt[u] = 1;
		}
		else	low[u] = min(low[u] , ids[v]);
	}
}


vector <int> findArticulationPoints(int n, int m){
	clr(isArt);
	vector <int> res;
	clr(visited);
	for(int i=0; i<n; i++){
		if(!visited[i]){
			outEdgeCount = 0;
			dfs(i,i,-1);
			isArt[i] = (outEdgeCount > 1);
		}
		if(isArt[i])	res.pb(i);
	}
	return res;
}

int main(){
	fast_io; cout_precision;
	int n,m;	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int u,v;	cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector < pair <int,int> > bridges = findBridges(n,m);
	cout << "bridges are " <<endl;
	for(int i=0; i<bridges.size(); i++)	cout << bridges[i].fr<<"," <<bridges[i].sc <<endl;

	vector <int> articulationPoints = findArticulationPoints(n,m);
	cout <<"Articulation Points are ";
	for(int i=0; i<articulationPoints.size(); i++)	cout << articulationPoints[i] <<",";
	cout << endl;

	return 0;
}
