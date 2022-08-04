/*
  *Rotate Matrix Elements
  *T.c -> O(m*n) m = number of rows n = number of columns
  *S.c -> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void print(int**arr, int m, int n){
  for(int i = 0; i<m ; i++){
    for(int j = 0; j<n ; j++)
      printf("%d ", arr[i][j]);
    cout<<endl;
  }
}

int main(){
  int m,n,**arr;
  cin>>m>>n;
  arr = new int*[m];
  for(int i = 0; i <m; i++){
    arr[i] = new int[n];
    for(int j = 0; j<n; j++)
      cin>>arr[i][j];
  }

  print(arr,m,n);
  int prev_m = m, prev_n = n;

  int row = 0, col = 0, prev, cur;

  while(row+1<m && col+1<n){
    prev = arr[row+1][col];
    //first row
    for(int i = col; i < n; i++){
      cur = arr[row][i];
      arr[row][i] = prev;
      prev = cur;
    }
    row++;

    //last column
    for(int i = row; i<m; i++){
      cur = arr[i][n-1];
      arr[i][n-1] = prev;
      prev = cur; 
    }
    n--;

    //last row
    if(row<m){
      for(int i = n-1; i >= col; i--){
        cur = arr[m-1][i];
        arr[m-1][i] = prev;
        prev = cur;
      }
    }
    m--;
    //first column
    if(col<n){
      for(int i = m-1; i>=row; i--){
        cur = arr[i][col];
        arr[i][col] = prev;
        prev = cur;
      }
    }
    col++;
    
  }

  cout<<endl;
  print(arr,prev_m,prev_n);

  
}