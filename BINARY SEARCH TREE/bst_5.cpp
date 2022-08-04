/*
  *Sorted Array to Balanced BST
  *T.c -> O(n) n = number of nodes
  *S.c -> O(n)

*/

#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int val;
    node*right = NULL, *left = NULL;
    node(int val){
      this->val = val;
    }
};
typedef vector<int>vi;


node* create_tree(vi arr, int &index, int n){
  if(n<=0)
    return NULL;
  node*left = create_tree(arr, index, n/2);
  node*tree_root = new node(arr[index]);
  tree_root->left = left;
  index++;
  tree_root->right = create_tree(arr, index, n-n/2-1);
  return tree_root;
}

void print_tree(node*root){
  if(root == NULL)
    return;
  print_tree(root->right);
  cout<<root->val<<" ";
  print_tree(root->left);
  
}


int main(){

  int n, v, index = 0;
  vi arr;
  cin>>n;
  for(int i = 0; i < n;  i++){
    cin>>v;
    arr.push_back(v);
  }
  cout<<endl;
  node*tree_root = create_tree(arr, index, n);
  print_tree(tree_root);


  return 0;
}