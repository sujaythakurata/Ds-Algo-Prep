/*
  *Check if a given string is sum-string
  *T.c -> O(n^3) n = length of the string
  *S.c -> O(n)

*/

#include<bits/stdc++.h>

using namespace std;

string stringSum(string s1, string s2){
  if(s1.size()<s2.size())
    swap(s1, s2);
  int n = s1.size(), m = s2.size(), carry = 0, s = 0, d;
  string ans = "";
  for(int i = 0; i<m; i++){
    s = (s1[n-1-i]-'0')+(s2[m-1-i]-'0')+carry;
    d = s%10;
    carry = s/10;
    ans = char(d+'0') + ans;
  }
  for(int i = m; i < n; i++){
    s = (s1[n-1-i]-'0')+carry;
    d = s%10;
    carry = s/10;
    ans = char(d+'0') + ans;
  }

  if(carry)
    ans = char(carry+'0') + ans;

  return ans;
}

bool isSumString(string str, int beg, int len1, int len2){
  string s1 = str.substr(beg, len1);
  string s2 = str.substr(beg+len1, len2);
  string s3 = stringSum(s1, s2);
  int s3Len = s3.size();
  //cout<<s1<<" "<<s2<<" "<<s3<<" "<<(s3 == str.substr(beg+len1+len2, s3Len))<<endl;
  if(s3Len > str.size()-beg-len1-len2)
    return false;
  if(s3 == str.substr(beg+len1+len2, s3Len)){
    if(beg+len1+len2+s3Len == str.size())
      return true;
    return isSumString(str, beg+len1, len2, s3Len);
  }
  return false;

}

bool check(string str){
  int n = str.size();
  for(int i = 1; i < n; i++){
    for(int j = 1; i+j < n; j++)
      if(isSumString(str, 0, i, j))
        return true;
  }
  return false;
}

int main(){
  string str;
  cin>>str;
  if(check(str))
    cout<<"Sum String";
  else
    cout<<"Not a Sum string";
  
}