/*
  *Find the subarray with least average
  *T.c -> O(n)
  *S.c -> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

  int n, k, curSum = 0, minSum = INT_MAX, index = 0, start, end;
  cin>>n>>k;
  int *arr = new int[n];
  for(int i = 0; i<n; i++)
    cin>>arr[i];
  for(int i = 0; i<k; i++)
    curSum+= arr[i];
  for(int i = k; i<n; i++){
    curSum = curSum-arr[index]+arr[i];
    if(minSum>curSum){
      start = index+1;
      end = i;
      minSum = curSum;
    }
    index++;
  }
  for(int i = start; i<=end; i++)
    cout<<arr[i]<<" ";

}