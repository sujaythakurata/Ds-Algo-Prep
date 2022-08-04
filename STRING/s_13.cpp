/*
  *Z algorithm (Linear time pattern searching Algorithm)
  *T.c -> O(n+m) n = length of the text m = length of the pattern
  *S.c -> O(n+m)
*/

#include<bits/stdc++.h>
using namespace std;

int*zTable(string p, string text){
  int n = text.size(), m =  p.size();
  int*table = new int[n+m+1];
  string str = p+"$"+text;
  int r = 0, l = 0, k;
  table[0] = 0;
  for(int i = 1; i<n+m+1; i++){
    if(i>r){
      r = l = i;
      while(r<n+m+1 && str[r] == str[r-l])
        r++;
      table[i] = r-l;
      r--;
    }else{
      k = i - l;
      if(table[k] < r-i+1){
        table[i] = table[k];
      }else{
        l = i;
        while(r<n+m+1 && str[r] == str[r-l]) r++;
        table[i] = r-l;
        r--;
      }
    }
  }
  return table;
}

int main(){
  string text, p;
  cin>>text>>p;
  int*table = zTable(p, text);
  int n = text.size(), m = p.size();
  for(int i = 0; i<n+m+1; i++)
    if(table[i] == m)
      cout<<"Pattern found index: "<<i-m<<endl;
}