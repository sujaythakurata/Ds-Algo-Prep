/*
  *Threaded binary tree insertion & deletion
  *T.c ->O(logn)
  *S.c ->O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int val;
    bool lt = true, rt = true;
    node*left = NULL, *right = NULL;
    node(int val){
      this->val = val;
    }
};

node*insert(node*root,int val){
  if(root == NULL)
    return new node(val);
  node*ptr = root;
  node*par = NULL;
  while(ptr != NULL){
    par = ptr;
    if(ptr->val > val){
      if(ptr->lt != true)
        ptr = ptr->left;
      else break;
    }else{
      if(ptr->rt != true)
        ptr = ptr->right;
      else break;
    }
  }
  node*temp = new node(val);
  if(par->val > val){
    temp->left = par->left;
    temp->right = par;
    par->left = temp;
    par->lt = false;
  }else{
    temp->right = par->right;
    temp->left = par;
    par->right = temp;
    par->rt = false;
  }
  
  return root;
}

node*inorder_succ(node*ptr){
  if(ptr->rt)
    return ptr->right;
  ptr = ptr->right;
  while(ptr->lt != true)
    ptr = ptr->left;
  return ptr;
}

node*inorder_pre(node*ptr){
  if(ptr->lt)
    return ptr->left;
  ptr = ptr->left;
  while(ptr->rt != true)
    ptr = ptr->right;
  return ptr;
}

void print_tree(node*root){
  if(root == NULL)
    return;
  while(root->lt != true)
    root = root->left;
  while(root != NULL){
    cout<<root->val<<" ";
    root = inorder_succ(root);
  }
}

node*case_a(node*root, node*ptr, node*par){
  if(par == NULL)
    return NULL;
  if(par->left == ptr){
    par->left = ptr->left;
    par->lt = true;
  }else{
    par->right = ptr->right;
    par->rt = true;
  }
  delete ptr;
  return root;
}
node*case_b(node*root, node*ptr, node*par){
  node*child;
  if(!ptr->lt)
    child = ptr->left;
  else
    child = ptr->right;
  if(par == NULL)
    root = child;
  else if(par->left == ptr){
    par->left = child;
  }else{
    par->right = child;
  }
  node*su = inorder_succ(ptr);
  node*pre = inorder_pre(ptr);
  if(!ptr->lt)
    pre->right = su;
  else if(!ptr->rt)
    su->left = pre;
  delete ptr;
  return root;
}
node*case_c(node*root, node*ptr, node*par){
    node*sp = ptr;
    node*s = sp->right;
    while(!s->lt){
      sp = s;
      s = s->left;
    }
    ptr->val = s->val;
    if(s->lt && s->rt)
      root = case_a(root, s, sp);
    else
      root = case_b(root, s, sp);
    return root;
}


node*delete_node(node*root, int val){
  node*ptr = root;
  node*par = NULL;
  bool flag = false;
  while(ptr != NULL){

    if(ptr->val == val){
      flag = true;
      break;
    }
    par = ptr;
    if(ptr->val > val){
      if(ptr->lt != true)
        ptr = ptr->left;
      else break;
    }else{
      if(ptr->rt != true)
        ptr = ptr->right;
      else break;
    }
  }
  if(!flag) return root;

  if(ptr->lt && ptr->rt)
    root = case_a(root, ptr, par);
  else if(!ptr->lt && ptr->rt)
    root = case_b(root, ptr, par);
  else if(!ptr->rt && ptr->lt)
    root = case_b(root, ptr, par);
  else
    root = case_c(root, ptr, par);

  return root;

}




int main(){
  int n, v;
  node*root = NULL;
  cin>>n;
  for(int i = 0;i < n; i++){
    cin>>v;
    root = insert(root, v);
  }
  cout<<endl;
  print_tree(root);
  cout<<endl;
  cin>>n;
  for(int i = 0; i < n; i ++){
    cin>>v;
    root = delete_node(root, v);
    cout<<endl;
    print_tree(root);
  }
  return 0;
}