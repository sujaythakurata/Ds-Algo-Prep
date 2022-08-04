/*
	*Topological Sorting
	*T.c -> O(n+e)
	*S.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[], int u, vector<bool>&vs, stack<int>&s){

	vs[u] = true;
	for(auto i = adj[u].begin(); i != adj[u].end(); i++){
		if(!vs[*i])
			dfs(adj, *i, vs, s);
	}
	s.push(u);
}

int main(){
	int n, e, u, v;
	cin>>n>>e;
	vector<int>adj[n];
	vector<bool>vs(n, false);
	stack<int>s;
	
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	for(int i = 0; i < n; i++){
		if(!vs[i])
			dfs(adj, i, vs, s);
	}
	
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}
