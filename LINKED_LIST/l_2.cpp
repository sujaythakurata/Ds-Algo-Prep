/*
  *circular linked list
  *T.c -> O(n)
  *S.c -> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
  int val;
  node*next=this;
};

node*insert(node*root, int val){
  node*new_node = new node();
  new_node->val = val;
  node*temp = root;
  if(temp == NULL)
    return new_node;
  while(temp->next != root)
    temp = temp->next;
  temp->next = new_node;
  new_node->next = root;
  return root;
}

void split(node*root, node*&root1, node*&root2){
  node*temp1 = root, *temp2 = NULL;
  if(root->next != root)
    temp2 = root->next->next;
  while(temp2->next->next != root && temp2->next != root){
    temp1 = temp1->next;
    temp2 = temp2->next->next;
  }
  temp1 = temp1->next;
  root1 = root;
  root2 = temp1->next;
  temp1->next = root1;
  if(temp2->next == root)
    temp2->next = root2;
  else
    temp2 = temp2->next;
  temp2->next = root2;
}



void print_list(node*head, node*root){
  if(root->next == head){
    cout<<root->val<<endl;
    return;
  }
  cout<<root->val<<" ";
  print_list(head, root->next);
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
  print_list(root, root);
  node*r1,*r2;
  split(root, r1, r2);
  print_list(r1, r1);
  print_list(r2, r2);

  return 0;
}
