/*
  *Detect loop in a linked list
  *T.c -> O(n)
  *S.c -> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
  int val;
  node*next=NULL;
};

node*insert(node*root, int val){
  node*new_node = new node();
  new_node->val = val;
  node*temp = root;
  if(temp == NULL)
    return new_node;
  while(temp->next != NULL)
    temp = temp->next;
  temp->next = new_node;
  return root;
}

node*make_loop(node*root, int v1, int v2){
  node*temp1, *temp2, *temp = root;
  while(temp!= NULL){
    if(temp->val == v1)
      temp1 = temp;
    if(temp->val == v2)
      temp2 = temp;
    temp = temp->next;
  }
  temp2->next = temp1;
  return root;
}


bool detect_loop(node*root){
  node*temp1 = root, *temp2 = NULL;
  if(root->next != NULL)
    temp2 = root->next->next;
  while(temp1 != temp2){
    temp1 = temp1->next;
    if(temp2 != NULL && temp2->next != NULL)
      temp2 = temp2->next->next;
    else
      break;
  }
  if(temp1 == temp2)
    return true;
  return false;
}


void print_list(node*root){
  if(root == NULL)
    return;
  cout<<root->val<<" ";
  print_list(root->next);
}

int main(){
  int n, v, v1,v2;
  bool option;
  node*root = NULL;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>v;
    root = insert(root, v);
  }
  print_list(root);
  cin>>option;
  if(option){
    cin>>v1>>v2;
    root = make_loop(root, v1, v2);
  }
  if(detect_loop(root))
    cout<<"LOOP";
  else
    cout<<"Not LOOP";

  return 0;
}
