/*
  *Rearrange an array such that arr[i] = i
  *T.c -> O(n)
  *S.c -> O(1)
*/

#include<bits/stdc++.h>

using namespace std;

void print_arr(int*arr, int n){
  for(int i = 0; i < n; i++)
    cout<<*(arr+i)<<" ";
  cout<<endl;
}

void change(int*&arr, int pos){
  if(arr[pos] == pos || arr[pos] == -1){
    arr[pos] = pos;
    return;
  }
  int val = arr[pos];
  arr[pos] = pos;
  if(val != -1)
    change(arr, val);
}

void rearrange(int*&arr, int n){
  int val;
  for(int i = 0; i<n;i++){
    if(arr[i] != -1 && arr[i] != i){
      val = arr[i];
      arr[i] = -1;
      change(arr, val);
    }
  }
}

int main(){
  int n, v, *arr;
  cin>>n;
  arr = new int[n];
  for(int i = 0; i<n;i++){
    cin>>v;
    arr[i] = v;
  }
  print_arr(arr,n);

  rearrange(arr, n);

  print_arr(arr,n);


  return 0;
}