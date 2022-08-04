/*
	*Bidirectional Search
	*T.c -> O(b^d/2)
	*b = branching factor
	*d = distance between source vertex to goal vertex
*/

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>adj[], queue<int>&que,  vector<bool>&visited, vector<int>&path){
	
	int ele = que.front();
	que.pop();
	for(auto i = adj[ele].begin(); i != adj[ele].end(); i++){
		if(!visited[*i]){
			que.push(*i);
			visited[*i] = true;
			path[*i]  = ele;
		}
	}

}

int is_intersect(vector<bool>v_f, vector<bool>v_b){
	
	for(int i = 0; i < v_f.size(); i++){
		if(v_f[i] && v_b[i])
			return i;
	}
	return -1;
}

void print_path(vector<int>pathf, vector<int>pathb, int point, int src, int dest){
	
	vector<int>path;
	path.push_back(point);
	int i = point;
	while( i != src){
		path.push_back(pathf[i]);
		i = pathf[i];
	}
	reverse(path.begin(), path.end());
	i = point;
	while(i != dest){
		path.push_back(pathb[i]);
		i = pathb[i];
	}
	
	for(auto j = path.begin(); j != path.end(); j++)
		cout<<*j<<" ";

}

void find_path(vector<int>adj[], int src, int dest, int n){
	queue<int>que_f, que_b;
	vector<bool>visited_f(n, false), visited_b(n, false);
	vector<int>path_f(n), path_b(n);
	int intersect_point;
	que_f.push(src);
	que_b.push(dest);
	
	while(!que_f.empty() && !que_b.empty()){
		
		bfs(adj, que_f,visited_f, path_f);
		bfs(adj, que_b,visited_b, path_b);
		intersect_point = is_intersect(visited_f, visited_b);
		if(intersect_point != - 1){
			print_path(path_f, path_b, intersect_point, src, dest);
			return;
		}
	
	}
	
	cout<<-1;
	

}


int main(){

	int n,e, u, v, src, dest;
	cin>>n>>e;
	vector<int>adj[n];
	for(int i = 0; i<e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin>>src>>dest;
	
	find_path(adj, src, dest, n);

	return 0;
}
