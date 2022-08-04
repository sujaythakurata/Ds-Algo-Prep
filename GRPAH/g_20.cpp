/*
	*Find length of the largest region in Boolean Matrix
	*T.c -> O(n^2)
	*S.c -> O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

int bfs(vector<int>adj[], int u, int v, vector<vector<bool>>&vs, int n, int m){
	int count = 0;
	queue<pair<int, int>>que;
	pair<int, int>ele;
	que.push({u,v});
	vs[u][v] = true;
	while(!que.empty()){
		ele = que.front();
		u = ele.first;
		v = ele.second;
		que.pop();
		count++;
		//top
		if(u-1 > -1 && adj[u-1][v] != 0 && !vs[u-1][v]){
			vs[u-1][v] = true;
			que.push({u-1, v});
		}
		//bottom
		if(u+1 < n && adj[u+1][v] != 0 && !vs[u+1][v]){
			vs[u+1][v] = true;
			que.push({u+1, v});
		}
		//left
		if(v-1 > -1 && adj[u][v-1] != 0 && !vs[u][v-1]){
			vs[u][v-1] = true;
			que.push({u, v-1});
		}
		
		//right
		if(v+1 < m && adj[u][v+1] != 0 && !vs[u][v+1]){
			vs[u][v+1] = true;
			que.push({u, v+1});
		}
		
		//top right
		if(u-1 > -1 && v+1 < m && adj[u-1][v+1] != 0 && !vs[u-1][v+1]){
			vs[u-1][v+1] = true;
			que.push({u-1, v+1});
		}
		
		//top left
		if(u-1 > -1 && v - 1 > -1 && adj[u-1][v-1] != 0 && !vs[u-1][v-1]){
			vs[u-1][v-1] = true;
			que.push({u-1, v-1});
		}
		
		//bottom right
		if(u+1 < n && v+1 < m && adj[u+1][v+1] != 0 && !vs[u+1][v+1]){
			vs[u+1][v+1] = true;
			que.push({u+1, v+1});
		}
		//bottom left
		if(u+1 < n && v-1 > -1 && adj[u+1][v-1] != 0 && !vs[u+1][v-1]){
			vs[u+1][v-1] = true;
			que.push({u+1, v-1});
		}
	}
	
	return count;
}

int main(){
	int n, m, ele, count = -1;
	cin>>n>>m;
	vector<int>adj[n];
	vector<vector<bool>>vs(n, vector<bool>(m, false));
	for(int i = 0; i <n; i++){
		for(int j = 0; j < m; j++){
			cin>>ele;
			adj[i].push_back(ele);
		}
	}
	
	for(int i = 0; i < n; i++){
	
		for(int j = 0; j < m; j++){
			if(adj[i][j] != 0 && !vs[i][j]){
				count = max(count, bfs(adj,i,j,vs, n, m));
			}
		}	
	}
	
	cout<<count;
	
	return 0;
}
