/*
  *Compressed Tries
  *T.c -> O(w) n = number of words w = number of character in words
  *S.c -> O(n) 

*/

#include<bits/stdc++.h>

using namespace std;

#define MAX_CHAR 26

struct Trie{
  bool isWord;
  string labels[MAX_CHAR];
  Trie *children[MAX_CHAR] = {NULL};
  Trie(bool word){
    this->isWord = word;
  }
};

Trie*insert(Trie*root, string word){
  Trie*temp = root;
  int i = 0, index, j, wordLen = word.size(), labelLen, newIndex;
  string label, labelRemain, newLabel;
  Trie*prevNode, *newChild;
  while(i < wordLen && temp->children[word[i] - 'a'] != NULL){
    index = word[i] - 'a';
    label = temp->labels[index];
    j = 0;
    labelLen = label.size();
    while(i < wordLen && j < labelLen && label[j] == word[i]){
      i++;
      j++;
    }

    if(j == labelLen)
      temp = temp->children[index];
    else{
      if(i == wordLen){
          labelRemain = label.substr(j);
          newLabel = label.substr(0, j);
          prevNode = temp->children[index];
          newIndex = labelRemain[0] - 'a';
          newChild = new Trie(true);
          temp->labels[index] = newLabel;
          temp->children[index] = newChild;
          newChild->labels[newIndex] = labelRemain;
          newChild->children[newIndex] = prevNode;
      }else{ 

          labelRemain = label.substr(j);
          newLabel = label.substr(0, j);
          string wordRemain = word.substr(i);
          prevNode = temp->children[index];
          newIndex = labelRemain[0] - 'a';
          int wordIndex = wordRemain[0] - 'a';
          newChild = new Trie(false);
          temp->children[index] = newChild;
          temp->labels[index] = newLabel;
          newChild->labels[newIndex] = labelRemain;
          newChild->labels[wordIndex] = wordRemain;
          newChild->children[newIndex] = prevNode;
          newChild->children[wordIndex] = new Trie(true);
      }
      return root;
    }
  }

  if(i < wordLen){
    index = word[i] - 'a';
    temp->labels[index] = word.substr(i);
    temp->children[index] = new Trie(true);
  }else temp->isWord = true;

  return root;
}


bool search(Trie*root, string word, bool prefix=false){
  int index;
  int i = 0, j = 0;
  while(i<word.size() && root->children[word[i]-'a'] != NULL){
    index = word[i] - 'a';
    string label = root->labels[index];
    j = 0;
    while(i < word.size() && j < label.size() && word[i] == label[j]){
      if(word[i] != label[j] && prefix)
        return false;
      i++;
      j++;
    }
    if(j == label.size() && i <= word.size())
      root = root->children[index];
    else {
      if(!prefix) return false;
      else true;
    }
  }
  if(prefix)
    return i == word.size();
  return i == word.size() && root->isWord;
}


void print(Trie*root, string str){
  if(root->isWord){
    cout<<str<<endl;
  }
  for(int i = 0; i < MAX_CHAR; i++){
    if(root->children[i] != NULL)
      print(root->children[i], str + root->labels[i]);
  }
}

int main(){
  int n;
  cin>>n;
  string *str = new string[n];
  for(int i = 0; i<n; i++)
    cin>>str[i];
  Trie*root = new Trie(false);
  for(int i = 0; i< n; i++)
    root = insert(root, str[i]);
  print(root, "");
  int q, s;
  string word;
  cin>>q;
  for(int i = 0; i<q; i++){
    cin>>s>>word;
    if(s == 0){
      if(search(root, word)) cout<< "Word Found\n";
      else cout<<"Word Not Found\n";
    }
    else{
      if(search(root, word, true)) cout<<"Prefix Found\n";
      else cout<<"Prefix Not Found\n";
    }
  }
}