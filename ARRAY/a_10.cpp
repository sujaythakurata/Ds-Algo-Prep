/*
  *Largest Sum Contiguous Subarray using kadane's algo
  *T.c -> O(n)
  *S.c -> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, *arr;
  cin>>n;
  arr = new int[n];
  for(int i = 0; i<n; i++)
    cin>>arr[i];
  int curSum = 0, maxSum = INT_MIN;
  for(int i = 0; i <n;i++){
    curSum += arr[i];
    if(curSum>maxSum)
      maxSum = curSum;
    if(curSum<0)
      curSum = 0;
  }
  cout<<maxSum;

}
