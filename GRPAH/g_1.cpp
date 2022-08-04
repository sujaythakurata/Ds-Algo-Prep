/*
	*Count nodes within K-distance from all nodes in a set
	*T.c -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;


int bfs(vector<int>adj[], int u, int n, vector<int>marked, vector<int>&distance){
	queue<int>que;
	vector<int>visited(n, false);
	int lastmarked;
	que.push(u);
	visited[u] = true;
	
	while(!que.empty()){
		u = que.front();
		que.pop();
		if(find(marked.begin(), marked.end(), u) != marked.end())
			lastmarked = u;
		
		for(auto i = adj[u].begin(); i != adj[u].end(); i++){
			if(!visited[*i]){
				que.push(*i);
				visited[*i] = true;
				distance[*i] = distance[u] + 1;
			}
		}
	
	}
	
	return lastmarked;

}


int find_nodes(vector<int>adj[], int n, int k, int m, vector<int>marked){
	
	vector<int>temp(n, 0), d1(n, 0), d2(n, 0);
	int u,v, count=0;
	u = bfs(adj, 0, n, marked, temp);
	v = bfs(adj, u, n, marked, d1);
	bfs(adj, v, n, marked, d2);
		
	for(int i = 0; i < n; i++){
		
		if(d1[i] <= k && d2[i] <= k)
			count++;
	}
	
	return count;


}

int main(){
	
	int n, e, u, v, m, k;
	cin>>n>>e>>k>>m;
	vector<int>adj[n];
	vector<int>marked(n);
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 0; i < m; i++){
		cin>>u;
		marked[i] = u;
	}
	
	cout<<find_nodes(adj, n, k, m, marked);

	return 0;
}
