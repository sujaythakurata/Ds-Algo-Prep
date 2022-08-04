/*
	*adjency list representation
	*edges 
	0 -> 1, 4
	1 -> 0, 2, 4
	2 -> 1, 3
	3 -> 2, 4
	4 -> 0, 1
	
	node = 5
	edge = 6
	T.c = O(edge)
	S.c = O(node+edge) worst case O(node^2)

*/

#include<iostream>
#include<vector>
using namespace std;


int main(){
	int n = 5, e = 6, u, v;
	vector<int>adj[n];
	
	for(int i = 0; i<e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	
	}
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<adj[i].size(); j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<"\n";
	}

}
