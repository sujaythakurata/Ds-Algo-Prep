/*
	*Count the number of nodes at given level in a tree using BFS
	*T.c -> O(v+e)

*/

#include<iostream>
#include<vector>
#include<list>

using namespace std;

int bfs(vector<int>adj[], int start, int l, vector<int>&level, vector<bool>&visited, int n){
	
	list<int>queue(n);
	queue.push_back(start);
	int ele, count = 0;
	
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
	
	for(int i = 0; i < n; i ++){
		if(level[i] == l)
			count++;
	}
	
	return count;

}

int main(){
	
	int n, e, u, v, l;
	cin>>n>>e;
	vector<int>adj[n];
	vector<int>level(n, 0);
	vector<bool>visited(n, false);
	
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cin>>l;
	
	for(int i = 0; i < n ; i++){
		cout<<i<<" : ";
		for(auto j = adj[i].begin(); j != adj[i].end(); j++)
			cout<<*j<<" ";
		cout<<"\n";
	
	}
	cout<<bfs(adj, 0, l, level, visited, n);
	return 0;
}
