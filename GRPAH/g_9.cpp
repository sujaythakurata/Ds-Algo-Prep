/*
	*Delete Edge to minimize subtree sum difference
	*T.c -> O(n)
	*S.c -> O(n+e)

*/


#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int>adj[], vector<int>weight, vector<int>&subtree, int u, int parent, int total, int &diff){
	int sum = weight[u];
	for(auto i = adj[u].begin(); i != adj[u].end(); i++){
	
		if(*i != parent){
			dfs(adj, weight, subtree, *i, u, total, diff);
			sum += subtree[*i];
		}
	}
	subtree[u] = sum;
	
	if(u != weight.size() - 1 && abs(total - (2*sum)) < diff)
			diff = abs(total - (2*sum));
}

int main(){

	int n, e, u, v, w, min_diff = 99999, total_weight = 0;
	cin>>n>>e;
	vector<int>adj[n];
	vector<int>weight(n);
	vector<int>subtree(n);
	for(int i = 0; i < n; i++){
		cin>>w;
		weight[i] = w;
		subtree[i] = w;
		total_weight += w;
	}
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(adj, weight, subtree, n-1, -1, total_weight, min_diff);
	cout<<min_diff;



	return 0;
}
