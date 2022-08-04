/*
  *Construct BST from given preorder traversal
  *T.c -> O(n) n = number of nodes
  *S.c -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int val;
    node*left = NULL, *right = NULL;
    node(int val){
      this->val = val;
    }
};

node* create_tree(vector<int>pre, int &index, int min_val, int max_val, int n){
  if(index >= n)
    return NULL;
  if(pre[index] >= min_val && pre[index] <= max_val){
    node*root = new node(pre[index]);
    index++;
    root->left = create_tree(pre, index, min_val, root->val, n);
    root->right = create_tree(pre, index, root->val, max_val, n);
    return root;
  }
  return NULL;
}

void print_tree(node*root){
  if(root == NULL)
    return;
  print_tree(root->left);
  cout<<root->val<<" ";
  print_tree(root->right);
}


int main(){
  int n, v, index = 0, min_val = 9999, max_val = -9999;
  node*root;
  vector<int>pre;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>v;
    pre.push_back(v);
    if(v<min_val)
      min_val = v;
    if(v>max_val)
      max_val = v;
  }
  root = create_tree(pre, index, min_val, max_val, n);
  print_tree(root);

  return 0;
}