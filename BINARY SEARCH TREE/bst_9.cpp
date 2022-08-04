/*
  *Red-black tree deletion
  *T.c -> O(h) means O(logn)
  *S.c -> O(n)
  *0 = black 1 = red
*/

#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int val, color = 1;
    node*left=NULL, *right=NULL,*parent=NULL;
    node(int val){
      this->val = val;
    }
};

void right_rotate(node*&x, node*&y){
  node* y_right = y->right;
  y->right = x;
  if(y_right != NULL)
    y_right->parent = x;
  if(x->parent != NULL){
    if(x->parent->left == x)
      x->parent->left = y;
    else 
      x->parent->right = y;
  }

  y->parent = x->parent;
  x->parent = y;
  x->left = y_right;

}

void left_rotate(node*&x, node*&y){
  node*y_left = y->left;
  y->left = x;
  if(y_left != NULL)
    y_left->parent = x;
  if(x->parent != NULL){
    if(x->parent->left == x)
      x->parent->left = y;
    else 
      x->parent->right = y;
  }
  y->parent = x->parent;
  x->parent = y;
  x->right = y_left;
}

void fix_validation(node*&root, node*&cn){
  if(cn->parent == NULL){
    cn->color = 0;
    root = cn;
    return;
  }
  if(cn->parent->color == 0)
    return;
  node*parent = cn->parent;
  node*gt_parent = parent->parent;
  node*uncle = NULL;
  int path1,path2;
  if(gt_parent->right == parent){
    uncle = gt_parent->left;
    path1 = 1;
  }else{
    uncle = gt_parent->right;
    path1 = 0;
  }
  if(parent->right == cn)
    path2 = 1;
  else
    path2 = 0;

  if(uncle == NULL || uncle->color == 0 ){
    if(path1 == 1 && path2 == 1)
      left_rotate(gt_parent, parent);
    else if(path1 == 0 && path2 == 0)
      right_rotate(gt_parent, parent);
    else if(path1 == 0 && path2 == 1){
      left_rotate(parent, cn);
      right_rotate(gt_parent, parent);
    }else{
      right_rotate(parent, cn);
      left_rotate(gt_parent, parent);
    }
    swap(gt_parent->color, parent->color);
    fix_validation(root, parent);
  }else{
    gt_parent->color = 1;
    parent->color = 0;
    uncle->color = 0;
    fix_validation(root, gt_parent);
  }
  

}

node*insert(node*root, int val, node*&pt){
  if(root == NULL){

    pt = new node(val);
    return pt;
  }
  node*cn;
  if(root->val > val){
    cn = insert(root->left, val, pt);
    root->left = cn;
  }
  else{
    cn = insert(root->right, val, pt);
    root->right = cn;
  }
  cn->parent = root;
  return root;


}

void print_tree(node*root){
  if(root == NULL)
    return;
  print_tree(root->left);
  cout<<root->val<<" ";
  print_tree(root->right);
}

void print_line(queue<node*>que, int n, int level){
  node*ele;
  int count = n-level;
  for(int i = 0;i<n-level;i++)
    cout<<" ";
  while(!que.empty()){
    ele = que.front();
    que.pop();
    if(ele->left)
      cout<<"/";
    cout<<"  ";
    if(ele->right)
      cout<<"\\";
    count++;
    if(count == n)
      cout<<"  ";
    
  }
}

void print_value(queue<node*>que, int n, int level){
  node*ele;
  int count = n-level;
  for(int i = 0;i<n-level;i++)
    cout<<" ";
  while(!que.empty()){
    ele = que.front();
    que.pop();
    cout<<ele->val<<"("<<ele->color<<") ";
    count++;
    if(count == n)
      cout<<"  ";
  }
}

void print_graphic(node*root, int n){
  if(root == NULL)
    return ;
  queue<node*>que;
  queue<node*>temp;
  node*ele;
  int count = 1, size, level = 0;
  que.push(root);
  while(!que.empty()){
    size = count;
    count = 0;
    temp = que;
    for(int i = 0; i < size ; i++)
    {
      ele = que.front();
      que.pop();
      if(ele->left){
        count++;
        que.push(ele->left);
      }
      if(ele->right){
        que.push(ele->right);
        count++;
      }
    }
    
    cout<<endl;
    n -= 1;
    print_value(temp, n, level);
    cout<<endl;
    level++;
    print_line(temp, n, level);
    
    
  }
}


node* bst_rm(node*root, int val, node*&pt, node*&leaf_node){
  if(root == NULL){
    pt = NULL;
    return root;
  }
  else if(root->val > val)
    root->left = bst_rm(root->left, val, pt, leaf_node);
  else if(root->val < val)
    root->right = bst_rm(root->right, val, pt, leaf_node);
  else{
    if(root->right == NULL && root->left == NULL){
      pt = leaf_node = root;
    }else if(root->right != NULL){
      node*sp = root;
      node*s = root->right;
      while(s->left != NULL){
        sp = s;
        s = s->left;
      }
      root->val = s->val;
      
      if(s->right != NULL){
        swap(s->val, s->right->val);
        pt = leaf_node = s->right;
      }else
        pt = leaf_node = s;
      
    }else{
      node*sp = root;
      node*s = root->left;
      while(s->right != NULL){
        sp = s;
        s = s->right;
      }
      root->val = s->val;
      
      if(s->left != NULL){
        swap(s->val, s->left->val);
        pt = leaf_node = s->left;
      }else
        pt = leaf_node = s;
    }
  }
  return root;
}

void fix_delete(node*&root, node*&cn){
  node*parent, *uncle;
  int path1;
  while(true){
    parent = cn->parent;
    uncle = NULL;
    path1 = -1;
    if(parent != NULL && parent->right == cn){
      uncle = parent->left;
      path1 = 0;
    }
    else if(parent != NULL){
      uncle = parent->right;
      path1 = 1;
    }
    if(cn == root)
      break;
    else if(cn->color == 1)
      break;
    else if(uncle != NULL && uncle->color == 1){
      parent->color = 1;
      uncle->color = 0;
      if(path1 == 0)
        right_rotate(parent, uncle);
      else
        left_rotate(parent, uncle);
      if(uncle->parent == NULL)
        root = uncle;
    }
    else if(uncle != NULL && uncle->right != NULL && uncle->right->color == 1){
      swap(uncle->color, parent->color);
      parent->color = 0;
      uncle->right->color = 0;
      if(path1 == 0)
        right_rotate(parent, uncle);
      else
        left_rotate(parent, uncle);
      cn = root;
      if(uncle->parent == NULL)
        root = uncle;
      break;
    }
    else if(uncle != NULL && uncle->left != NULL && uncle->left->color == 1){
      uncle->left->color = 0;
      uncle->color = 1;
      right_rotate(uncle, uncle->left);
      if(uncle->parent == NULL)
        root = uncle;
    }
    else{
      if(uncle != NULL)
        uncle->color = 1;
      cn = parent;
    }
  }
  cn->color = 0;
}

void delete_node(node*&leaf){
  if(leaf->parent == NULL){
    delete leaf;
    return;
  }
  if(leaf->parent->left == leaf)
    leaf->parent->left = NULL;
  else
    leaf->parent->right = NULL;
  leaf->parent = NULL;
  delete leaf;
}



int main(){
  int n,v;
  node*root=NULL, *cn, *leaf_node;
  cin>>n;
  for(int i = 0; i < n;i++){
    cin>>v;
    root = insert(root, v, cn);
    fix_validation(root,cn);
  }
  cout<<endl;
  print_tree(root);
  print_graphic(root, n);
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>v;
    root = bst_rm(root, v, cn, leaf_node);
    fix_delete(root, cn);
    delete_node(leaf_node);
    cout<<endl;
    print_tree(root);
    print_graphic(root, n);
  }

  return 0;
}