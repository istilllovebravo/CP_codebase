#include "bits/stdc++.h"

using namespace std;


#define int long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define cout_precision cout.setf(ios::fixed); cout.precision(32);
#define pb push_back
#define endl "\n"
#define clr(a)	memset(a, 0 , sizeof(a))

const int N = 100100;

/*
	int find_set(int v) : returns the representative of the set containing v
	void union_sets(int u, int v) : merges the sets containing u and v
	void make_set(int v) : creates a set whose representative is v

*/

int parent[N];
int size[N]; // size[i] = # elements in set whose representative is i

/*CANT make use of rank[N] because it is a special function in C++*/

int find_set(int v){ // O(logn)	on average
	if(v == parent[v])	return v;
	return parent[v] = find_set(parent[v]);
}

void initialize_sets_and_sizes(int n){
	for(int i = 0; i<=n; i++){
		parent[i] = i;
		size[i] = 1; // there is currently only 1 element whose representativ is i
	}
}	

void union_sets(int u, int v){ // union based on size of set ( smaller sized set goes into bigger sized set)
	int r_u = find_set(u);
	int r_v = find_set(v);

	if(r_u != r_v){

		if(size[r_u] < size[r_v]){ // this is done to make sure ki r_u is the bigger sized set
			swap(r_u, r_v);
		}
		parent[r_v] = r_u;
		size[r_u] += size[r_v];
	}

}

void optimal_dsu(){
	int n;	cin >> n;

	initialize_sets_and_sizes(n);

	int m;	cin >> m;
	for(int i =0 ; i<m; i++){
		int u,v;	cin >> u >> v; // u and v belong to same set
		union_sets(u,v);
	}
	int q;	cin >> q;
	while(q--){
		int u,v;	cin >> u >> v;
		int r_u = find_set(u);
		int r_v = find_set(v);
		cout <<r_u <<" "<<r_v<<endl;
	}

    return ;
}


int32_t main(){
    fast_io;
    cout_precision;
    
    optimal_dsu();

    return 0;
}