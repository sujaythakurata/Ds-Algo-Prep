/*
  *Sort an array in wave form
  *T.c -> O(n)
  *S.c -> O(1)
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, *arr;
  cin>>n;
  arr = new int[n];
  for(int i = 0;i<n;i++)
    cin>>arr[i];
  for(int i = 1; i<n-1; i+=2){
    if(arr[i] > arr[i-1])
      swap(arr[i], arr[i-1]);
    if(i+1<n-1 && arr[i]>arr[i+1])
      swap(arr[i], arr[i+1]);
  }
  for(int i = 0; i<n; i++)
    cout<<arr[i]<<" ";
}