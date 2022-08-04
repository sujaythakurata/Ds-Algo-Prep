/*
	*Kahn’s algorithm for Topological Sorting
	*T.c -> O(n+e)
	*S.c -> O(n) if graph is given otherwise O(n+e)
	
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, e, u, v, count = 0;
	cin>>n>>e;
	vector<int>adj[n];
	vector<int>degree(n, 0);
	queue<int>que;
	vector<int>ans;
	
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	for(int i = 0; i < e; i++){
		for(auto j = adj[i].begin(); j != adj[i].end(); j++){
			degree[*j]++;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(degree[i] == 0)
			que.push(i);
	}
	
	while(!que.empty()){
		u = que.front();
		que.pop();
		ans.push_back(u);
		for(auto j = adj[u].begin(); j != adj[u].end(); j++){
			degree[*j]--;
			if(degree[*j] == 0)
				que.push(*j);
		}
		
		count += 1;
	}
	
	if(count != n)
		cout<<-1;
	else{
		for(auto i = ans.begin(); i != ans.end(); i++)
			cout<<*i<<" ";
	}
	


	return 0;
}

