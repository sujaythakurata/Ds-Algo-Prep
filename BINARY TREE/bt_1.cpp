/*
  *binary tree insertion
  *T.c -> O(h) i.e. h = the height of the tree
  *S.c -> O(n) i.e. n = number of nodes
*/

#include<bits/stdc++.h>
using namespace std;
struct node{
  int key;
  node *left = NULL, *right = NULL;
};

node* insert_node(node*root, int val){
  if(root == NULL){
    root = new node();
    root->key = val;
    return root;
  }
  queue<node*>que;
  node*temp;
  que.push(root);
  while(!que.empty()){
    temp = que.front();
    que.pop();
    if(temp->right == NULL){
      temp->right = new node();
      temp->right->key = val;
      break;
    }else que.push(temp->right);
    if(temp->left == NULL){
      temp->left = new node();
      temp->left->key = val;
      break;
    }else que.push(temp->left);
  }
  return root;
}

void print_tree(node * root){
  if (root == NULL)
    return;
  cout<<root->key<<" ";
  print_tree(root->right);
  print_tree(root->left);
}

int main(){

  int n, v;
  node*root = NULL;
  cin>>n;
  for(int i = 0; i < n; i ++){
    cin>>v;
    root = insert_node(root, v);
  }

  print_tree(root);


}