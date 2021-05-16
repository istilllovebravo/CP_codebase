#include "bits/stdc++.h"
using namespace std;




#define int long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define cout_precision cout.setf(ios::fixed); cout.precision(32);
#define pb push_back

/*extra headers for ordered_set */


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

/*
1. find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
    Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
    *(s.find_by_order(2)) : 3rd element in the set i.e. 6
    *(s.find_by_order(4)) : 5th element in the set i.e. 88

*/

/*

2. order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
    Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
    s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
    s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.


*/


void solve(){
    int n;  cin >> n;

    ordered_set s; // Duplicates dont matter as it is a set after all.
    for(int i=0; i<n; i++){
        int num;    cin >> num;
        s.insert(num);
    }
    int q;  cin >> q;
    while(q--){
        int x;  cin >> x;
        int n_elements_less_than_x = s.order_of_key(x);
        int n_elements_greater_than_equal_to_x = s.size() - n_elements_less_than_x;
        cout << n_elements_greater_than_equal_to_x <<endl;
    }



    return ;
}


int32_t main(){
    fast_io;
    cout_precision;
    int tc = 1; 
    // cin >> tc;
    while(tc--){
        solve();
    }

    return 0;
}