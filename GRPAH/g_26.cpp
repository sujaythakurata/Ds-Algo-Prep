/*
	*Prim’s Minimum Spanning Tree (MST)\
	*T.c -> O(v^2)
	*S.c -> O(v^2)

*/

#include<bits/stdc++.h>
using namespace std;

int minkey(vector<int>keys, vector<bool>vs, int n){
	int minval = 9999, u;
	for(int i = 0; i < n; i++){
		if(!vs[i] && keys[i]<minval){
			minval = keys[i];
			u = i;
		}
	}
	
	return u;
}

void mst(vector<vector<int>>adj, int n){
	
	vector<bool>vs(n, false);
	vector<int>keys(n, 9999);
	vector<int>parent(n);
	
	int u = adj[0][0];
	
	keys[u] = 0;
	parent[u] = -1;
	
	for(int i = 0; i < n - 1; i++){
		u = minkey(keys, vs, n);
		vs[u] = true;
		for(int i = 0; i < n; i++){
			if( adj[u][i] && !vs[i] && adj[u][i] < keys[i]){
				keys[i] = adj[u][i];
				parent[i] = u;
			}
		}
	}
	
	
	
	for(int i = 1; i < n; i++)
		cout<<parent[i]<<" - "<<i<<" | w: "<<adj[i][parent[i]]<<endl;
	
	
	

}

int main(){
	int n, e, u, v, w;
	cin>>n>>e;
	vector<vector<int>>adj(n, vector<int>(n,0));
	for(int i = 0; i < e; i++){
		cin>>u>>v>>w;
		adj[u][v] = w;
		adj[v][u] = w;
	}
	
	mst(adj, n);
	
	
	return 0;
}
