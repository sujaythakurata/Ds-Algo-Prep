/*
	*Delete Edge to minimize subtree sum difference
	*T.c -> O(n*e)
	*S.c -> O(n+e)

*/

#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int>adj[], vector<int>weight, int u, int v){
	
	int sum = weight[u];
	for(auto i = adj[u].begin(); i != adj[u].end(); i++){
		if(*i == v)
			continue;
		sum += dfs(adj, weight, *i, u);
	}
	
	return sum;

}

int main(){
	int n, e, u,v,w, min_diff = 99999, s1, s2;
	pair<int, int> ele;
	cin>>n>>e;
	vector<int>adj[n];
	vector<int>weight(n);
	vector<pair<int, int>>edge(e);
	
	for(int i = 0; i < n; i++){
		cin>>w;
		weight[i] = w;
	}
	
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		edge[i] = make_pair(u,v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	
	for(int i = 0; i < e; i++){
		
		ele = edge[i];
		s1 = dfs(adj, weight, ele.second, ele.first);
		s2 = dfs(adj, weight, ele.first, ele.second);
		min_diff = min(min_diff, abs(s1 - s2));
	
	}
	cout<<min_diff;
	
	
	return 0;
}
