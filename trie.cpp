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

struct TrieNode{
	TrieNode *children[26];
	bool isEndOfWord;
	TrieNode(){
		for(int i=0; i<26; i++)	children[i]= NULL;
		isEndOfWord = 0;
	}
};

void insertInTrie(TrieNode *root , string str){
	int n = str.size();
	TrieNode *curr = root;
	for(int i=0; i<n; i++){
		int val = str[i]-'a';
		if(curr->children[val] == NULL)	curr->children[val] = new TrieNode();
		curr = curr->children[val];	
	}
	curr->isEndOfWord = 1;
}
string currWord = "";
void printTrie(TrieNode *root){
	if(root->isEndOfWord)	cout << currWord <<endl;
	for(int i=0; i<26; i++){
		if(root->children[i]){
			currWord += 'a'+i;
			printTrie(root->children[i]);
			currWord.pop_back();
		}
	}
}

bool search(TrieNode *root, string str){
	int n = str.size();
	for(int i=0; i<n; i++){
		int val = str[i]-'a';
		if(root->children[val] == NULL)	return 0;
		root = root->children[val];
	}
	if(root->isEndOfWord)	return 1;
	return 0;
}

int main() {
	fast_io; cout_precision;
	int n;	cin >> n;
	TrieNode *root = new TrieNode();
	for(int i=0; i<n; i++){
		string str;	cin >> str;
		insertInTrie(root, str);
	}
	printTrie(root); // idk why but the root pointer still points to the top of trie 
	// even after executing lul


	return 0;
}
