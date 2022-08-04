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


void iscontinus(node*root){
  if(root == NULL)
    cout<<"False";
  
  queue<node*>que;
  node*ele;
  bool flag = true;

  que.push(root);
  while(!que.empty()){
    ele = que.front();
    que.pop();
    if(ele->left != NULL){
      if(abs(ele->key - ele->left->key) == 1)
        que.push(ele->left);
      else{
        flag = false;
        break;
      }
    }
    if(ele->right != NULL){
      if(abs(ele->key - ele->right->key) == 1)
        que.push(ele->right);
      else{
        flag = false;
        break;
      }
    }
  }

  if(flag)
    cout<<"True";
  else
    cout<<"False";

  

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

  iscontinus(root);


}