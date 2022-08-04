/*
	*Check if two nodes are on same path in a tree
	*T.c -> O(n)
	*S.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>adj[], int u, vector<int>&intime, vector<int>&outtime, vector<bool>&vs, int &timer){
	timer++;
	intime[u] = timer;
	vs[u] = true;
	for(auto i = adj[u].begin(); i != adj[u].end(); i++){
		if(!vs[*i]){
			dfs(adj, *i, intime, outtime, vs, timer);
		}
	}
	
	timer++;
	outtime[u] = timer;
	
	
}


int main(){
	int n, e, q, u, v;
	cin>>n>>e>>q;
	vector<int>adj[n];
	vector<int>intime(n, 0);
	vector<int>outtime(n,0);
	vector<pair<int, int>>quries(n);
	vector<bool>vs(n,false);
	
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 0; i < q; i++){
		cin>>u>>v;
		u--;
		v--;
		quries[i] = {u, v};
	}
	int timer = -1;
	dfs(adj, 0, intime, outtime, vs, timer);
	
	for(int i = 0; i < q; i++){
		u = quries[i].first;
		v = quries[i].second;
		if((intime[u] < intime[v] && outtime[u] > outtime[v]) || (intime[v] < intime[u] && outtime[v] > outtime[u]))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	
	
	return 0;
}
