/*
  *Find if there is a path of more than k length from a source
  *T.c -> O(n!)
  *S.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<pair<int,int>>adj[], int u, int count, vector<bool>&vs, int k){
  pair<int,int> ele;
  bool flag = false;
  if(count >=k)
    return true;
  vs[u] = true;
  for(auto i = adj[u].begin(); i != adj[u].end(); i++){
    ele = *i;
    if(!vs[ele.first]){
      if(dfs(adj, ele.first, count+ele.second, vs, k))
        flag = true;
    }
  }
  vs[u] = false;
  return flag;
}

void kthpath(vector<pair<int,int>>adj[], int n, int k, int u){
  int count = 0;
  bool flag = false;
  pair<int,int>ele;
  vector<bool>vs(n, false);
  flag = dfs(adj, u, count, vs, k);

  if(flag)
    cout<<"Yes";
  else
    cout<<"No";
}

int main(){
  int n, e, u, v, w, k, src;
  cin>>n>>e>>k>>src;
  vector<pair<int, int>>adj[n];
  for(int i = 0; i < e; i++){
    cin>>u>>v>>w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  kthpath(adj, n, k, src);


  return 0;

}