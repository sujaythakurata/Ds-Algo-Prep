/*
  *leftist tree  / heap
  *T.c ->
    *merge => O(logn)
    *delete => O(logn)
    *insert => O(logn)
    *extract min / max => O(logn)
    *decrease key => O(logn)
    *build tree => O(nlogn)
  *S.c -> O(n)
  *Here I make the max heap
*/

#include<bits/stdc++.h>
using namespace std;

class heap{
  public:
    int val, dist = 0;
    heap*left = NULL, *right = NULL;
    heap(int val){this->val = val;}
};

heap*swap_child(heap*h1){
  heap*left = h1->left;
  h1->left = h1->right;
  h1->right = left;
  return h1;
}
heap*merge(heap*root, heap*new_tree);
heap*merge_tree(heap*h1, heap*h2){
  if(h1->left == NULL)
    h1->left = h2;
  else{
    h1->right = merge(h1->right, h2);
    if(h1->left->dist < h1->right->dist)
      h1 = swap_child(h1);
    h1->dist = 1 + h1->right->dist;
  }
  return h1;
}

heap*merge(heap*root, heap*new_tree){
  if(root == NULL)
    return new_tree;
  if(new_tree == NULL)
    return root;
  if(root->val > new_tree->val)
    return merge_tree(root, new_tree);
  return merge_tree(new_tree, root);
}

heap*insert(heap*root, int val){
  root = merge(root, new heap(val));
  return root;
}

void print_tree(heap*root){
  if(root == NULL)
    return;
  print_tree(root->left);
  cout<<root->val<<" ";
  print_tree(root->right);
}

int get_max(heap*root){
  return root->val;
}

int extract_max(heap*&root){
  heap*old_root = root;
  root = merge(root->left, root->right);
  return old_root->val;
}


heap*decrease_key(heap*root, int old_val, int new_val){
  if(root == NULL)
    return NULL;
  if(root->val == old_val){
    root->val = new_val;
    return root;
  }
  if(root->left != NULL){
    root->left = decrease_key(root->left, old_val, new_val);
    if(root->val < root->left->val)
      swap(root->val, root->left->val);
  }
  if(root->right != NULL){
    root->right = decrease_key(root->right, old_val, new_val);
    if(root->val < root->right->val)
      swap(root->val, root->right->val);
  }
  return root;
}

heap*delete_key(heap*root, int val){
  root = decrease_key(root, val, INT_MAX);
  extract_max(root);
  return root;
}


int main(){

  heap*root = NULL;
  int n, v;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>v;
    root = insert(root, v);
  }
  print_tree(root);
  cout<<endl;
  cout<<get_max(root);
  cout<<endl;

  for(int i = 0; i < n/2; i++)
    cout<<extract_max(root)<<" ";
  cin>>n;
  for(int i = 0; i < n ;i++){
    cin>>v;
    root = delete_key(root, v);
    print_tree(root);
  }
  cout<<endl;
  cout<<extract_max(root)<<" ";


  return 0;
}