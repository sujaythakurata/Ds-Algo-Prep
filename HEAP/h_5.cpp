/*
  *K-ary Heap
  *T.c -> 
    *insertion -> O(log_k n)
    *deletion ->O(log_k n)
    *extract_min / max -> O(log_k n)
    *get_min / max -> O(1)
    *decrease_key -> O(log_k n)
  *S.c -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class heap{
  public:
    int *arr, size = 0, cap = 0;
    heap(int cap){
      arr = new int[cap];
      this->cap = cap;
    }
};

void insert(heap*&root, int val, int k){
  root->arr[root->size] = val;
  int child = root->size;
  int parent = child/k;
  root->size++;
  while(child >0){
    if(root->arr[child] > root->arr[parent])
      swap(root->arr[child], root->arr[parent]);
    else break;
    child = parent;
    parent = child/k;
  }
}

int get_max(heap*root){
  return root->arr[0];
}

void heapify(heap*&root, int pos, int k){
  int child[k], max_pos = pos, max_val = INT_MIN;
  for(int i = 0; i < k; i++)
    child[i] = k*pos+i+1;
  
  for(int i = 0; i < k; i++){
    if( child[i] < root->size && max_val < root->arr[child[i]]){
      max_val = root->arr[child[i]];
      max_pos = child[i];
    }
  }
  if(max_pos != pos){
    swap(root->arr[pos], root->arr[max_pos]);
    heapify(root, max_pos, k);
  }
  
}

int decrease_key(heap*&root, int old_val, int new_val, int k){
  int pos = -1;
  for(int i = 0; i < root->size; i++){
    if(root->arr[i] == old_val){
      root->arr[i] = new_val;
      pos = i;
    }
  }
  if(pos != -1){
    int child = pos;
    int parent = pos/k;
    while(child > 0){
      if(root->arr[child] > root->arr[parent])
        swap(root->arr[child], root->arr[parent]);
      else break;
      child = parent;
      parent = child/k;
    }
  }
  return pos;
}

int extract_max(heap*&root, int k){
    if(root->size == 0)
      return -1;
    int max_val = root->arr[0];
    root->arr[0] = root->arr[root->size-1];
    root->size--;
    heapify(root, 0, k);
    return max_val;
}

void delete_key(heap*&root, int val, int k){
  int pos = decrease_key(root, val, INT_MAX, k);
  if(pos != -1)
    extract_max(root, k);
}

void print_tree(heap*&root){
  for(int i = 0; i < root->size; i++)
    cout<<root->arr[i]<<" ";
  cout<<endl;
}



int main(){
  int n,k, v;
  cin>>n>>k;
  heap*root = new heap(n);
  for(int i = 0; i < n; i++){
    cin>>v;
    insert(root, v, k);
  }
  print_tree(root);
  for(int i = 0; i < n/2; i++)
    cout<<extract_max(root, k)<<" ";
  cout<<endl;
  print_tree(root);

  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>v;
    delete_key(root, v, k);
    print_tree(root);
  }

  return 0;
}