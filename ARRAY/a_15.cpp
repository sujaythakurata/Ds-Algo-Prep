/*
  *Sort a nearly sorted (or K sorted) array
  *T.c -> O(nlogk)
  *S.c -> O(n)
*/

#include<bits/stdc++.h>

using namespace std;


int main(){

  int n, k, *arr, *ans, index = 0;
  cin>>n>>k;
  arr = new int[n];
  ans= new int[n];
  for(int i = 0; i <n;i++)
    cin>>arr[i];
  priority_queue<int, vector<int>, greater<int>>pq;
  for(int i = 0; i<=k; i++)
    pq.push(arr[i]);
  for(int i = k+1; i<n; i++){
    ans[index++] = pq.top();
    pq.pop();
    pq.push(arr[i]);
  }
  while(!pq.empty()){
    ans[index++] = pq.top();
    pq.pop();
  }

  for(int i = 0; i <n; i++)
    cout<<ans[i]<<" ";

  return 0;
}