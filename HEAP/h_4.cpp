/*
  *Implementation of Binomial Heap
  *T.c -> O(nlogn)
  *S.c -> O(n)
*/

#include<bits/stdc++.h>

using namespace std;

class heap{
  public:
    int val;
    int degree = 0;
    heap*parent = NULL, *sibling = NULL, *child = NULL;
    heap(int val){
      this->val = val;
    }

};

heap*binomial_link(heap*h1, heap*h2){
  heap*child = h2->child;
  h2->child = h1;
  h1->parent = h2;
  h1->sibling = child;
  h2->degree++;
  return h2;
}

heap*merge_heap(heap*h1, heap*h2){
  heap*root = h1;
  heap*sib;
  if(h1 == NULL)
    return h2;
  if(h2 == NULL)
    return h1;
  if(h1->degree > h2->degree)
    root = h2;
  while(h1 != NULL && h2 != NULL){
    if(h1->degree < h2->degree)
      h1 = h1->sibling;
    else if(h1->degree == h2->degree){
      sib = h1->sibling;
      h1->sibling = h2;
      h1 = sib;
    }else{
      sib = h2->sibling;
      h2->sibling = h1;
      h2 = sib;
    }
  }
  return root;
}

heap*adjust(heap*root){
  heap *prev = NULL, *cur = root, *next = root->sibling, *sib;
  while(next != NULL){
    if(cur->degree != next->degree || (next->sibling != NULL && cur->degree == next->sibling->degree))
    {
      prev = cur;
      cur = next;
    }
    else{
      if(cur->val < next->val){
        
        if(prev == NULL)
          root = next;
        else
          prev->sibling = next;
        cur = binomial_link(cur,next);
        cur = next;
      }
      else{
        cur->sibling = next->sibling;
        cur = binomial_link(next, cur);
        
      }
      
    }
    next = cur->sibling;
  }
  return root;
}

heap*insert(heap*root, int val){
  heap*new_node = new heap(val);
  root = merge_heap(root, new_node);
  root = adjust(root);
  return root;
}

int get_max(heap*root){
  int m = root->val;
  while(root->sibling != NULL){
    if(root->sibling->val > m)
      m = root->sibling->val;
    root = root->sibling;
  }
  return m;
}

heap*find_max_node(heap*&root){
  heap*prev = NULL, *cur = root, *max_node = cur;
  int m = cur->val;
  while(cur->sibling != NULL){
    if(cur->sibling->val>m){
      prev = cur;
      m = cur->val;
      max_node = cur->sibling;
    }
    cur = cur->sibling;
  }
  if(prev == NULL && max_node->sibling == NULL)
    root = NULL;
  else if (prev == NULL) {
    root = max_node->sibling;
  }
  else{
    prev->sibling = max_node->sibling;
  }
  return max_node;
}

heap*reverse_tree(heap*&tree){
  if(tree->sibling != NULL){
    heap*t = reverse_tree(tree->sibling);
    tree->sibling->sibling = tree;
    return t;
  }
  return tree;
}

heap*find_node(heap*&root, int val){
  if(root == NULL)
    return NULL;
  if(root->val == val)
    return root;
  heap*res = find_node(root->child, val);
  if(res != NULL)
    return res;
  return find_node(root->sibling, val);
}
void decrease_key(heap*&root, int old_val, int new_val){
  heap*node = find_node(root, old_val);
  node->val = new_val;
  while(node->parent != NULL){
    if(node->val > node->parent->val){
      swap(node->val, node->parent->val);
      node = node->parent;
    }else break;
  }
}




int extract_max(heap*&root){
  heap*max_node = find_max_node(root);
  int m = max_node->val;
  if(root == NULL && max_node->child == NULL)
    return m;
  heap*new_tree = NULL;
  if(max_node->child != NULL){
    new_tree = reverse_tree(max_node->child);
    max_node->child->sibling = NULL;
  }
  root = merge_heap(root, new_tree);
  root = adjust(root);
  return m;
}


void print_tree(heap*root){
  if(root == NULL)
    return;
  cout<<root->val<<" ";
  print_tree(root->child);
  cout<<endl;
  print_tree(root->sibling);
}

void delete_key(heap*&root, int val){
  decrease_key(root, val, INT_MAX);
  int v = extract_max(root);

}


int main(){
  int n, v;
  cin>>n;
  heap*root = NULL;
  for(int i = 0; i < n ; i++){
    cin>>v;
    root = insert(root, v);
  }
  print_tree(root);
  cout<<endl;
  cout<<"Max_value: "<<get_max(root);
  cout<<endl;
  delete_key(root, 7);
  cout<<endl;
  print_tree(root);
  cout<<endl;
  for(int i = 0; i < n-2; i++){
    cout<<"Max_value: "<<extract_max(root);
    cout<<endl;
    print_tree(root);
    cout<<endl;
  }
  return 0;
}