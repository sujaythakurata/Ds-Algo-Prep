/*
  *Inplace rotate square matrix by 90 degrees
  *T.c -> O(n^2)
  *S.c -> O(1)
*/

#include<bits/stdc++.h>

using namespace std;

void print(int**arr, int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      cout<<arr[i][j]<<" ";
    cout<<endl;
  }
}

int main(){

  int n, **arr, temp;
  cin>>n;
  arr = new int*[n];
  for(int i = 0; i < n ;i++){
    arr[i] = new int[n];
    for(int j = 0; j < n ; j++)
      cin>>arr[i][j];
  }

  for(int i = 0; i<n/2; i++){
    for(int j = i; j < n-i-1; j++){
      temp = arr[i][j];
      arr[i][j] = arr[j][n-1-i];
      arr[j][n-1-i] = arr[n-1-i][n-1-j];
      arr[n-1-i][n-1-j] = arr[n-1-j][i];
      arr[n-1-j][i] = temp;
    }
  }
  print(arr,n);

}