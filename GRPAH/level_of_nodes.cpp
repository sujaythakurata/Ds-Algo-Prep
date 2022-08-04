/*

	*Level of Each node in a Tree from source node (using BFS)
	*T.c -> O(v)

*/

#include<bits/stdc++.h>

using namespace std;

void bfs(vector<int>adj[], int u, vector<bool>&visited, vector<int>&level, int n){
	
	list<int>queue(n);
	int ele;
	queue.push_back(u);
	while(!queue.empty()){
		ele = queue.front();
		queue.pop_front();
		visited[ele] = true;
		for(auto i = adj[ele].begin(); i != adj[ele].end(); i++){
			if(!visited[*i]){
				level[*i] = level[ele] + 1;
				queue.push_back(*i);
			}
		
		}
	}

}

int main(){

	int n, e, u, v;
	cin>>n>>e;
	vector<int>adj[n];
	vector<bool>visited(n, false);
	vector<int>level(n, 0);
	
	for(int i = 0; i<e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bfs(adj, 0, visited, level, n);
	for(int i = 0; i < n ; i++){
		cout<<i<<" : "<<level[i]<<endl;
	}

	return 0;
}
