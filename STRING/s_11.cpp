/*
  *Finite Automata algorithm for Pattern Searching
  *T.c -> O(m^2) m = Pattern length n = text length
  *S.c -> O(m)
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;

int getNewState(string p, int currState, int len, int c){
  if(currState < len && p[currState] == c)
    return ++currState;
  int ns, i;
  for(ns = currState; ns>0; ns--){
    if(p[ns-1] == c){

        for(i = 0; i<ns-1; i++)
          if(p[i] != p[currState-ns+1+i])
            break;
        if(i == ns-1)
          return ns;

    }
  }
  return 0;

}

int** createStateTable(string p){
  int**arr, n = p.size(), state = n+1;
  arr = new int*[state];
  for(int i = 0; i<state; i++)
    arr[i] = new int[MAX_CHAR];
  for(int i = 0; i<state; i++){
    for(int j = 0; j<MAX_CHAR; j++)
      arr[i][j] = getNewState(p, i, n, j);
  }

  return arr;
}

int main(){
  string p, txt;
  int **arr, newState = 0;
  cin>>txt>>p;
  arr = createStateTable(p);
  for(int i = 0; i<txt.size(); i++){
    newState = arr[newState][txt[i]];
    if(newState == p.size())
      cout<<"Found Index: "<<i-p.size()+1<<endl;
  }
}