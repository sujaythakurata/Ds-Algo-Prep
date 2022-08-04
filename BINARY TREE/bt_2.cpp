/*
  *Binary Tree (Array implementation)
  *T.c -> O(n)
  *S.c -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

void insert_node(int v, vector<int>&tree){
  queue<int>que;
  que.push(0);
  int pos;
  while(!que.empty()){
    pos = que.front();
    que.pop();
    if(tree[pos] == -9999){
      tree[pos] = v;
      break;
    }
    que.push((2*pos)+1);
    que.push((2*pos)+2);
  }
}

void print_tree(vector<int>tree, int n){
  queue<int>que;
  que.push(0);
  int pos;
  while(!que.empty()){
    pos = que.front();
    que.pop();
    cout<<tree[pos]<<" ";
    if(tree[(2*pos)+2] != -9999 && (2*pos)+2 < n)
      que.push((2*pos)+2);
    if(tree[(2*pos)+1] != -9999 && (2*pos)+1 < n)
      que.push((2*pos)+1);
    
  }
}

int main(){
  int n, v;
  cin>>n;
  vector<int>tree(n, -9999);
  for(int i = 0; i < n;i ++){
    cin>>v;
    insert_node(v, tree);
  }
  print_tree(tree, n);

  return 0;
}