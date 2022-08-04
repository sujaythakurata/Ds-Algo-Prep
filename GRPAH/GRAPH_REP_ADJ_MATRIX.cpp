/*
	*adjency matrix representation
	*edges 
	0 -> 1, 4
	1 -> 0, 2, 4
	2 -> 1, 3
	3 -> 2, 4
	4 -> 0, 1
	
	node = 5
	edge = 6
	T.c = O(edge)
	S.c = O(node^2)

*/


#include<iostream>
#include<vector>

using namespace std;

int main(){
	
	int node = 5, edge = 6, u, v;
	vector<vector<int>> adj(node);
	
	for(int i = 0; i < node; i++)
		adj[i] = vector<int>(node);
		
	for(int i = 0; i < edge ; i++){
		cin>>u>>v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	
	for(int i = 0; i<node; i++){
		for(int j = 0; j<node; j++){
		
			cout<<adj[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
	

}

