/*
  *Check if all leaves are at same level
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
    if(temp->left == NULL){
      temp->left = new node();
      temp->left->key = val;
      break;
    }else que.push(temp->left);
    if(temp->right == NULL){
      temp->right = new node();
      temp->right->key = val;
      break;
    }else que.push(temp->right);
  }
  return root;
}

void print_tree(node * root){
  if (root == NULL)
    return;
  cout<<root->key<<" ";
  print_tree(root->left);
  print_tree(root->right);
}

bool same_level(node*root, int level,int &leaflevel){
  if(!root)
    return true;
  if(!root->left && !root->right){
    if(!leaflevel)
      leaflevel = level;
    return (leaflevel == level);
  }

  return same_level(root->left, level+1, leaflevel) && same_level(root->right, level+1, leaflevel);

}





int main(){

  int n, v, a, b;
  node*root = NULL;
  cin>>n;
  for(int i = 0; i < n; i ++){
    cin>>v;
    root = insert_node(root, v);
  }

  print_tree(root);
  cout<<endl;
  int level = 0, leaflevel = 0;
  if(same_level(root, level,leaflevel))
    cout<<"Yes";
  else
    cout<<"No";




}