/*
	
	*Find the minimum number of moves needed to move from one cell of matrix to another
	*T.c -> O(n^2)
	*S.c -> O(n^2)
	
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>graph[], int u, vector<bool>&visited, vector<int>&level){
	
	visited[u] = true;
	for(auto j = graph[u].begin(); j != graph[u].end(); j++){
		if(!visited[*j]){
			level[*j] = level[u] + 1;
			dfs(graph, *j, visited, level);
		}
	}

}

int main(){
	int n,v, dest, src, root, node;
	cin>>n;
	vector<int>adj[n];
	vector<int>graph[n*n];
	vector<bool>visited(n*n, false);
	vector<int>level(n*n, 0);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>v;
			adj[i].push_back(v);
			if(v == 2)
				dest = (i*n)+j;
			if(v == 1)
				src = (i*n)+j;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(adj[i][j] == 0)
				continue;
			root = (i*n)+j;
			//top node
			if(i - 1 > -1 && adj[i-1][j] != 0){
				node = ((i-1)*n) + j;
				graph[root].push_back(node);
			}				
									
			//bottom node
			if(i + 1 <n && adj[i+1][j] != 0){
				node = ((i+1)*n) + j;
				graph[root].push_back(node);
			}	
			
			//left node
			if(j - 1 > -1 && adj[i][j-1] != 0){
				node = (i*n) + j - 1;
				graph[root].push_back(node);
			}	
			//right node
			if(j + 1 < n && adj[i][j+1] != 0){
				node = (i*n) + j + 1;
				graph[root].push_back(node);
			}	
		}
	}
	
	for(int i = 0; i < n*n; i++){
		cout<<i<<" I: ";
		for(auto j = graph[i].begin(); j != graph[i].end(); j++)
			cout<<*j<<" ";
		cout<<endl;
	}
	
	
	
	
	dfs(graph, src, visited, level);
	cout<<" src: "<<src<<" dest: "<<dest<<endl;
	for(auto j = level.begin(); j != level.end(); j++)
		cout<<*j<<" ";
	
	
	
	
	return 0;
}
