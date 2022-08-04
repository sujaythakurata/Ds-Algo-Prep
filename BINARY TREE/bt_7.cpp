/*
  *binary tree deletion
  *T.c -> O(n) i.e. h = the height of the tree
  *S.c -> O(h) i.e. n = number of nodes
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

void delete_node(int val, node*root){
  if(root == NULL)
    return;
  queue<node*>que;
  node *lnode = NULL, *rnode = NULL, *temp = NULL, *n;
  que.push(root);
  while(!que.empty()){
    n = que.front();
    que.pop();

    if(n->key == val)
        temp = n;
    if(n->left != NULL){
      que.push(n->left);
      lnode = n;
      rnode = NULL;
    }
    if(n->right != NULL){
      que.push(n->right);
      rnode = n;
      lnode = NULL;
    }
  }

  if(temp != NULL){
    temp->key = n->key;
    if(rnode)
      rnode->right = NULL;
    if(lnode)
      lnode->left = NULL;
    delete(n);
  }

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
  cin>>n;
  for(int i = 0; i < n;i++){
    cin>>v;
    delete_node(v, root);
    print_tree(root);
    cout<<endl;
  }


}