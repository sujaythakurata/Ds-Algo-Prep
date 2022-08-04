/*
  *K’th Smallest/Largest Element in Unsorted Array 
  *T.c -> O(n) worst case O(n^2)
  *S.c -> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int partision(int*&arr, int l, int h){
  int pivot = arr[l], i = l, j = h;
  while(i<j){
    do{
      i++;
    }while(arr[i]<pivot);
    do{
      j--;
    }while(arr[j]>pivot);
    if(i<j)
      swap(arr[i], arr[j]);
  }
  swap(arr[l], arr[j]);
  return j;
}

int kth_smallest(int *&arr, int l, int h, int k){
  if(k>0 && k <= h+1){
    int pivot = partision(arr, l, h);
    if(pivot == k-1)
      return arr[pivot];
    if(pivot > k-1)
      return kth_smallest(arr, l, pivot,k);
    return kth_smallest(arr, pivot+1, h, k);
  }
  return INT_MAX;
}

int main(){
  int *arr, n, k, v;
  cin>>n>>k;
  arr = new int[n];
  for(int i = 0; i < n; i++){
    cin>>v;
    arr[i] = v;
  }
  cout<<kth_smallest(arr, 0, n, k);
  return 0;
}