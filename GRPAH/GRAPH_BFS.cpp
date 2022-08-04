/*
	*bfs
	*bfs use queue
	*level order parse
*/


#include<iostream>
#include<vector>
#include<list>

using namespace std;

void bfs(vector<int>adj[], int start, int n){
	int ele, adjVertex;
	vector<bool>visited(n);
	for(int i = 0; i<n; i++)
		visited[i] = false;
	list<int>queue;
	queue.push_back(start);
	visited[start] = true;
	while(!queue.empty()){
		ele = queue.front();
		cout<< ele <<" ";
		queue.pop_front();
		
		for(int i = 0; i<adj[ele].size(); i++){
			adjVertex = adj[ele][i];
			if(!visited[adjVertex]){
				visited[adjVertex] = true;
				queue.push_back(adjVertex);
			}
		}
		
	
	}


}

int main(){
	
	int n = 5, e = 6, u, v;
	vector<int>adj[5];
	
	for(int i = 0; i<e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bfs(adj, adj[0][0], n);
	
	return 0;
}
