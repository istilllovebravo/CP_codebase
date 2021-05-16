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
 
void spiral(int arr[][6] , int m , int n){
	int top = 0 , down = m-1, left = 0 , right  = n-1 , dir = 0;
	while(top <= down && left <= right){
		switch(dir){
			case 0 :for(int i=left ; i<=right; i++)
						cout << arr[top][i] <<" ";
					top++;
					break;
			case 1 :for(int i=top; i<=down; i++)	cout << arr[i][right]<<" ";
					right--;
					break;
			case 2 :for(int i=right; i>=left; i--)	cout << arr[down][i] <<" ";
					down--;
					break;
			case 3 :for(int i=down; i>=top; i--)	cout << arr[i][left] <<" ";
					left++;
					break;	

		}
		dir = (dir+1)%4;
			
	}
}

int main(){
	fast_io; cout_precision;
	int arr[3][6] = { { 1, 2, 3, 4, 5, 6 }, 
                    { 7, 8, 9, 10, 11, 12 }, 
                    { 13, 14, 15, 16, 17, 18 } }; 
     spiral(arr,3,6); 

	return 0;
}
