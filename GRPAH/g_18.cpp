/*
	*Sum of the minimum elements in all connected components of an undirected graph
	*T.c -> O(n)
	*S.c -> O(n+e)

*/

#include<bits/stdc++.h>
using namespace std;
int minvalue(vector<int>adj[], vector<bool>&visited, vector<int>value, int u, int n){
	queue<int>que;
	int min_val = value[u];
	que.push(u);
	visited[u] = true;
	while(!que.empty()){
		u = que.front();
		que.pop();
		for(auto j = adj[u].begin(); j != adj[u].end(); j++){
			if(!visited[*j]){
				que.push(*j);
				visited[*j] = true;
				min_val = min(min_val, value[*j]);
			}
		}
	}
	
	return min_val;

}
int main(){	
	int n,e,u,v, ans = 0;
	cin>>n>>e;
	vector<int>adj[n];
	vector<bool>visited(n, false);
	vector<int>value(n);
	for(int i = 0; i < n; i++){
		cin>>u;
		value[i] = u;
	}
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			ans += minvalue(adj, visited, value, i, n);
		}
	}
	
	cout<<ans;

	return 0;
}
