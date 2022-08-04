/*
	*Path in a Rectangle with Circles
	*T.c -> O(n*m*k)
	
*/

#include<bits/stdc++.h>

using namespace std;

void print_path(map<pair<int,int>, pair<int,int>>path, int u, int v){

	if (u == 0 && v == 0){
		cout<<u<<" , "<< v<<endl;
		return;
	}
	print_path(path, path[{u, v}].first, path[{u, v}].second);
	cout<<u<<" , "<<v<<endl;
}

bool possible(vector<vector<int>>&rect, int n, int m, int u, int v){
	
	if(rect[u][v] == -1)
		return false;
	
	list<pair<int,int>>que(n*m);
	map<pair<int,int>, pair<int,int>>path;
	pair<int,int> pos;
	que.push_back({u,v});
	
	while(!que.empty()){
		pos = que.front();
		que.pop_front();
		rect[pos.first][pos.second] = 1;
		
		if(rect[n-1][m-1] == 1){
			print_path(path, pos.first, pos.second);
			return (rect[n-1][m-1] == 1);
		}
		
		//check top
		if(pos.first - 1 > -1 && rect[pos.first-1][pos.second] != 1 && rect[pos.first-1][pos.second] != -1){
			que.push_back({pos.first-1, pos.second});
			path[{pos.first-1, pos.second}] = {pos.first, pos.second};
		}
		
		//check bottom
		if(pos.first + 1 < n && rect[pos.first+1][pos.second] != 1 && rect[pos.first+1][pos.second] != -1){
			que.push_back({pos.first+1, pos.second});
			path[{pos.first+1, pos.second}] = {pos.first, pos.second};
		}
		
		//check left
		if(pos.second - 1 > -1 && rect[pos.first][pos.second-1] != 1 && rect[pos.first][pos.second-1] != -1){
			que.push_back({pos.first, pos.second-1});
			path[{pos.first, pos.second-1}] = {pos.first, pos.second};
		}
		
		//check right
		if(pos.second + 1 < m && rect[pos.first][pos.second+1] != 1 && rect[pos.first][pos.second+1] != -1){
			que.push_back({pos.first, pos.second+1});
			path[{pos.first, pos.second+1}] = {pos.first, pos.second};
		}
		
		//check top right
		
		if(pos.second + 1 < m && pos.first - 1 > -1 && rect[pos.first-1][pos.second+1] != 1 && rect[pos.first-1][pos.second+1] != -1){
			que.push_back({pos.first-1, pos.second+1});
			path[{pos.first-1, pos.second+1}] = {pos.first, pos.second};
		}
		
		//check top left
		if(pos.second - 1 > -1 && pos.first -1 > -1 && rect[pos.first-1][pos.second-1] != 1 && rect[pos.first-1][pos.second-1] != -1){
			que.push_back({pos.first-1, pos.second-1});
			path[{pos.first-1, pos.second-1}] = {pos.first, pos.second};
		}
		
		//check bottom right
		if(pos.second + 1 < m && pos.first+1 <n && rect[pos.first+1][pos.second+1] != 1 && rect[pos.first+1][pos.second+1] != -1){
			que.push_back({pos.first+1, pos.second+1});
			path[{pos.first+1, pos.second+1}] = {pos.first, pos.second};
		}
		
		//check bottom left
		if(pos.second - 1 > -1 && pos.first +1 < n && rect[pos.first+1][pos.second-1] != 1 && rect[pos.first+1][pos.second-1] != -1){
			que.push_back({pos.first+1, pos.second-1});
			path[{pos.first+1, pos.second-1}] = {pos.first, pos.second};
		}
	
	}
	
	return (rect[n-1][m-1] == 1);
	

}

int main(){
	int n,m,k,r,x,y;
	cin>>n>>m>>k>>r;
	vector<int>posx(k);
	vector<int>posy(k);
	vector<vector<int>>rect(n, vector<int>(m,0));
	for(int i = 0; i < k; i++){
		cin>>x>>y;
		posx[i] = x;
		posy[i] = y;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int p = 0; p < k; p++){
				if(sqrt(pow((posx[p]-1-i), 2)+pow((posy[p]-1-j), 2)) <= r)
					rect[i][j] = -1;
			}
		}
	}
	
	for( int i = 0; i<n; i++){
		for(int j = 0; j<m; j++)
		cout<<rect[i][j]<<" ";
		cout<<endl;
	}
	
	if(possible(rect, n,m, 0, 0))
		cout<<"Possible"<<endl;
	else
		cout<<"Not Possible"<<endl;
	for( int i = 0; i<n; i++){
		for(int j = 0; j<m; j++)
		cout<<rect[i][j]<<" ";
		cout<<endl;
	}
	
	
	
	
	
	return 0;
}
