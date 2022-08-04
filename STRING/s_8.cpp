/*
  *Find number of times a string occurs as a subsequence in given string
  *T.c -> O(MN) M = length of string a N = lenght of string b
  *S.c -> O(MN)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  string a, b;
  cin>>a>>b;
  int m = a.size(), n = b.size();
  int dp[m+1][n+1];
  memset(dp, 0, sizeof(dp));
  for(int i = 0; i<m+1; i++)
    dp[i][0] = 1;

  for(int i = 1; i<m+1; i++){
    for(int j = 1; j<n+1; j++){
      if(a[i-1] == b[j-1])
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
      else
        dp[i][j] = dp[i-1][j];
    }
  }

  cout<<dp[m][n];
}