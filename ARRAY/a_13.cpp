/*
  *Minimize the maximum difference between the heights
  *T.c -> O(n+logn)
  *S.c -> O(1)
*/

#include<bits/stdc++.h>

using namespace std;


int solve(int*arr, int n, int k){
  sort(arr, arr+n);
  int ans =  arr[n-1]-k - arr[0]+k, l = arr[n-1]-k, s = arr[0]+k, mi, mx;
  for(int i = 0; i<n-1; i++){
    mi = min(s, arr[i+1]-k);
    mx = max(l, arr[i]+k);
    if(mi<0) continue;
    ans = min(ans, mx-mi);
  }
  return ans;
}

int main(){
  int n, k, *arr;
  cin>>n>>k;
  arr = new int[n];
  for(int i = 0; i < n; i++)
    cin>>arr[i];

  cout<<solve(arr, n, k);

}