/*
  *Print Postorder traversal from given Inorder and Preorder traversals
  *T.c -> O(n) n = number of nodes
  *S.c -> O(n)

*/

#include<bits/stdc++.h>

using namespace std;
typedef int vi;
int preindex = 0;
void postorder(vi in[], vi pr[], int start, int end, unordered_map<int,int>hm){
  if(start > end)
    return;
  int root = hm[pr[preindex++]];
  postorder(in, pr, start, root-1, hm);
  postorder(in, pr, root+1, end, hm);
  cout<<in[root]<<" ";
}

int main(){
  int n, v;
  cin>>n;
  vi in[n], pr[n];
  unordered_map<int,int>hm;
  for(int i = 0; i < n; i++){
    cin>>v;
    in[i] = v;
    hm[v] = i;
  }
  for(int i = 0; i < n; i++){
    cin>>v;
    pr[i] = v;
  }

  

  postorder(in,pr,0, n-1, hm);
  

  return 0;
}