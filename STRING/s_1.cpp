/*
  *Rearrange characters in a string such that no two adjacent are same
  *T.c -> O(n)
  *S.c -> O(n+26)
*/

#include<bits/stdc++.h>
using namespace std;

int getMax(int count[]){
  int maxValue = 0, ans;
  for(int i = 0; i < 26; i++){
    if(count[i]>maxValue){
      maxValue = count[i];
      ans = i;
    }
  }
  return ans;
}

string rearrange(string s){
  int n = s.size();
  int count[26] = {0};
  for(auto i = s.begin(); i != s.end(); i++)
    count[*i-'a']++;
  int maxIndex = getMax(count);
  int maxValue = count[maxIndex];
  if(maxValue>(n+1)/2)
    return "Impossible";
  string ans(n,' ');
  int ind = 0;
  while(maxValue>0){
    ans[ind] = 'a'+maxIndex;
    ind += 2;
    maxValue--;
  }
  count[maxIndex] = 0;
  for(int i = 0; i < 26; i++){
    while(count[i]){
      ind = (ind>=n)?1:ind;
      ans[ind] = 'a'+i;
      ind += 2;
      count[i]--;
    }
  }

  return ans;
}

int main(){
  string s;
  cin>>s;
  cout<<rearrange(s);
}