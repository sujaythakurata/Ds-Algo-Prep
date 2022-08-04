/*
  *Check if a given Binary Tree is SumTree
  *T.c -> O(n) 
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

int checksum(node*root){
  int left = 0, right = 0;
  if(root->left != NULL)
    left = checksum(root->left);
  if(root->right != NULL)
    right = checksum(root->right);
  if(left == 0 && right == 0)
    return root->key;
  if(left + right == root->key)
    return left + right + root->key;
  return 0;

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
  cout<<endl;
  if(checksum(root))
    cout<<"Yes";
  else
    cout<<"No";




}