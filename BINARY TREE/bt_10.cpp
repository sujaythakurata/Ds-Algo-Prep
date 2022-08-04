/*
  *Construct a tree from Inorder and Level order traversals
  *T.c -> O(n^2) n = number of nodes
  *S.c -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int inorder_index = 0;

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

node*postorder(int in[], int lr[], int start, int end, unordered_map<int,int>hm){

  if (start>end)
    return NULL;
  int root = find_minimum(start,end, hm);
  node*left = postorder(in,lr, start, root-1, hm);
  node*right = postorder(in, lr, root+1, end, hm);
  node*r = new node(in[root]);
  r->left = left;
  r->right = right;
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


  node * root = postorder(in,lr,0, n-1, hm);
  print_tree(root);
  return 0;
}