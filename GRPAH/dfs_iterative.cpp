/*

	*dfs using iterative method
	*T.c -> O(v+e)
	*S.c => O(v)

*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
	
	int n, e, u, v, ele;
	cin>>n>>e;
	
	vector<int>adj[n];
	vector<bool>visited(n,false);
	vector<int>stack(n);
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
		
	stack.push_back(adj[0][0]);
	
	while(!stack.empty()){
		ele = stack.back();
		stack.pop_back();
		if(!visited[ele]){
			cout<<ele<<" ";
			visited[ele] = true;
		}
		for(auto i = adj[ele].begin(); i != adj[ele].end(); i++){
			if(!visited[*i])
				stack.push_back(*i);
		}
	
	}
	
	
	

	return 0;
}
