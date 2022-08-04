/*
  *MO’s Algorithm (Query Square Root Decomposition) 
  *T.c -> O((m+n)*sqrt(n))
  *S.c -> O(m)
*/

#include<bits/stdc++.h>

using namespace std;

int block;
struct query{
  int l,r,index;
};

bool compare(query q1, query q2){
  if(q1.l/block != q2.l/block)
    return q1.l/block<q2.l/block;
  return q1.r>q2.r;
}

int*get_sum(int *arr, query quries[], int n, int m){
  int l, r,*ans = new int[m];
  for(int i = 0; i < m; i++){
    l = quries[i].l;
    r = quries[i].r;
    ans[quries[i].index] = arr[r]-(l-1<0?0:arr[l-1]);
  }
  return ans;
}



int main(){
  int n, m, *arr, *prefix_sum, l, r;
  cin>>n>>m;
  arr = new int[n];
  prefix_sum = new int[n];
  query quries[m];
  block = sqrtl(n);
  for(int i = 0; i < n; i++)
    cin>>arr[i];
  for(int i = 0;i < m; i++){
    cin>>quries[i].l>>quries[i].r;
    quries[i].index = i;
  }
  sort(quries, quries+m, compare);
  prefix_sum[0] = arr[0];
  for(int i = 1; i<n;i++)
    prefix_sum[i] = prefix_sum[i-1] + arr[i];
  
  int *ans = get_sum(prefix_sum, quries, n,m);
  for(int i = 0; i<m;i++)
    cout<<ans[i]<<" ";

  return 0;
}