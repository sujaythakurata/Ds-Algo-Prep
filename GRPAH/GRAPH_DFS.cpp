/*
	*dfs
	*dfs use stack
	*post order parse
	
*/

#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<int>adj[], int start, vector<bool>&visited){
	
	visited[start] = true;
	cout<<start<<" ";
	for(int i = 0; i<adj[start].size(); i++){
		if(!visited[adj[start][i]]){
			dfs(adj, adj[start][i], visited);
			}
	}

}

int main(){
	
	int n = 5, e = 6, u, v;
	vector<int>adj[n];
	vector<bool>visited(n);
	for(int i = 0; i<n; i++)
		visited[i] = false;
		
	for(int i = 0; i<e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
	
	dfs(adj, 0, visited);
	
	
	return 0;
}
