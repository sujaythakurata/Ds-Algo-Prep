/*
	*Height of a generic tree from parent array
	*T.c -> O(v)

*/

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>adj[], int u, int n, vector<bool>&visited, vector<int>&level, int &max_level){
	int ele;
	list<int>que(n);
	que.push_back(u);
	while(!que.empty()){
		ele = que.front();
		que.pop_front();
		visited[ele] = true;
		for(auto i = adj[ele].begin(); i != adj[ele].end(); i++){
			if(!visited[*i]){
				que.push_back(*i);
				level[*i] = level[ele] + 1;
				if(level[*i] > max_level)
					max_level = level[*i];
			}
		}
	
	}

}

int main(){
	int n,ele, max_level = 0;
	cin>>n;
	vector<int>parent(n);
	vector<int>adj[n];
	vector<int>level(n, 0);
	vector<bool>visited(n, false);
	for(int i = 0; i<n; i++){
		cin>>ele;
		parent[i] = ele;
	}
	
	for(int i = 0; i < n; i++){
		if(parent[i] != -1){
			adj[parent[i]].push_back(i);
			adj[i].push_back(parent[i]);
		}
	}
	bfs(adj, 0, n, visited, level,max_level);
	cout<<max_level;
	
	
	

	return 0;
}
