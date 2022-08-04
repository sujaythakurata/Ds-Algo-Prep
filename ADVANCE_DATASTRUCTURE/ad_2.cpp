/*
  *Trie insert, search, delete
  *T.c -> O(26*n*m) m = number of words n = number of letters in each word
  *T.c -> search, insert, delete -> O(n)
  *S.c -> O(26*n*m)

*/

#include<bits/stdc++.h>
using namespace std;

#define MAX_CHAR 26

struct Trie{
  bool isWord;
  Trie*children[MAX_CHAR] = {NULL};
};

Trie*insert(Trie*root, string word){
  int n = word.size();
  Trie*cur = root;
  for(int i = 0; i<n; i++){
    if(cur->children[word[i]-'a'] == NULL)
      cur->children[word[i]-'a'] = new Trie();
    cur = cur->children[word[i]-'a'];
  }
  cur->isWord = true;
  return root;
}

bool search(Trie*root, string word){
  int n = word.size();
  for(int i = 0; i<n; i++){
    if(root->children[word[i]-'a'] != NULL)
      root = root->children[word[i]-'a'];
    else
      return false;
  }
  return root->isWord;
}
bool childLength(Trie*root){
  for(int i = 0; i<MAX_CHAR; i++)
    if(root->children[i] != NULL) return false;
  return true;
}

bool removeWord(Trie*&root, string word, int index){
  if(index == word.size()){
    if(!root->isWord)
      return false;
    root->isWord = false;
    return childLength(root);
  }

  Trie*cur = root->children[word[index]-'a'];
  if(cur == NULL)
    return false;
  bool del = removeWord(cur, word, index+1);
  if(del){
    root->children[word[index]-'a'] = NULL;
    return childLength(root);
  }
  return false;

}

int main(){
  int n, q;
  cin>>n>>q;
  string words[n];
  for(int i = 0; i<n; i++)
    cin>>words[i];
  Trie*root = new Trie();
  for(int i = 0; i<n; i++)
    root= insert(root, words[i]);
  int s;
  string word;
  for(int i = 0; i<q; i++){
    cin>>s;
    cin>>word;
    if(s == 0){
      if(search(root, word))cout<<"Word found\n";
      else cout<<"Word not found\n";
    }else if(s == 1){
      root = insert(root, word);
    }else{
      if(search(root, word)) cout<<"Deleted"<<endl;
      else cout<<"Not Found\n";
      removeWord(root, word, 0);
    }
  }
}