/*
	*minimum initial vertices to travarse the whole matrix
	*adjacent cell value must be less or equal
	*T.c - > O(row*col(v+e))

*/

#include<bits/stdc++.h>

using namespace std;


void dfs(vector<int>adj[], int x, int y, vector<bool>visited[], int row, int col){
	
	visited[x][y] = true;
	//check right
	if(y + 1<col && adj[x][y] >= adj[x][y+1] && !visited[x][y+1])
		dfs(adj, x, y+1, visited, row, col);
		
	//check left
	if(y - 1> -1 && adj[x][y] >= adj[x][y-1] && !visited[x][y-1])
		dfs(adj, x, y-1, visited, row, col);
	
	//check below
	if(x + 1<row && adj[x][y] >= adj[x+1][y] && !visited[x+1][y])
		dfs(adj, x+1, y, visited, row, col);
	//check above
	if(x - 1>-1 && adj[x][y] >= adj[x-1][y] && !visited[x-1][y])
		dfs(adj, x-1, y, visited, row, col);

}

int main(){
	
	int row, col, value;
	cin>>row>>col;
	vector<int>adj[row];
	vector<pair<int, pair<int, int>>>pair_array(row*col);
	vector<bool>visited[row];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin>>value;
			adj[i].push_back(value);
			pair_array.push_back(make_pair(value, make_pair(i,j)));
			visited[i].push_back(false);
		}
	}
	
	sort(pair_array.begin(), pair_array.end());
	
	for(int j = pair_array.size() - 1; j > -1; j--){
		if(!visited[pair_array[j].second.first][pair_array[j].second.second]){
			cout<<"X: "<<pair_array[j].second.first<<" Y: "<<pair_array[j].second.second<<"\n";
			dfs(adj, pair_array[j].second.first, pair_array[j].second.second, visited, row, col);
		}
	}
	

	return 0;
}
