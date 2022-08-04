/*
  *Sorted Linked List to Balanced BST
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

void insert_node(node*&root, int val){
  if(root == NULL){
    root = new node(val);
    return;
  }
  node *temp = root;
  while(temp->right != NULL)
    temp = temp->right;
  temp->right = new node(val);

}

node* create_tree(node*&root, int n){
  if(n<=0)
    return NULL;
  node*left = create_tree(root, n/2);
  node*tree_root = new node(root->val);
  tree_root->left = left;
  root = root->right;
  tree_root->right = create_tree(root, n-n/2-1);
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

  int n, v;
  node*root = NULL;
  cin>>n;
  for(int i = 0; i < n;  i++){
    cin>>v;
    insert_node(root, v);
  }
  cout<<endl;
  node*tree_root = create_tree(root, n);
  print_tree(tree_root);


  return 0;
}