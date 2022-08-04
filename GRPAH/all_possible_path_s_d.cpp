/*
	*Count all possible paths between two vertices
	*T.c -> O(n!)
	*S.c -> O(1)
*/

#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<int>adj[], int s, int d, vector<bool>&visited, int &count){
	
	visited[s] = true;
	if(s == d)
		count += 1;
	else{
		for(auto i = adj[s].begin(); i != adj[s].end(); i++){
			if(!visited[*i])
					dfs(adj, *i, d, visited, count);
		}
	}
	visited[s] = false;
}

int main(){
	
	int n, e, u, v, s, d, count = 0;
	cin>>n>>e;
	vector<int>adj[n];
	vector<bool>visited(n, false);
	
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	cin>>s>>d;
	
	for(int i = 0; i < n; i++){
		cout<<i<<" : ";
		for( auto j = adj[i].begin(); j != adj[i].end(); j++){
			cout<< *j << " ";
		}
		cout<<"\n";
	}
	
	dfs(adj, s, d, visited, count);
	cout<<count;

	return 0;
}


