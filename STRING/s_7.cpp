/*
  *Number of subsequences in a string divisible by n
  *T.c -> O(n*L) L = length of the string
  *S.c -> O(n*L)
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
  string str;
  int n;
  cin>>str;
  cin>>n;
  int dp[str.size()][n] = {{0}};
  memset(dp, 0, sizeof(dp));
  dp[0][(str[0]-'0')%n] = 1;
  for(int i = 1; i<str.size(); i++){
    dp[i][(str[i]-'0')%n]++;
    for(int j = 0; j<n; j++){
      dp[i][j] += dp[i-1][j];
      dp[i][(j*10+(str[i]-'0'))%n] += dp[i-1][j];
    }
  }
  cout<<dp[str.size()-1][0];

}