/*
  *Find distance between two nodes of a Binary Tree
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

void parentify(node * root, unordered_map<node*,node*>&parent, unordered_map<node*,int>&level, 
node*&a, node*&b, int av, int bv){
  queue<node*>que;
  node*ele;
  que.push(root);
  level[root] = 0;
  parent[root] = NULL;
  while(!que.empty()){
    ele = que.front();
    if(ele->key == av && !a)
      a = ele;
    else if (ele->key == bv && !b)
      b = ele;
    que.pop();
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
}

int lca(node*root, int a, int b){
  unordered_map<node*, node*>parent;
  unordered_map<node*,int>level;
  node*a_node = NULL , *b_node = NULL, *temp_a, *temp_b;
  int count = 0;
  parentify(root, parent, level, a_node, b_node, a, b);
  while(parent[a_node] != parent[b_node] && parent[a_node] != b_node && parent[b_node] != a_node){
    temp_a = a_node;
    temp_b = b_node;
    if(parent[temp_a] && level[temp_a]>=level[temp_b]){
      a_node = parent[a_node];
      count++;
    }
    if(parent[temp_b] && level[temp_b]>=level[temp_a]){
      b_node = parent[b_node];
      count++;
    }
  }
  if(parent[b_node] == a_node || parent[a_node] == b_node)
    return ++count;
  
  return count+2;



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
  cout<<lca(root, a, b);

  return 0;



}