/*
  *Two Dimensional Binary Indexed Tree or Fenwick Tree
  *T.c -> O(mnlogmn) -> to create the tree m = number of rows n = number of columns
  *T.c -> O(logmn) -> update and search
  *S.c -> O(mn)
*/
#include<bits/stdc++.h>
using namespace std;

int getNext(int index){
  return index + (index & -index);
}

int getParent(int index){
  return index - (index & -index);
}

int** update(int**arr, int x, int y, int val, int row, int col){
  int x_ = x, y_ = y;
  while(x_ < row+1){
    y_ = y;
    while(y_ < col+1){
      arr[x_][y_] += val;
      y_ = getNext(y_);
    }
    x_ = getNext(x_);
  }
  return arr;
}

int getSum(int**arr, int x, int y){
  int s = 0;
  int x_ = x+1;
  int y_ = y+1;
  while(x_>0){
    y_ = y+1;
    while(y_>0){
      s += arr[x_][y_];
      y_ = getParent(y_);
    }
    x_ = getParent(x_);
  }
  return s;
}

int totalSum(int**arr, int x, int y, int x2, int y2){
  int incl1 = getSum(arr, x2, y2);
  int excl1 = getSum(arr, x-1, y2);
  int incl2 = getSum(arr, x-1, y-1);
  int excl2 = getSum(arr, x2, y-1);
  return incl1+incl2-excl1-excl2;
}

int**constructTree(int**arr, int row, int col){
  int**tree;
  tree =  new int*[row+1];
  for(int i = 0; i<row+1; i++)
    tree[i] = new int[col+1];
  memset(tree, 0, sizeof(tree));
  for(int i = 1; i<=row; i++){
    for(int j = 1; j<=col; j++)
      tree = update(tree, i, j, arr[i-1][j-1], row, col);
  }
  return tree;
}

int main(){
  int row, col, **arr, q, s, x, y,x2, y2,val;
  cin>>row>>col>>q;
  arr = new int*[row];
  for(int i =0; i<row; i++)
    arr[i] = new int[col];
  for(int i = 0; i<row; i++)
    for(int j = 0;  j<col; j++)
      cin>>arr[i][j];
  int**tree = constructTree(arr, row, col);
  for(int i = 0; i<q; i++){
    cin>>s>>x>>y;
    if(s == 0){
      cin>>x2>>y2;
      cout<<totalSum(tree, x, y, x2, y2)<<endl;
    }
    else{
      cin>>val;
      tree = update(tree, x, y, val, row, col);
    }
  }
}
