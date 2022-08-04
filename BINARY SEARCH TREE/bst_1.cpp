/*
  *Binary Search Tree | Set 1 (Search and Insertion)
  *T.c -> O(h) h -> height of the tree
  *S.c -> O(n) n -> number of nodes = 2^h-1
*/

#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int val;
  node *right = NULL, *left = NULL;
  node(int val){
    this->val = val;
  }
};

void insert_node(node* &root, int val){
  if(!root){
    root = new node(val);
    return;
  }
  queue<node*>que;
  node*ele;
  que.push(root);
  while(!que.empty()){
    ele = que.front();
    que.pop();
    if(val > ele->val){
      if(!ele->right){
        ele->right = new node(val);
        return;
      }else que.push(ele->right);
    }else{
      if(!ele->left){
        ele->left = new node(val);
        return;
      }else que.push(ele->left);
    }
  }
}

void print_pre_order(node*root){
  if(!root)
    return;
  print_pre_order(root->left);
  cout<<root->val<<" ";
  print_pre_order(root->right);
}

void print_post_order(node*root){
  if(!root)
    return;
  print_post_order(root->right);
  cout<<root->val<<" ";
  print_post_order(root->left);
}

int search(node*root, int val){
  queue<node*>que;
  node*ele;
  que.push(root);
  while(!que.empty()){
    ele = que.front();
    que.pop();
    if(ele->val == val)
      return val;
    if(ele->val > val && ele->left)
      que.push(ele->left);
    if(ele->val < val && ele->right)
      que.push(ele->right);
    
  }
  return -1;
}
int main(){
  int n, v;
  node*root=NULL;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>v;
    insert_node(root, v);
  }

  print_pre_order(root);
  cout<<endl;
  print_post_order(root);
  cout<<endl;
  cin>>n;
  for(int i = 0; i <n; i++){
    cin>>v;
    cout<<search(root, v);
    cout<<endl;
  }

  return 0;
}