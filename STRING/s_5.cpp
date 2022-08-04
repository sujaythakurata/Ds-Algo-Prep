/*
  *Count number of substrings with exactly k distinct characters
  *T.c -> O(n)
  *S.c -> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int getResult(string str, int k){
  int count = 0, i = 0, j = 0;
  map<char,int>s;
  while(i<str.size()){
    s[str[i]]++;
    while(s.size()>k){
      s[str[j]]--;
      if(s[str[j]] == 0)
        s.erase(s.find(str[j]));
      j++;
    }
    count += (i-j+1);
    i++;
  }
  return count;
}

int main(){
  string str;
  int k;
  cin>>str>>k;
  cout<<getResult(str, k) - getResult(str, k-1);
}