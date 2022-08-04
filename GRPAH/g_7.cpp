/*
	
	*Maximum product of two non-intersecting paths in a tree
	*T.c -> O(n*e)
	*S.c ->O(n+e)
	
*/

#include<bits/stdc++.h>

using namespace std;

int dfs(vector<int>adj[], int u, int v, int &curmax){
	
	int m1 = 0, m2 = 0;
	
	for(auto i = adj[u].begin(); i != adj[u].end(); i++){
		if(*i == v)
			continue;
		dfs(adj, *i, u, curmax);
		if(curmax > m1){
			m2 = m1;
			m1 = curmax;
		}
		else
			m2 = max(m2, curmax);
	}
	
	curmax = m1 + 1;
	return m1 + m2;

}

int main(){
	int n,u,v, max_product=-1, curmax, p1, p2;
	cin>>n;
	vector<int>adj[n];
	for(int i = 0; i < n-1; i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 0; i < n; i++){
		for(auto j = adj[i].begin(); j != adj[i].end(); j++){
			curmax = 0;
			p1 = dfs(adj, *j, i, curmax);
			curmax = 0;
			p2 = dfs(adj, i, *j, curmax);
			max_product = max(max_product, (p1*p2));
		}
	}
	
	cout<<max_product;
	
	
	return 0;
}
