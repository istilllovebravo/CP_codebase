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
int maxLen = INT_MIN;

int dfs( int arr[][1000],int x, int y, bool visited[][1000] ,int m ,int n){
		int currLen = 1;
		int dx[]  = {0,-1,-1,-1,0,1,1,1};
		int dy[] = {-1,-1,0,1,1,1,0,-1};
		
		visited[x][y] = 1;
		for(int i=0; i<8; i++){
			int x1 = x + dx[i] , y1 = y + dy[i];
			if(x1>=1 && y1 >=1 && x1 <=m && y1 <= n && !visited[x1][y1] && arr[x1][y1])	currLen+=dfs(arr,x1,y1,visited,m,n);
		}	
		return currLen;
	
}
 
int main(){
	fast_io; cout_precision;
	int m,n;	cin >>m >> n ;
	int arr[m+1][1000];
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++){
			cin >> arr[i][j];
		}
	int count = 0;
	bool visited[m+1][1000];	
	for(int i=0; i<=m; i++)	for(int j=0; j<1000;j++)	visited[i][j] = 0;

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(!visited[i][j] && arr[i][j]){
				count++;
				maxLen = max(maxLen , dfs(arr,i,j,visited, m, n))	;
			}
		}
	}

	cout << count << endl;
	cout << maxLen <<endl;
	
	return 0;
}
