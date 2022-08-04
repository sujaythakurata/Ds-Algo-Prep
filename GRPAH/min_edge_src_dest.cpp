/*
	*Minimum number of edges between two vertices of a Graph
	*T.c -> O(n)

*/

#include<bits/stdc++.h>

using namespace std;

int get_distance(vector<int>adj[], int n, int src, int dest){
	queue<int>que;
	vector<bool>visited(n, false);
	vector<int>distance(n, 0);
	int ele;
	que.push(src);
	visited[src] = true;
	while(!que.empty()){
		
		ele = que.front();
		que.pop();
		for(auto i = adj[ele].begin(); i != adj[ele].end(); i++){
			if(!visited[*i]){
				que.push(*i);
				visited[*i] = true;
				distance[*i] = distance[ele] + 1;
			}
		}
		
	}
	
	return distance[dest];
}

int main(){
	
	int n, e, u, v, src, dest;
	cin>>n>>e;
	vector<int>adj[n];
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cin>>src>>dest;
	
	cout<<get_distance(adj, n, src, dest);
		
	return 0;
}
