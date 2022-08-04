/*
	*Minimum steps to reach target by a Knight
	*T.c -> O(n^2)
	*S.c -> O(n^2)

*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;

void find_min_path(pi src, int n, vector<int>&level){
	queue<pi>que;
	int root, node;
	vector<bool>visited(n*n,false);
	que.push(src);
	root = (src.first *n)+src.second;
	visited[root] = true;
	while(!que.empty()){
		
		src = que.front();
		que.pop();
		root = (src.first *n) + src.second;
		
		//move - 1
		node = ((src.first - 2)*n)+src.second+1;
		if(src.first - 2 > -1 && src.second + 1 < n && !visited[node]){
			que.push({src.first-2 , src.second+1});
			visited[node] = true;
			level[node] = level[root] + 1;
		}
		
		//move - 2
		node = ((src.first - 2)*n)+src.second-1;
		if(src.first - 2 > -1 && src.second - 1 > -1 && !visited[node]){
			que.push({src.first-2 , src.second-1});
			visited[node] = true;
			level[node] = level[root] + 1;
		}
		
		//move - 3
		node = ((src.first - 1)*n)+src.second-2;
		if(src.first - 1 > -1 && src.second - 2 > -1 && !visited[node]){
			que.push({src.first-1 , src.second-2});
			visited[node] = true;
			level[node] = level[root] + 1;
		}
		
		//move - 4
		node = ((src.first - 1)*n)+src.second+2;
		if(src.first - 1 > -1 && src.second + 2 < n && !visited[node]){
			que.push({src.first-1 , src.second+2});
			visited[node] = true;
			level[node] = level[root] + 1;
		}
		
		//move - 5
		node = ((src.first + 1)*n)+src.second-2;
		if(src.first+1 <n && src.second - 2 > -1 && !visited[node]){
			que.push({src.first+1 , src.second-2});
			visited[node] = true;
			level[node] = level[root] + 1;
		}
		
		//move - 6
		node = ((src.first +1)*n)+src.second+2;
		if(src.first + 1 < n && src.second + 2 < n && !visited[node]){
			que.push({src.first+1 , src.second+2});
			visited[node] = true;
			level[node] = level[root] + 1;
		}
		
		//move - 7
		node = ((src.first +2)*n)+src.second+1;
		if(src.first + 2 < n && src.second + 1 < n && !visited[node]){
			que.push({src.first+2 , src.second+1});
			visited[node] = true;
			level[node] = level[root] + 1;
		}
		
		//move - 8
		node = ((src.first +2)*n)+src.second - 1;
		if(src.first + 2 < n && src.second - 1 > -1 && !visited[node]){
			que.push({src.first+2 , src.second-1});
			visited[node] = true;
			level[node] = level[root] + 1;
		}
	
	}
	
}


int main(){
	int n, u, v;
	pi src, dest;
	cin>>n;
	vector<int>level(n*n, 0);
	cin>>u>>v;
	src = {u, v};
	cin>>u>>v;
	dest = {u, v};
	
	find_min_path(src,n,level);
	cout<<level[(dest.first*n)+dest.second];
	



	return 0;
}
