/*
  *Binary Search Tree deletion
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


void delete_node(node*&root, int val){
  if(!root)
    return;
  if(val>root->val) delete_node(root->right, val);
  else if(val < root->val) delete_node(root->left, val);
  else{
    if(!root->left && !root->right)
      delete root;
    else if (!root->left){
      node*temp = root;
      root = root->right;
      delete temp;
    }
    else if(!root->right){
      node*temp = root;
      root = root->left;
      delete temp;
    }
    else{
      node*sp = root;
      node*s = root->right;
      while(s->left != NULL){
        sp = s;
        s = s->left;
      }
      if(sp == root)
        sp->right = s->right;
      else
        sp->left = s->right;
      root->val = s->val;
      delete s;
    }
  }
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
    delete_node(root, v);
    cout<<endl;
    print_pre_order(root);
    cout<<endl;
    print_post_order(root);
    cout<<endl;
  }
  

  return 0;
}