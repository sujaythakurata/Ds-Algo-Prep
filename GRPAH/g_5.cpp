/*
	*Best First Search
	*T.c  -> O(n*logn)
	*S.c -> O(n+e)
*/

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

void getPath(vector<pi>adj[],int n, int src, int target){
	priority_queue<pi, vector<pi>, greater<pi>>pq;
	vector<bool>vs(n,false);
	pi ele;
	
	pq.push(make_pair(0,src));
	vs[src] = true;
	while(!pq.empty()){
		ele = pq.top();
		pq.pop();
		cout<<ele.second<<" ";
		if(ele.second == target)
			return;
			
		for(int i = 0; i < adj[ele.second].size(); i++){
			if(!vs[adj[ele.second][i].first]){
				vs[adj[ele.second][i].first] = true;
				pq.push(make_pair(adj[ele.second][i].second, adj[ele.second][i].first));
			}
		}
	}
	
}

int main(){
	int n, e, u,v, cost, src, target;
	cin>>n>>e;
	vector<pi>adj[n];
	
	for(int i = 0; i < e; i++){
		cin>>u>>v>>cost;
		adj[u].push_back(make_pair(v,cost));
		adj[v].push_back(make_pair(u,cost));
	}
	cin>>src>>target;
	getPath(adj, n, src, target);

	return 0;
}
