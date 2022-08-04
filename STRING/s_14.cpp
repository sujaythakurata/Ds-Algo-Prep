/*
  *Manacher’s Algorithm – Linear Time Longest Palindromic Substring – Part 4
  *T.c -> O(n) n = length of the string
  *S.c -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

string printPalindrome(string str){
  int n = str.size(), m,r = 0, c = 0;
  char newString[2*n+1];
  memset(newString, '#', 2*n+1);
  int p[2*n+1], lgLen = -1, lgC;
  fill_n(p, 2*n+1, 0);
  for(int i = 0; i<n; i++)
    newString[2*i+1] = str[i];
  for(int i = 0; i<2*n+1; i++){
    m = 2*c-i;
    if(i<r)
      p[i] = min(r-i, p[m]);
    while(i-(1+p[i]) >-1 && i+(1+p[i])<2*n+1 && newString[i+(1+p[i])] == newString[i-(1+p[i])])
      p[i]++;
    if(i+p[i] > r){
      c = i;
      r = i+p[i];
    }
    if(lgLen<p[i]){
      lgLen = p[i];
      lgC = i;
    }
  }

  string ans = string(newString);
  ans = ans.substr(lgC-lgLen,2*lgLen);
  string s = "#";
  size_t pos = ans.find(s);
  while(pos != string::npos){
    ans.replace(pos, s.size(), "");
    pos = ans.find(s, pos+s.size());
  }
  return ans;

}

int main(){
  string str;
  cin>>str;
  cout<<printPalindrome(str);
}