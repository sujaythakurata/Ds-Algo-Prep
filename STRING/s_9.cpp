/*
  *Sorting array of strings (or words) using Trie
  *T.c -> O(n*l) n = number of words l = words length
  *S.c -> O(n*26)
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;
struct Node{
  int isWord = -1;
  Node *children[MAX_CHAR] = {NULL};
};

Node *root = new Node();

void insert(string str, int strIndex){
  Node *cur = root;
  int index;
  for(int i = 0; i < str.size(); i++){
    index = str[i] - 'a';
    if(cur->children[index] == NULL)
      cur->children[index] = new Node();
    cur = cur->children[index];
  }
  cur->isWord = strIndex;
}

void makeTree(string str[], int n){
  for(int i = 0; i<n; i++)
    insert(str[i], i);
}

void preorder(Node*trie, string str[]){
  if(trie == NULL)
    return;
  for(int i = 0; i < MAX_CHAR; i++){
    if(trie->children[i] != NULL && trie->children[i]->isWord != -1)
      cout<<str[trie->children[i]->isWord]<<" ";
    preorder(trie->children[i], str);
  }
}


int main(){
  int n;
  cin>>n;
  string str[n];
  for(int i = 0; i<n; i++)
    cin>>str[i];
  makeTree(str, n);
  preorder(root, str);
}