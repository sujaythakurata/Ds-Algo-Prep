/*
  *Binary Heap (Here max heap)
  *get_min() / max -> O(1)
  *extract_min() / max -> O(logn)
  *insert() -> O(logn)
  *decrease_key() -> O(logn)
  *delete() -> O(logn)
  *S.c -> O(n) n = heap capacity

*/

#include<bits/stdc++.h>
using namespace std;

class heap_tree{
  private:
    int cap;
    int heap_size = 0;
  public:
    int *arr;
    heap_tree(int cap){
      this->cap = cap;
      arr = new int[cap];
    }
    int get_cap(){return this->cap;}
    int get_heap_size(){return this->heap_size;}
    void set_heap_size(int size){this->heap_size = size;}
};

void insert(heap_tree*root, int val){
  int heap_size = root->get_heap_size();
  int parent = heap_size/2;
  root->arr[heap_size] = val;
  root->set_heap_size(heap_size+1);
  while(heap_size>0){
    if(root->arr[parent] < root->arr[heap_size]){
      swap(root->arr[parent], root->arr[heap_size]);
      heap_size = parent;
      parent = parent/2;
    }else break;
  }
  
}
void heapify(heap_tree*root, int index){
  int left = 2*index+1;
  int right = 2*index+2;
  int biggest = index;
  if(left < root->get_heap_size() && root->arr[left]>root->arr[biggest])
    biggest = left;
  if(right < root->get_heap_size() && root->arr[right]> root->arr[biggest])
    biggest = right;
  if(index != biggest){
    swap(root->arr[index], root->arr[biggest]);
    heapify(root, biggest);
  }
}
void delete_node(heap_tree*root, int index){
  root->arr[index] = root->arr[root->get_heap_size()-1];
  root->set_heap_size(root->get_heap_size()-1);
  heapify(root, index);
}

int get_max(heap_tree*root){return root->arr[0];}
int extract_max(heap_tree*root){
  int val = root->arr[0];
  delete_node(root, 0);
  return val;
}

void print_arr(heap_tree*root){
  for(int i = 0; i < root->get_heap_size(); i++)
    cout<<root->arr[i]<<" ";
}



int main(){
  int n, v;
  cin>>n;
  heap_tree*root = new heap_tree(n);
  for(int i = 0; i < n; i++){
    cin>>v;
    insert(root, v);
  }
  cout<<endl;
  print_arr(root);
  cin>>n;
  cout<<endl;
  for(int i = 0; i < n; i++){
    cout<<extract_max(root)<<" ";
  }
  cout<<endl;
  print_arr(root);

  return 0;
}