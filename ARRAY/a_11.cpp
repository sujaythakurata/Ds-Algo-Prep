/*
  *Maximum profit by buying and selling a share at most twice
  *T.c -> O(days*k) here k = 2;
  *S.c -> O(days*k)

*/

#include<bits/stdc++.h>

using namespace std;

int calculateProfit(int*arr, int n, int k){
  int t[k+1][n] = {0}, maxDiff = INT_MIN;

  for(int i = 1; i <= k; i++){
    maxDiff = t[i-1][0]-arr[0];
    for(int j = 1; j < n ;j++){
      t[i][j] = max(t[i][j-1], maxDiff + arr[j]);
      maxDiff = max(maxDiff, t[i-1][j]-arr[j]);
    }
    cout<<endl;
  }

  int i = k;
  int j = n-1;
  stack<int>s;
  while(true){
    if(i == 0 || j==0)
      break;
    if(t[i][j] == t[i][j-1])
      j--;
    else{
      s.push(j);
      for(int k = j;k>=0; k--){
        if(t[i-1][k]-arr[k] == t[i][j]-arr[j]){
          i--;
          j = k;
          s.push(j);
          break;
        }
      }
    }
  }

  while(!s.empty()){
    cout<<"Buy at : "<<arr[s.top()]<<endl;
    s.pop();
    cout<<"Sell at: "<<arr[s.top()]<<endl;
    s.pop();
  }



  return t[k][n-1];

}


int main(){
  int n,k;
  cin>>n>>k;
  int *arr = new int[n];
  for(int i = 0; i < n; i++)
    cin>>arr[i];
  cout<<calculateProfit(arr, n, k);

}