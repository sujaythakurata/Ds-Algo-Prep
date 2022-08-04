/*
  *Printing Paths in Dijkstra’s Shortest Path Algorithm
  *T.c -> worst case O(n^2) i.e n = number of total vertex best case O(n+e)
  *S.c -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;
#define intmax 9999
typedef pair<int, int> pi;


void printpath(vector<int>path, int u, vector<int>dist){
  if(u == -1)
    return;
  printpath(path, path[u], dist);
  cout<<"("<<u<<", "<<dist[u]<<") ";
}

void shortestpath(vector<pi>adj[], int src, int dest, int n){

  vector<int>dist(n, intmax);
  vector<bool>vs(n, false);
  vector<int>path(n);
  priority_queue<pi, vector<pi>, greater<pi>>que;
  pi ele, ngh;
  int w;
  que.push({0, src});
  path[src] = -1;
  dist[src] = 0;
  while(!que.empty()){
    ele = que.top();
    que.pop();
    vs[ele.second] = true;
    for(auto i = adj[ele.second].begin(); i != adj[ele.second].end(); i++){
      ngh = *i;
      w = dist[ele.second] + ngh.second;
      if(!vs[ngh.first] && w < dist[ngh.first]){
        dist[ngh.first] = w;
        que.push({w, ngh.first});
        path[ngh.first] = ele.second;
      }
    }
  }

  printpath(path, dest, dist);

}


int main(){
  int n, e, u, v, w, src, dest;
  cin>>n>>e>>src>>dest;
  vector<pi>adj[n];
  for(int i = 0; i < e; i++){
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u, w});
  }

  shortestpath(adj, src, dest, n);

  return 0;


}
