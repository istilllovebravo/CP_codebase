#include <bits/stdc++.h>
using namespace std;


#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define cout_precision cout.setf(ios::fixed); cout.precision(18);
#define int long long
#define M int(1e9+7)
#define pb push_back
#define fr first
#define sc second
#define pii pair <int,int>
#define INF LONG_LONG_MAX
#define endl '\n'

const int max_n = 10000;

vector <pii> adj[max_n]; 
vector <int> ptr(max_n, 0);
int n,m;

vector <pii> primsMst(){
	vector <bool> visited(max_n , 0);
	vector <int> selected;
	selected.pb(1);	visited[1] = 1 ;

	vector <pii> mst;
	while(mst.size() != n-1){
		pii newEdge = {-1 , -1};
		int currWeight = INF;
		for(int i=0; i<selected.size(); i++){
			if(mst.size() == n-1){
				break;
			}
			int u = selected[i];
			vector <pii> edges = adj[u];
			for(int j=ptr[u]; j<edges.size(); j++){
				int v = edges[j].sc;
				int w = edges[j].fr;
				if(!visited[v]){
					if(currWeight > w){
						currWeight = w;
						newEdge = {u,v};
						ptr[u] = j; // updating the pointer to currMin edge
					}
					break;
				}
			}
		}	
		visited[newEdge.sc] = 1;
		selected.pb(newEdge.sc);
		mst.pb(newEdge);
	}
	return mst;
} 

int32_t main(){
	fast_io;	cout_precision;

	cin >> n >> m; // nodes assumed to be from 1 to n

	for(int i=0; i<m; i++){
		int u,v , w;
		cin >> u >> v >> w;
		adj[u].pb({w,v});
		adj[v].pb({w,u});
	}
	for(int i=1; i<=n; i++){// nodes assumed to be from 1 to n
		sort(adj[i].begin() , adj[i].end() );
	}
	
		
	vector <pii> mst = primsMst();

	for(int i=0; i<mst.size(); i++){
		cout << mst[i].fr <<" "<<mst[i].sc <<endl;
	}

	return 0;
}

