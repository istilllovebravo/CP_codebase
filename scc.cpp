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

vector < int > adj[10000000];
vector <int> newAdj[10000000];
int V,E;


void printVector(vector <int> v){
	for(int i=0; i<v.size(); i++)	cout << v[i] <<" ";
	cout <<endl;
}

void reverseGraph(){
	
	for(int u=0; u<V;u++){
		for(auto i = adj[u].begin(); i!= adj[u].end(); i++){
			int v = *i;
			newAdj[v].pb(u);
		}
	}
	
}

void dfs(int u , bool visited[], vector <int> &component){
	component.pb(u);
	for(auto i= adj[u].begin(); i!= adj[u].end(); i++){
		if(!visited[*i])
			dfs(*i , visited , component);
	}
}

void sccHelper(int u ,  bool visited[], stack <int> &s){
	visited[u] = 1;
	for(auto i = adj[u].begin(); i!= adj[u].end(); i++){
		if(!visited[*i])	sccHelper(*i , visited , s);
	}
	s.push(u);
}

vector <vector <int> > scc(){
	vector < vector <int> > res;
	bool visited[V];	clr(visited);
	stack <int> s;
	for(int u =0 ; u<V; u++){
		if(!visited[u])
			sccHelper(u,visited,s);
	}
	reverseGraph();

	for(int u=0; u<V; u++)	adj[u].clear();
	
	
	for(int u=0; u<V; u++){
		adj[u] = newAdj[u];
	}	
	
	clr(visited);
	while(!s.empty()){
		int u = s.top();	s.pop();
		if(!visited[u]){
			vector < int > component;	component.clear();
			dfs(u , visited,component);
			res.pb(component);
		}
	}
	return res;
}

 
int main(){
	fast_io; cout_precision;
	cin >> V;		cin >> E;	
	for(int i=0; i<E; i++){
		int a,b;	cin >> a >> b;	adj[a].pb(b);
	}
	vector <vector <int> > res = 	scc();
	for(int i=0; i<res.size(); i++)	printVector(res[i]);

	return 0;
}
