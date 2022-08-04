/*
	*Roots of a tree which give minimum height
	*T.c -> O(n)
	*S.c -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

queue<int> findnode(vector<int>adj[], vector<int>&degree, int n){
	
	queue<int>que;
	int ele, len;
	for(int i = 0; i < n; i++){
		if(degree[i] == 1)
			que.push(i);
	}
	
	while (n > 2){
		len = que.size();
		n -= len;
		for(int i = 0; i < len; i++){
			ele = que.front();
			que.pop();
			for(auto j = adj[ele].begin(); j != adj[ele].end(); j++){
				degree[*j]--;
				if(degree[*j] == 1)
					que.push(*j);
			}
		}
		
	}
	
	return que;

}

int main(){
	int n, e, u, v;
	cin>>n>>e;
	vector<int>adj[n];
	vector<int>degree(n, 0);
	queue<int>ans;
	
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	
	ans = findnode(adj, degree, n);
	while(!ans.empty()){
		cout<<ans.front()<<" ";
		ans.pop();
	}

	return 0;
}
