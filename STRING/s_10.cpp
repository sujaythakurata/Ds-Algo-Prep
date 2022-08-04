/*
  *Print all words matching a pattern in CamelCase Notation Dictionary
  *T.c -> O(n*w*p) n = length of the array w = length of the word p = length of the pattern
  *S.c -> O(w*p)
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
struct Trie{
  int isWord = -1;
  Trie*children[MAX_CHAR] = {NULL};
  vector<string>words;
};

Trie* insert(Trie*root, string s){
  Trie*cur = root;
  for(int i = 0; i<s.size(); i++){
    if(s[i] >='a' && s[i]<='z')
      continue;
    if(cur->children[s[i]-'A'] == NULL)
      cur->children[s[i]-'A'] = new Trie();
    cur = cur->children[s[i]-'A'];
  }
  cur->isWord = 1;
  cur->words.push_back(s);
  return root;
}
void printWords(Trie*root){

  if(root->isWord == 1){
    for(auto i = root->words.begin(); i!= root->words.end(); i++)
      cout<<*i<<endl;
  }
  for(int i = 0; i < MAX_CHAR; i++){
    if(root->children[i] != NULL)
      printWords(root->children[i]);
  }

}


bool search(Trie*root, string p){
  for(int i = 0; i<p.size(); i++){
    if(root->children[p[i]-'A'] != NULL)
      root = root->children[p[i]-'A'];
    else
      return false;
  }
  printWords(root);
  return true;
}


int main(){
  int n;
  cin>>n;
  string str[n], s, pattern;
  for(int i = 0; i<n; i++)
    cin>>str[i];
  cin>>pattern;
  Trie*root = new Trie();
  for(int i = 0; i<n; i++)
    root = insert(root, str[i]);
  if(!search(root, pattern))cout<<-1;
}