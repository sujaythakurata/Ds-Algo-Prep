/*

	*Maximum number of edges to be added to a tree so that it stays a Bipartite graph
	*T.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;

int bfs(vector<int>adj[], int u, vector<int>&color, vector<bool>&visited, int n){
	queue<int>que;
	int c1 = 0, c2 = 0;
	que.push(u);
	c1 += 1;
	visited[u] = true;
	while(!que.empty()){
		u = que.front();
		que.pop();
		for(auto i = adj[u].begin(); i != adj[u].end(); i++){
			if(!visited[*i]){
				que.push(*i);
				visited[*i] = true;
				if(color[u] == 0){
					color[*i] = 1;
					c2++;
				}else
					c1++;
			}
		}
	
	}
	
	return (c1*c2)-(n-1);
	

}


int main(){
	int n,e,u,v;
	cin>>n>>e;
	vector<int>adj[n];
	vector<int>color(n, 0);
	vector<bool>visited(n, false);
	for(int i = 0; i<e; i++){
		cin>>u>>v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	
	cout<<bfs(adj, adj[0][0], color, visited, n);
	

	return 0;
}
