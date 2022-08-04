/*
  *Kruskal’s Minimum Spanning Tree Algorithm
  *T.c -> O(elogv) worst case O(v^2)
  *S.c -> O(v)

*/

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>pi;

int find(int u, vector<int>&parent, int v){
  if(parent[u] == -1 || parent[u] == u){
    parent[v] = u;
    return u;
  }
  return find(parent[u], parent, v);
}

void union_set(int u, int v, vector<int>&parent, vector<int>&rank){
  u = find(u, parent, u);
  v = find(v, parent, v);
  if(u == v)
    return;
  if(rank[u] > rank[v]){
    parent[v] = u;
    rank[u] += 1;
    return;
  }
  parent[u] = v;
  rank[v] += 1;
}


void mst(vector<pair<int,pi>>graph, int n, int e){
  vector<int>parent(n, -1);
  vector<int>rank(n,1);
  int u, v, w;
  for(int i = 0; i < e; i++){
    u = graph[i].second.first;
    v = graph[i].second.second;
    w = graph[i].first;

    if(find(u, parent, u) != find(v, parent, v)){
      union_set(u,v,parent, rank);
      cout<<u<<" - "<<v<<" : "<<w<<endl;
    }

  }
}

int main(){
  int n, e, u, v, w;
  cin>>n>>e;
  vector<pair<int, pi>>graph (e);
  for(int i = 0; i < e; i++){
    cin>>u>>v>>w;
    graph[i] = {w, {u, v}};
  }
  sort(graph.begin(), graph.end());

  mst(graph, n, e);

  return 0;

}