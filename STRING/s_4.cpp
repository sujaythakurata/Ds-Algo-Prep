/*
  *Find the smallest window in a string containing all characters of another string
  *T.c -> O(n)
  *S.c -> O(1) letters size = 256 so it's can be consider as constant size
*/

#include<bits/stdc++.h>
using namespace std;

string getSmallestWindow(string str, string t){
  int count = 0, i = 0, j = 0, ans = INT_MAX, start;
  int m[26] = {0};
  for(int i = 0; i < t.size(); i++){
    if(m[t[i]-'a'] == 0)
      count++;
    m[t[i]-'a']++;
  }

  while(i < str.size()){
    m[str[i]-'a']--;
    if(m[str[i]-'a'] == 0)
      count--;
    while(count == 0){
      if(ans > i-j+1){
        start = j;
        ans = i-j+1;
      }
      m[str[j]-'a']++;
      if(m[str[j]-'a']>0)
        count++;
      j++;
    }
    i++;
  }

  if(ans == INT_MAX)
    return "-1";
  return str.substr(start, ans);
}

int main(){
  string str, t;
  cin>>str>>t;
  cout<<getSmallestWindow(str, t);
}