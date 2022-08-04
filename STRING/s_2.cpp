/*
  *Minimum sum of squares of character counts in a given string after removing k characters
  *T.c -> O(n)
  *S.c -> O(26)
*/

#include<bits/stdc++.h>
using namespace std;

int getResult(string s, int k){
  int count[26] = {0};
  for(auto i:s)
    count[i-'a']++;
  sort(count, count+26, greater<int>());
  int ind = 0, rem;
  while(k>0){
    if(count[ind] == 0)
      ind = 0;
    if(count[ind] != 0)
      count[ind]--;
    if(ind-1 > -1 && count[ind] == count[ind-1] && count[ind] != 0)
      ind--;
    else if(count[ind]<count[ind+1])
      ind++;
    k--;

  }
  int result = 0;
  for(int i = 0; i < 26; i++)
    result += pow(count[i], 2);
  return result;
}

int main(){
  string s;
  int k;
  cin>>s>>k;
  cout<<getResult(s, k);

}