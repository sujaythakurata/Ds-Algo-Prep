/*
	*count number of trees in a forest
	*T.c->O(v+e)
*/

#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int>adj[], int u, vector<bool>&visited){
	visited[u] = true;
	for(auto i = adj[u].begin(); i != adj[u].end(); i++){
		if(!visited[*i])
			dfs(adj, *i, visited);
	}

}

int main(){
		
	int n, e, u,v, count = 0;
	cin>>n>>e;
	vector<int>adj[n];
	vector<bool>visited(n, false);
	for(int i = 0; i < e;i ++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			dfs(adj, i, visited);
			count++;
		}
	}
	
	cout<<count;
	

	return 0;
}
