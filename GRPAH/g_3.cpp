/*
	*Minimum edge reversals to make a root
	*T.c -> O(n*n)
	*S.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;

int findNumberOfEdges(vector<pair<int, int>>adj[], int u, int n){
	queue<int>que;
	vector<bool>visited(n, false);
	int weight = 0;
	pair<int, int>ele;
	que.push(u);
	visited[u] = true;
	while(!que.empty()){
		u = que.front();
		que.pop();
		
		for(auto j = adj[u].begin(); j != adj[u].end(); j++){
			ele = *j;
			if(!visited[ele.first]){
				que.push(ele.first);
				visited[ele.first] = true;
				weight += ele.second;
			}
		}
	}
	
	return weight;
	

}

int main(){
	int n, e, u, v, min_edges = 99999, edge, root;
	
	cin>>n>>e;
	vector<pair<int, int>>adj[n];
	
	for(int i = 0; i<e; i++){
		cin>>u>>v;
		adj[u].push_back(make_pair(v,0));
		adj[v].push_back(make_pair(u, 1));
	}
	
	for(int i = 0; i < n; i++){
		edge = findNumberOfEdges(adj,i,n);
		if(edge < min_edges){
			min_edges = edge;
			root = i;
		}
	}
	
	cout<<root<<min_edges;
	
	
	

	return 0;
}
