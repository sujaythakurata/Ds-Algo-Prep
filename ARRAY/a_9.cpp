/*
  *Range LCM Queries using Segment Tree
  *T.c -> to build the tree O(n) and for each query O(logn)
  *S.c -> O(2*n)
*/

#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
  if(a == 0)
    return b;
  return gcd(b%a, a);
}
int lcm(int a, int b){
  return ceil((a*b)/gcd(a,b));
}
int*buildTree(int*arr, int *tree, int l, int h, int pos){
  if(l == h){
    tree[pos] = arr[l];
    return tree;
  }
  int mid = (l+h)/2;
  tree = buildTree(arr, tree, l, mid, 2*pos+1);
  tree = buildTree(arr, tree, mid+1, h, 2*pos+2);
  tree[pos] = lcm(tree[2*pos+1], tree[2*pos+2]);
  return tree;
}

int query(int *tree, int l, int h, int start, int end, int pos){
  if(end<l || start > h)
    return 1;
  if(start>=l && end <= h)
    return tree[pos];
  int mid = (start+end)/2;
  return lcm(query(tree, l,h, start, mid, 2*pos+1), query(tree, l, h, mid+1, end, 2*pos+2));
}


int main(){
  int n, q, l, h, *arr, *tree, size;
  cin>>n>>q;
  arr = new int[n];
  size = 2*pow(2, ceil(log2(n)))-1;
  tree = new int[size];
  for(int i = 0; i < n; i++)
    cin>>arr[i];
  tree = buildTree(arr, tree, 0, n-1, 0);
  for(int i = 0; i < q; i++){
    cin>>l>>h;
    cout<<query(tree,l, h, 0, n-1, 0)<<endl;
  }
}