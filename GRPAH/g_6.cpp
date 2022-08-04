/*
	*Number of pair of positions in matrix which are not accessible
	*T.c -> O(n^2)
	*S.c -> O(n^2)

*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[], int u, vector<bool>&vs, int &count){
	
	vs[u] = true;
	for(auto i = adj[u].begin(); i != adj[u].end(); i++){
		if(!vs[*i]){
			count++;
			dfs(adj, *i,vs, count);
		}
	}

}

int count_pair(vector<int>adj[], int n){
	
	int count, ans = 0;
	vector<bool>vs(n, false);
	for(int i = 0; i < n*n; i++){
		if(!vs[i]){
			count = 1;
			dfs(adj, i, vs, count);
			ans += ((n*n) - count) * count;
		}
	}
	return ans;

}

int main(){
	int n, u, v, p, n1, n2;
	cin>>n>>p;
	vector<int>adj[n*n];
	for(int i = 0; i<p; i++){
		cin>>u>>v;
		n1 = ((u-1)*n)+v;
		cin>>u>>v;
		n2 = ((u-1)*n)+v;
		adj[n1-1].push_back(n2-1);
		
	}
	
	cout<<count_pair(adj,n);
	
	
	return 0;
}
