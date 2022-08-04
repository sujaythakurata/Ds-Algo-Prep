/*
  *Check if two nodes are cousins in a Binary Tree
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

bool check_cousine(node*root, int a,int b){
  queue<node*>que;
  unordered_map<node*,int>level;
  unordered_map<node*,node*>parent;
  node*ele, *a_node = NULL, *b_node = NULL;
  que.push(root);
  level[root] = 0;
  while(!que.empty()){
    ele = que.front();
    que.pop();
    if(ele->key == a && !a_node)
      a_node = ele;
    else if(ele->key == b && !b_node)
      b_node = ele;

    if(a_node && b_node){
      if(level[a_node] == level[b_node] && parent[a_node] != parent[b_node])
        return true;
    }

    if(ele->left){
      que.push(ele->left);
      level[ele->left] = level[ele] + 1;
      parent[ele->left] = ele;
    }
    if(ele->right){
      que.push(ele->right);
      level[ele->right] = level[ele] + 1;
      parent[ele->right] = ele;
    }
  }
  return false;
}





int main(){

  int n, v, a, b;
  node*root = NULL;
  cin>>n>>a>>b;
  for(int i = 0; i < n; i ++){
    cin>>v;
    root = insert_node(root, v);
  }

  print_tree(root);
  cout<<endl;
  if(check_cousine(root, a,b))
    cout<<"Yes";
  else
    cout<<"No";




}