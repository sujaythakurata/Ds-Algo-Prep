/*
	
	*Find the minimum number of moves needed to move from one cell of matrix to another
	*T.c -> O(n^2)
	*S.c -> O(n^2)
	
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[], int x, int y, int count , int &mincount, int n, vector<bool>visited){
	if(adj[x][y] == 2){
		if(mincount > count)
				mincount = count;
		return;
	}
	visited[(x*n)+y] = true;
	
	//go top
	if(x - 1 > -1 && adj[x-1][y] != 0 && !visited[((x-1)*n)+y])
		dfs(adj, x-1, y, count + 1, mincount, n, visited);
	//go bottom
	if(x + 1 < n && adj[x+1][y] != 0 && !visited[((x+1)*n)+y])
		dfs(adj, x+1, y, count + 1, mincount, n, visited);
	
	//go left
	if(y - 1 > -1 && adj[x][y-1] != 0 && !visited[(x*n)+y-1])
		dfs(adj, x, y-1, count + 1, mincount, n, visited);
	
	//go right
	if(y+1 < n && adj[x][y+1] != 0 && !visited[(x*n)+y+1])
		dfs(adj, x, y+1, count + 1, mincount, n, visited);
	
	visited[(x*n)+y] = false;
}

int main(){
	int n,v, srcx, srcy, count = 0, min_count = 9999;
	cin>>n;
	vector<int>adj[n];
	vector<bool>visited(n*n, false);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>v;
			adj[i].push_back(v);
			if(v == 1){
				srcx = i;
				srcy = j;
			}
		}
	}
	
	dfs(adj, srcx, srcy, count, min_count, n, visited);
	cout<<min_count;
	
	
	
	
	return 0;
}
