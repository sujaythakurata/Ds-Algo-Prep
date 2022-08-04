/*
  *Sparse Table
  *T.c -> to build the table O(nlogn) and for query O(1)
  *S.c -> O(nlogn)
*/

#include<bits/stdc++.h>

using namespace std;
typedef vector<vector<int>>vvi;
void build_table(int *arr, vvi&table, int n){
  int block = log2(n);
  for(int i = 0; i < n;i++)
    table[i][0] = arr[i];
  for(int j = 1; pow(2, j)<=n; j++){
    for(int i = 0; i+pow(2,j-1)<n; i++)
      table[i][j] = min(table[i][j-1], table[i+pow(2,j-1)][j-1]);
  }
}

int query(vvi table, int l, int h){
  int block = h-l+1;
  int size = log2(block);
  return min(table[l][size], table[l+block-pow(2,size)][size]);
}

int main(){
  int n, q, l, h, *arr;
  cin>>n>>q;
  arr = new int[n];
  int block = log2(n);
  vvi table(n,vector<int>(block));
  for(int i = 0; i< n; i++)
    cin>>arr[i];
  build_table(arr, table, n);
  for(int i = 0; i < q; i++){
    cin>>l>>h;
    cout<<query(table, l, h)<<endl;
  }

  return 0;
}