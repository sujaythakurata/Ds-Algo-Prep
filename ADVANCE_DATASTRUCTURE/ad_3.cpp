/*
  *Binary Indexed Tree or Fenwick Tree
  *T.c -> O(nlogn) -> to create the tree
  *T.c -> O(logn) -> update and search
  *S.c -> O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int getNext(int index){
  return index + (index & -index);
}

int getParent(int index){
  return index - (index & -index);
}

int* update(int*arr, int index, int val, int n){
  while(index < n+1){
    arr[index] += val;
    index = getNext(index);
  }
  return arr;
}

int getSum(int*arr, int index){
  int s = 0;
  index += 1;
  while(index > 0){
    s += arr[index];
    index = getParent(index);
  }
  return s;
}

int*constructTree(int*arr, int n){
  int*tree = new int[n+1];
  memset(tree, 0, n+1);
  for(int i = 1; i<=n; i++){
    tree = update(tree, i, arr[i-1], n);
  }
  return tree;
}

int main(){
  int n, *arr, q, s, index, val;
  cin>>n>>q;
  arr = new int[n];
  for(int i = 0; i<n; i++)
    cin>>arr[i];
  int*tree = constructTree(arr, n);
  for(int i = 0; i<q; i++){
    cin>>s>>index;
    if(s == 0)
      cout<<getSum(tree, index)<<endl;
    else{
      cin>>val;
      tree = update(tree, index, val, n);
    }
  }
}
