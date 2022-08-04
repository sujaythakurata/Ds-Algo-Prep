/*
  *Search an element in a sorted and rotated array
  *T.c => O(logn)
  *S.c => O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int pivot(int arr[],int l, int h){
  if(l>h)
    return -1;
  if(l == h)
    return h;
  int mid = (l+h)/2;
  if(mid<h && arr[mid] >arr[mid+1])
    return mid;
  if(mid>l && arr[mid] < arr[mid-1])
    return mid - 1;
  if(arr[l] <= arr[mid])
    return pivot(arr, mid+1, h);
  return pivot(arr, l, mid-1);
}

int binary_search(int arr[], int l, int h, int key){
  int mid;
  while(l <= h){
    mid = (l+h)/2;
    if(arr[mid] == key)
      return mid;
    if(arr[mid] > key)
      h = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}


int main(){
  int n = 9, arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key = 10;
  int p = pivot(arr, 0, n), index;
  if(p == -1){
    cout<<-1;
    return 0;
  }
  int l1 = 0, h1 = p, l2 = p+1, h2 = n-1;
  index = binary_search(arr, l1, h1,key);
  if(index == -1)
    index = binary_search(arr,l2,h2,key);
  cout<<index;
  return 0;
}