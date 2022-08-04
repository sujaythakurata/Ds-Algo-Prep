/*

  *Minimum number of jumps to reach end
  *T.c -> O(n)
  *S.c -> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n){
  int mr = arr[0], step = arr[0], j = 1;
  if(mr == 0)
    return -1;
  if(n == 1)
    return j;
  for(int i = 1; i < n-1; i++){
    mr = max(mr, arr[i]+i);
    step--;
    if(step == 0){
      j++;
      if(i>=mr)return -1;
      step = mr-i;
    }
  }
  return j;
  
}

int main(){
  int n, *arr;
  cin>>n;
  arr = new int[n];
  for(int i = 0; i < n; i++)
    cin>>arr[i];
  cout<<solve(arr, n);

}