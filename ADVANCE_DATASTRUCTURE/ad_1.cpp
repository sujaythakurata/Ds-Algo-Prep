/*
  *Lazy Propagation in Segment Tree (get sum and also update array)
  *T.c -> O(n)
  *S.c -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

void segmentTree(int*arr, int*&tree, int l, int r, int pos){
  if(l == r){
    tree[pos] = arr[l];
    return;
  }
  int mid = (l+r)/2;
  segmentTree(arr, tree, l, mid, 2*pos+1);
  segmentTree(arr, tree, mid+1, r, 2*pos+2);
  tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

void updateTree(int*&tree,int*&lazy, int l, int r, int sr, int er, int pos, int delta){
  if(l>r)
    return;
  if(lazy[pos] != 0){
    tree[pos] += (r-l+1)*lazy[pos];
    if(l != r){
      lazy[2*pos+1] += lazy[pos];
      lazy[2*pos+2] += lazy[pos];
    }
    lazy[pos] = 0;
  }

  if(sr>r || er<l)
    return;
  if(sr <= l && er >= r){
    tree[pos] += (r-l+1)*delta;
    if(l != r){
      lazy[2*pos+1] += delta;
      lazy[2*pos+2] += delta;
    }
    return;
  }
  int mid = (l+r)/2;
  updateTree(tree, lazy, l, mid, sr, er,2*pos+1, delta);
  updateTree(tree, lazy, mid+1, r, sr, er, 2*pos+2, delta);
  tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}


int search(int*&tree, int*&lazy, int l, int r, int sr, int er, int pos){
  if(l>r)
    return 0;
  if(lazy[pos] != 0){
    tree[pos] += (r-l+1)*lazy[pos];
    if(l != r){
      lazy[2*pos+1] += lazy[pos];
      lazy[2*pos+2] += lazy[pos]; 
    }
    lazy[pos] = 0;
  }

  if(r<sr || er<l)
    return 0;

  if(l>=sr && r<=er)
    return tree[pos];
  int mid = (l+r)/2;
  return search(tree, lazy, l, mid, sr, er, 2*pos+1)
    + search(tree, lazy, mid+1, r, sr, er, 2*pos+2);

}


int main(){
  int n, s, e, delta, t, q;
  cin>>t;
  cin>>n;
  int*arr = new int[n];
  int size = 2*pow(2, ceil(log2(n)))-1;
  int*tree = new int[size];
  int*lazy = new int[size];
  fill_n(lazy, size, 0);
  fill_n(tree, size, 0);
  for(int i = 0; i<n;i++)
    cin>>arr[i];
  segmentTree(arr, tree, 0, n-1, 0);
  for(int _ = 0; _ < t; _++){
    cin>>q;
    if(q == 0){
      cin>>s>>e;
      cout<<search(tree, lazy, 0,n-1, s,e,0)<<endl;
    }else{
      cin>>s>>e>>delta;
      updateTree(tree, lazy, 0, n-1, s, e, 0, delta);
    }
  }

}