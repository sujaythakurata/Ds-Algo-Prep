/*
	*Prim’s MST for Adjacency List Representation 
	*T.c -> O(elogv) e = number of edges and v = number of vertices
	*S.c -> O(v)

*/

#include<bits/stdc++.h>

using namespace std;
#define int_max 9999
typedef pair<int,int> pi;
void printmst(vector<int>parent, int n, vector<int>keys){
	for(int i = 1; i < n; i++)
		cout<<parent[i]<<" - "<<i<<" : "<<keys[i]<<endl;
}

void mst(vector<vector<int>>g, int n){

	vector<int>keys(n, int_max);
	priority_queue<pi, vector<pi>, greater<pi>>que;
	vector<bool>vs(n,false);
	vector<int>parent(n);
	pi ele;
	int u, v, w, e = g.size();

	keys[0] = 0;
	parent[0] = -1;
	que.push({0,0});

	while(!que.empty()){
		ele = que.top();
		que.pop();
		vs[ele.second] = true;
		//update the keys
		for(int i = 0; i < e; i++){
			u = g[i][0];
			v = g[i][1];
			w = g[i][2];
			if(u == ele.second && !vs[v] && keys[v] > w){
				que.push({w,v});
				parent[v] = ele.second;
				keys[v] = w;
			}
			else if(v == ele.second && !vs[u] && keys[u] > w){
				que.push({w,u});
				parent[u] = ele.second;
				keys[u] = w;
			}
		}

	}

	printmst(parent, n, keys);




}

int main(){
	int n, e, u, v, w;
	cin>>n>>e;
	vector<vector<int>>g(e);
	for(int i = 0; i < e; i++){
		cin>>u>>v>>w;
		g[i].push_back(u);
		g[i].push_back(v);
		g[i].push_back(w);
	}
	
	mst(g, n);
	
	return 0;
}
