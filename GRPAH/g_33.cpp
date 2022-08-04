/*
  *Ford-Fulkerson Algorithm for Maximum Flow Problem
  *T.c -> O(v^3e)
  *S.c -> O(v^2)
*/

#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int bfs(vvi rg, vi &path, int n, int src, int dest){
  vector<bool>vs(n, false);
  queue<int>que;
  que.push(src);
  while(!que.empty()){
    src = que.front();
    que.pop();
    for(int i = 0; i < n ;i ++){
      if(!vs[i] && rg[src][i] > 0){
        que.push(i);
        path[i] = src;
        vs[i] = true;
        if(i == dest)
          return true;
      }
    }
  }
  return false;
}

void maxflow(vvi adj, int n, int src, int dest){
  vi path(n);
  vvi rg = adj;
  int max_flow = 0, flow, u, v;
  while(bfs(rg, path, n, src, dest)){
    flow = 9999;
    for(v = dest; v != src; v = path[v]){
      u = path[v];
      flow = min(flow, rg[u][v]);
    }
    max_flow += flow;
    cout<<"flow: "<<flow<<" ->";
    for(v = dest; v != src; v = path[v]){
      u = path[v];
      rg[u][v] -= flow;
      rg[v][u] += flow;
      cout<<"("<<u<<", "<<v<<") ";
    }
    cout<<endl;
  }
  cout<<max_flow;
}


int main(){
  int n , e, u, v, w, src, dest;
  cin>>n>>e>>src>>dest;
  vvi adj(n, vi(n, 0));
  for(int i = 0 ; i < e; i++){
    cin>>u>>v>>w;
    adj[u][v] = w;
  }

  maxflow(adj, n, src, dest);

  return 0;
}