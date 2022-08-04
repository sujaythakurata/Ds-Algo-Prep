/*
	*Print all paths from a given source to a destination using BFS
	*T.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;

bool visited(int u, vector<int>path){
		
		for(auto i = path.begin(); i != path.end() ; i++){
			if(*i == u)
				return true;
		}
		return false;
	
}

void print_graph(vector<int>path){
	for(auto i = path.begin(); i != path.end() ; i++){
			cout<<*i<<" ";
	}
	cout<<endl;
}

void bfs(vector<int>adj[], int n, int src, int dest){
	
	queue<vector<int>>que;
	vector<int>path;
	int ele;
	
	path.push_back(src);
	que.push(path);
	
	while(!que.empty()){
		path = que.front();
		ele = path.back();
		que.pop();
			
		if(ele == dest)
			print_graph(path);
		
		for(auto i = adj[ele].begin(); i != adj[ele].end(); i++){
			if(!visited(*i, path)){
				vector<int>new_path(path);
				new_path.push_back(*i);
				que.push(new_path);
			}
		}
	
	}
	
	
	
}


int main(){
		
	int n, e, u, v, src, dest;
	cin>>n>>e;
	vector<int>adj[n];
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	cin>>src>>dest;
	bfs(adj, n, src, dest);
	
	return 0;
}
