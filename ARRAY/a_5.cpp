/*
  *Rearrange array such that arr[i] >= arr[j] if i is even and arr[i]<=arr[j] if i is odd and j < i
  *T.c -> O(n+logn)
  *S.c -> O(n)

*/
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, v, *arr, *temp;
  cin>>n;
  arr = new int[n];
  temp = new int[n];
  for(int i = 0;i  < n; i++){
    cin>>v;
    arr[i] = v;
    temp[i] = v;
  }
  cout<<endl;
  for(int i = 0; i <n;  i++)
    cout<<arr[i]<<" ";
  sort(temp, temp+n);
  int p = 0, q = n-1;
  for(int i = n-1; i > -1; i--){
    if(i%2 != 0){
      arr[i] = temp[q];
      q--;
    }else{
      arr[i] = temp[p];
      p++;
    }
  }
  cout<<endl;
  for(int i = 0; i <n;  i++)
    cout<<arr[i]<<" ";

  return 0;
}