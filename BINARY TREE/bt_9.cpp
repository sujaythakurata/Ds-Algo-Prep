/*
  *Construct Tree from given Inorder and Preorder traversals
  *T.c -> O(n) n = number of nodes
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

node*postorder(int in[], int pre[], int start, int end, unordered_map<int,int>hm){

  if (start>end)
    return NULL;
  int root = hm[inorder_index++];
  node*left = postorder(in,pre, start, root-1, hm);
  node*right = postorder(in, pre, root+1, end, hm);
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
  int in[n], pre[n], temp[n];
  unordered_map<int,int>hm;
  for(int i = 0; i < n; i++){
    cin>>v;
    in[i] = v;
    temp[i] = v;
  }
  for(int i = 0; i < n; i++){
    cin>>v;
    pre[i] = v;
  }

  for(int i = 0; i < n; i++){
    v = pre[i];
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


  node * root = postorder(in,pre,0, n-1, hm);
  print_tree(root);
  return 0;
}