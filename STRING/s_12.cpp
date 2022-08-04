/*
  *Boyer Moore Algorithm for Pattern Searching
  *T.c -> O(mn) m = length of the pattern n = length of the text
  *S.c -> O(a) a = number of distinct character in pattern
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26
int*badMatchTable(string p){
  int*table = new int[MAX_CHAR];
  int n = p.size();
  fill_n(table, MAX_CHAR, n);
  for(int i = 0; i<n; i++)
    table[p[i]-'a'] = max(1, n-i-1);
  return table;
}

int main(){
  string txt, p;
  cin>>txt>>p;
  int*table = badMatchTable(p);
  int n = txt.size(), m = p.size();
  int i = 0, j;
  while(i < n-m){
    for(j = m-1; j>-1; j--){
      if(p[j] != txt[i+j]){
        i += table[txt[i+j]-'a'];
        break;
      }
    }
    if(j<0){
      cout<<"Pattern found: "<<i<<endl;
      i += 1;
    }

  }
}