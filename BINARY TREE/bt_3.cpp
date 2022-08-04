/*
  *Foldable Binary Trees
  *T.c -> O(n) n = number of nodes
  *S.c -> O(n) 
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

void mirror(node*root){
  if(root == NULL)
    return;
  mirror(root->left);
  mirror(root->right);
  node*temp = root->left;
  root->left = root->right;
  root->right = temp;
}

bool issame(node*left, node*right){
  if(left == NULL && right == NULL)
    return true;
  else if(left != NULL && right != NULL && issame(left->left, right->left) && issame(left->right, right->right))
    return true;
  return false;
}

void ismirror(node*root){
  if(root == NULL)
    cout<<"True";
  
  mirror(root->left);
  if(issame(root->left, root->right))
    cout<<"True";
  else
    cout<<"False";
  mirror(root->left);

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

  ismirror(root);


}