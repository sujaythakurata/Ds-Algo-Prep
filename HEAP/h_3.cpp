/*
  *k largest(or smallest) elements in an array
  *T.c -> O(klogk + (n-k)logk) =>O(nlogk)
  *S.c -> O(k)
*/

#include<bits/stdc++.h>
using namespace std;

class heap{
  public:
    int *arr,  size = 0,  cap = 0;
    heap(int cap){
      arr = new int[cap];
      this->cap = cap;
    }

};

heap*insert(heap*root, int v){
  if(root->size == root->cap)
    return root;
  root->arr[root->size] = v;
  int child = root->size;
  int parent = child/2;
  root->size++;
  while(child>0){
    if(root->arr[parent] > root->arr[child]){
      swap(root->arr[parent], root->arr[child]);
      child = parent;
      parent = child/2;
    }else break;
  }

  return root;
}

void heapify(heap*&root, int pos){
  int left = 2*pos+1;
  int right = 2*pos+2;
  int smallest = pos;
  if(left < root->cap && root->arr[left] < root->arr[smallest])
    smallest = left;
  if(right < root->cap && root->arr[right] < root->arr[smallest])
    smallest = right;
  if(pos != smallest){
    swap(root->arr[smallest], root->arr[pos]);
    heapify(root, smallest);
  }
}


int main(){
  int n, k, v;
  cin>>n>>k;
  heap*root = new heap(k);
  int arr[n];
  for(int i = 0; i < n; i++){
    cin>>v;
    arr[i] = v;
  }
  for(int i = 0; i < k; i++)
    root = insert(root, arr[i]);
  //kth element
  for(int i = k; i < n ;i++){
    if(arr[i] > root->arr[0]){
      root->arr[0] = arr[i];
      heapify(root, 0);
    }
  }

  for(int i = 0; i < k; i++)
    cout<<root->arr[i]<<" ";

  return 0;
}