/*
  *Sorted insert for circular linked list
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
  while(temp->next != root && temp->val<val)
    temp = temp->next;
  node*next = temp->next;
  temp->next = new_node;
  new_node->next = next;
  if(temp->val > new_node->val)
    swap(temp->val, new_node->val);
  return root;
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
  return 0;
}
