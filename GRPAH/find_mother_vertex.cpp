/*
	*find mother vertex(a vertex from this vertex we can reach any other vertex)
	*using dfs
	*dfs will return the last vertex and it can be a mother vertex
	*T.c = O(v+e)
*/

#include<iostream>
#include<vector>
using namespace std;

void print_graph(vector<int>adj[], int n){
	
	for(int i = 0; i<n; i++){
		cout<<i<<" : ";
		for(auto j = adj[i].begin(); j != adj[i].end(); j++){
			cout<< *j<<" ";
		}
		cout<<"\n";
	}

}

void dfs(vector<int>adj[], int start, vector<bool>&visited){
	visited[start] = true;
	for(auto i = adj[start].begin(); i != adj[start].end(); i++){
		
			if(!visited[*i]){
				dfs(adj, *i, visited);
			}
	}
}

int main(){
	int n,e,u,v, mother_vertex;
	cin>>n>>e;
	vector<int>adj[n];
	vector<bool>visited(n);
	fill(visited.begin(), visited.end(), false); 
	for(int i = 0; i<e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	print_graph(adj, n);
	
	for(int i = 0; i<n; i++){
		if(!visited[i]){
			dfs(adj, i, visited);
			mother_vertex = i;
		}
	}
	
	fill(visited.begin(), visited.end(), false);
	dfs(adj, mother_vertex, visited);
	for(int i = 0; i<n; i++){
		if(!visited[i]){
			cout<<-1;
			return 0;
		}
	}
	
	cout<<"Mother Vertex: "<<mother_vertex;

	
	

	return 0;
}
