/*
	*Maximum edges that can be added to DAG so that it remains DAG
	*T.c -> O(n*n)
	*S.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;


void dfs(vector<int>adj[], int u, vector<bool>&vs, vector<int>&s){
	vs[u] = true;
	for(auto j = adj[u].begin(); j != adj[u].end(); j++){
		if(!vs[*j])
			dfs(adj, *j, vs, s);
	}
	s.push_back(u);
}

vector<int> topologicalsort(vector<int>adj[], int n){
	vector<bool>vs(n,false);
	vector<int>s;
	for(int i = 0; i < n; i++){
		if(!vs[i])
			dfs(adj, i, vs, s);
	}
	reverse(s.begin(), s.end());
	return s;
}



int main(){
	
	int n, e, u, v;
	cin>>n>>e;
	vector<int>adj[n];
	vector<int>arr;
	vector<bool>vs(n, false);
	
	for(int i = 0; i < n; i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	arr = topologicalsort(adj, n);
	
	for(int i = 0; i < n; i++){
		u = arr[i];
		for(auto j = adj[u].begin(); j != adj[u].end(); j++)
			vs[*j] = true;
		for(int j = i + 1; j < n; j++){
			if(!vs[arr[j]])
				cout<<u<<" - "<<arr[j]<<" , ";
			vs[arr[j]] = false;
		}
	}
	

	return 0;
}
