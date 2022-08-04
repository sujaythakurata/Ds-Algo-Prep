/*
  *Construct a tree from Inorder and post order traversals
  *T.c -> O(n^2) n = number of nodes
  *S.c -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int g_index = 0;

class node{
  public:
    int key;
    node*left=NULL, *right =NULL;
  node(int key){
    this->key = key;
  }
};
int find_minimum(int start, int end, unordered_map<int,int>hm){
  int ans, prev = 9999;
  while(start<=end){
    if(prev > hm[start]){
      prev = hm[start];
      ans = start;
    }
    start++;
  }
  return ans;
}

node*postorder(int in[], int lr[], int start, int end, int n, unordered_map<int,int>hm){

  if (start>end || g_index>=n)
    return NULL;
  node*r = new node(in[g_index]);
  int root = hm[++g_index];
  if(root<end){
    node*left = postorder(in,lr, start, root, n, hm);
    node*right = postorder(in, lr, root+1, end, n, hm);
    r->left = left;
    r->right = right;
  }
  return r;
}

void print_tree(node*root){
  if(root == NULL)
    return;
  print_tree(root->left);
  print_tree(root->right);
  cout<<root->key<<" ";
}


int main(){
  int n, v, len, index = 0;
  cin>>n;
  len = n;
  int in[n], lr[n], temp[n];
  unordered_map<int,int>hm;
  for(int i = 0; i < n; i++){
    cin>>v;
    in[i] = v;
  }
  for(int i = 0; i < n; i++){
    cin>>v;
    lr[i] = v;
    temp[i] = v;
  }

  for(int i = 0; i < n; i++){
    v = in[i];
    index = 0;
    while(true){
      if(temp[index] == v){
        hm[i] = index;
        temp[index] = -9999;
        break;
      }
      index++;
    }
  }


  node * root = postorder(in,lr,0, n-1, n, hm);
  print_tree(root);
  return 0;
}