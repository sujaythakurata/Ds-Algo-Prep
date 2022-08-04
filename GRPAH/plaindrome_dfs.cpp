/*
	
	*Construct binary palindrome by repeated appending and trimming
	*T.c -> O(n)

*/

#include<bits/stdc++.h>

using namespace std;
void dfs(vector<int>adj[], int u, vector<int>&palindrome){
	
	palindrome[u] = 1;
	for(auto i = adj[u].begin(); i != adj[u].end(); i++){
		
		if(palindrome[*i] != 1)
			dfs(adj,*i,palindrome); 
	}

}
int main(){	

	int n,k;
	cin>>n>>k;
	vector<int>adj[n];
	vector<int>palindrome(n, 0);
	int index[n];
	for(int i = 0; i < n ; i++)
		index[i] = i % k;
	for(int i = 0; i < n/2; i++){
		adj[index[i]].push_back(index[n-i-1]);
		adj[index[n-i-1]].push_back(index[i]);
	}
	for(int i = 0; i < n/2; i++){
		cout<<i<<" : ";
		for(auto j = adj[i].begin(); j != adj[i].end(); j++)
			cout<<*j<<" ";
		cout<<endl;
	}
	
	dfs(adj, 0,palindrome);
	for(int i = 0; i < n ; i++)
		cout<<palindrome[index[i]];

	return 0;
}
