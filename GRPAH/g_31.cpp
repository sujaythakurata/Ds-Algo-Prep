/*
  *Bellman–Ford Algorithm
  *T.c -> O(v^2) and for a complete grpah O(v^3)
  *S.c -> O(v)
*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
typedef vector<vector<int>> vvi;
#define int_max 99999

void print_path(vector<int>path, vector<int>dist, int u){
  if (u == -1)
    return;
  print_path(path, dist, path[u]);
  cout<<"("<<u<<" , "<<dist[u]<<") ";
}

void shortest_path(vvi adj, int n, int e, int src , int dest){
  vector<int>dist(n, int_max);
  vector<int>path(n);
  int u, v, w;
  dist[src] = 0;
  path[src] = -1;

  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < e; j++){
      u = adj[j][0];
      v = adj[j][1];
      w = adj[j][2];
      if(dist[u] != int_max && dist[u] + w < dist[v]){
        dist[v] = dist[u] + w;
        path[v] = u;
      }
    }
  }

  print_path(path, dist, dest);

}

int main(){
  int n, e, u,v,w, src,dest;
  cin>>n>>e>>src>>dest;
  vvi adj(e);
  for(int i = 0; i < e; i++){
    cin>>u>>v>>w;
    adj[i].push_back(u);
    adj[i].push_back(v);
    adj[i].push_back(w);
  }

  shortest_path(adj, n, e, src, dest);

  return 0;

}