/*
  *Check sum of Covered and Uncovered nodes of Binary Tree
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

int sum_left(node*root){
  int s = root->key;
  if(root->left != NULL)
    s += sum_left(root->left);
  else if(root->right != NULL)
    s += sum_left(root->right);
  return s;
}

int sum_right(node*root){
  int s = root->key;
  if(root->right != NULL)
    s += sum_right(root->right);
  else if(root->left != NULL)
    s += sum_right(root->left);
  return s;
}

int total_sum(node*root){
  if(root != NULL)
    return root->key + total_sum(root->left) + total_sum(root->right);
  return 0;
}

bool checksum(node*root){
  int left = 0, right = 0, totalsum = 0;
  left = sum_left(root->left);
  right = sum_right(root->right);
  totalsum = total_sum(root);
  if(totalsum - (root->key+left+right) == left + right)
    return true;
  return false;

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