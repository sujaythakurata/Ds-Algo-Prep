/*
	*find k - cores of a unidirected graph
	*using dfs
	*T.c -> O(v(v+e))
*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(vector<int>adj[], int start, vector<bool>&visited, vector<int>&degree, int k){
	
	visited[start] = true;
	
	for(auto i = adj[start].begin(); i != adj[start].end(); i++){
		
		if(degree[start] < k)
			degree[*i]--;
			
		if(!visited[*i]){
			if(dfs(adj, *i, visited, degree, k))
				degree[start]--;
		}
	}
	
	return (degree[start]<k);

}

int main(){
	
	int n, e, u, v, k;
	cin>>k>>n>>e;
	vector<int>adj[n];
	vector<bool>visited(n, false);
	vector<int>degree(n);
	
	for(int i = 0; i<e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 0; i<n ; i++){
		cout<<i<<" : ";
		for(auto j = adj[i].begin(); j != adj[i].end(); j++){
			cout<<*j<<" ";
		}
		cout<<"\n";
	}
	
	for(int i = 0; i < n; i++)
		degree[i] = adj[i].size();
		
	for(int i = 0; i < n; i++){
		if(!visited[i])
			dfs(adj, i, visited, degree, k);
	}

	for(int i = 0; i < n; i++){
		cout<<i<<" : ";
		if(degree[i] >= k){
			for(auto j = adj[i].begin(); j != adj[i].end(); j++){
				if(degree[*j]>=k)
					cout<<*j<<" ";
			}
		}
		cout<<"\n";
	}

	return 0;
}
