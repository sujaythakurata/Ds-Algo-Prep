/*
  *Floyd Warshall Algorithm
  *T.c -> O(v^3)
  *S.c -> O(v^2)

*/

#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>>vvi;
typedef vector<int>vi;
#define int_max 9999

void print_path(vvi dist, vvi path, int src, int dest){
  if(dist[src][dest] == -1){
    cout<<-1;
    return;
  }
  cout<<"("<<src<<", "<<0<<") ";
  int u = src;
  while(src != dest){
    src = path[src][dest];
    cout<<"("<<src<<", "<<dist[u][src]<<") ";
  }
}

void shortest_path(vvi adj, int n, int src, int dest){
  vvi dist(adj);
  vvi next_path(n, vi(n, -1));
  for(int i = 0; i < n ;i++){
    for(int j = 0; j < n; j++){
      if(adj[i][j] == int_max)
        next_path[i][j] = -1;
      else
        next_path[i][j] = j;
    }
  }
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n ;i++){
      for(int j = 0; j < n; j++){
        if(dist[i][k] == int_max && dist[k][j] == int_max)
          continue;
        if(dist[i][j] > dist[i][k] + dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
          next_path[i][j] = next_path[i][k];
        }
      }
    }
  }

  print_path(dist, next_path, src, dest);

}


int main(){
  int n, e, u, v, w, src, dest;
  cin>>n>>e>>src>>dest;

  vvi adj(n, vi(n,int_max));

  for(int i = 0; i < e; i++){
    cin>>u>>v>>w;
    adj[u][v] = w;
    adj[v][u] = w;
  }

  shortest_path(adj, n, src, dest);


  return 0;
}