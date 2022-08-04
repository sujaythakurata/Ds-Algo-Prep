/*
	*transitive closure using dfs
	*T.c = O(v(v+e))
	*worst case O(v^3)

*/

#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<int>adj[], int start, int end, vector<vector<int>>&tc){
	tc[start][end] = 1;
	for(auto i = adj[end].begin(); i != adj[end].end(); i++){
		if(tc[start][*i] != 1)
			dfs(adj, start, *i, tc);
	}
}

int main(){
	
	int n, e, u, v;
	cin>>n>>e;
	vector<int>adj[n];
	vector<vector<int>>tc(n);
	for(int i = 0; i < n; i++){
		tc[i] = vector<int>(n);
		fill(tc[i].begin(), tc[i].end(), 0);	
	}
	
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	for(int i = 0; i<n; i++){
		cout<<i<<" : ";
		for(auto j = adj[i].begin(); j != adj[i].end(); j++){
			cout<< *j<< " ";
		}
		cout<<"\n";
	}
		
	for(int i = 0; i < n; i++){
		dfs(adj, i, i, tc);
	}
	
	cout<<"Transivitve closure matrix\n";
	for(int i = 0; i < n; i++){
		cout<<i<<" : ";
		for(int j = 0; j < n; j++)
			cout<<tc[i][j]<<" ";
		cout<<"\n";
	}
	
	
	return 0;
}
