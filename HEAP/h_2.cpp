/*
  *HeapSort
  *T.c -> O(nlogn) n = build the heap tree and logn = for heapify
  *S.c -> O(n)
*/
#include<bits/stdc++.h>

using namespace std;

class heap{
  public:
    int *arr, size = 0, cap = 0;
    heap(int cap){
      this->cap = cap;
      arr = new int[cap];
    }

};

heap*insert(heap*root, int v){
  if(root->size >= root->cap)
    return root;
  root->arr[root->size] = v;
  int parent = root->size/2;
  int child = root->size;
  root->size++;
  while(child>0){
    if(root->arr[parent] < root->arr[child]){
      swap(root->arr[parent], root->arr[child]);
      child = parent;
      parent = child/2;
    }else break;
  }
  return root;
}

void heapify(heap*&root, int pos, int size){
  int left = 2*pos+1;
  int right = 2*pos+2;
  int biggest = pos;
  if(left < size && root->arr[left] > root->arr[biggest])
    biggest = left;
  if(right < size && root->arr[right] > root->arr[biggest])
    biggest = right;
  if(pos != biggest){
    swap(root->arr[biggest], root->arr[pos]);
    heapify(root, biggest, size);
  }
}


int main(){
  int n, v;
  cin>>n;
  heap*root = new heap(n);
  for(int i = 0; i < n; i++){
    cin>>v;
    root = insert(root, v);
  }

  //sort it
  for(int i = 0;i < n;i++){
    swap(root->arr[0], root->arr[n-i-1]);
    heapify(root, 0, root->size-i-1);
  }

  for(int i = 0; i < root->size; i++)
    cout<<root->arr[i]<<" ";

  return 0;
}