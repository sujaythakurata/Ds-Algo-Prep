/*
  *Expression binary Tree using postfix expression
  *T.c -> O(n) n = length of the expression
  *S.c -> O(n)
*/
#include<bits/stdc++.h>
using namespace std;
class node{
  public:
    string key;
    node*left = NULL, *right = NULL;
    node(char key){
      this->key = key;
    }
};

void print_expression(node*root){
  if(root == NULL)
    return;
  print_expression(root->left);
  cout<<root->key<<" ";
  print_expression(root->right);
}

int main(){
  string exp;
  cin>>exp;
  stack<node*>st;
  node *ele, *left, *right;
  int n = exp.length();
  for(int i = 0; i < n; i++){
    if(exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '^'){
      ele = new node(exp[i]);
      right = st.top();
      st.pop();
      left = st.top();
      st.pop();
      ele->left = left;
      ele->right = right;
      st.push(ele);
    }else{
      ele = new node(exp[i]);
      st.push(ele);
    }
  }

  print_expression(st.top());

  return 0;
}