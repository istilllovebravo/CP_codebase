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

int solve(string str){
    int res = 0;
        int curr = 0;
        unordered_map <char , int> mp;
        for(int i=0; i<str.size(); i++){
            if(mp.find(str[i]) == mp.end()){
                mp[str[i]] = i;
                curr++;
            }
            else{
                int index = mp[str[i]];
                for(int j=0; j<index; j++) 
                    if(mp.find(str[j]) != mp.end())
                        mp.erase(str[j]);
                mp[str[i]] = i;
                curr =  i- index ;
            }
            res = max(curr, res);
        }
        return res;
} 

int main(){
    fast_io; cout_precision;
    string str; cin >> str; cout << solve(str) <<endl;


    return 0;
}
