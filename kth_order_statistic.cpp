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


/*NOTE - this function giving segFault for many k values !! */
int kth_order_statistic(vector <int> a, int k){
	int n = a.size();
	int l = 1  , r = n;
	while(1){
		int currSize = r-l+1;
		if(currSize == 1){
			return a[k];
		}
		else if(currSize == 2){
			if(a[l] > a[r]){
				swap(a[l] , a[r]);
			}
			return a[k];
		}
		// now we want to select a[mid] as pivot , se we do a neat trick
		// and swap a[mid] with a[l+1]

		int mid = (l+r)>>1; 
		swap(a[l+1] , a[mid]);

		// now ordering a[l] , a[l+1] , a[r]
		swap(a[l] ,a[l+1]);
		swap(a[l+1] ,a[r]);
		swap(a[l] , a[r]);


		// here is the partitioning of array on basis of a[l+1] : which is 
		// actually our orignal middle
		int i = l+2, j = n-1;
		int curr = a[l+1];	 // curr is the pivot 

		// swapping to make two groups i.e. on the left we have elements smaller
		// than pivot and on right we would have elements greater than pivot
		while(1){
			while(a[i] < curr){
				i++;
			}
			while( a[j] > curr){
				j--;
			}
			if(i > j)	break;
			swap(a[i] , a[j]); // the swapping that partitions into left and right
		}

		//doing the actual partitioning where we put out pivot back to the 
		// place where all elements to its left would be smaller 
		// and all to its right would be greater
		a[l+1] = a[j]; 
		a[j] = curr;

		if(j > k){
			r = j-1;
		}
		else if(j < k){
			l = i;
		}
		else if(j == k){
			r = j-1;
			l = i;
		}

	}
}

// gives kth-smallest element of array
//Also a is 1-based indexing
//WORKS GREAT
int kth_order_statistic_using_stl(vector <int> a , int k){
	// shallow copy of A made . This is required b/c
	// nth_element would modify the vector.
	vector <int> temp ; 
	int n = a.size();
	for(int i=1; i<=n; i++){
		temp.push_back(a[i]);
	}

	//this would partiton the temp vector such that temp[k-1] would be the k-th
	//smallest element. All elements to its left would be smaller 
	// than a[k-1] and all to right would be greater
	nth_element(temp.begin() ,temp.begin() + k-1  , temp.end());
	return temp[k-1];
	
}

int32_t main(){
	fast_io;	cout_precision;
	int n;	cin >> n;
	vector <int> a(n+1);
	// vector <int> b(n);
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	int k;	cin >> k;
	cout << kth_order_statistic(a,k) <<endl; // may give segFault for some Ks
	cout << kth_order_statistic_using_stl(a,k) <<endl;

	return 0;
}

