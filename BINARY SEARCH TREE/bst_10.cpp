/*
  *Left Leaning Red Black Tree
  *T.c -> O(logn)
  *S.c -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int val, color = 1;
    node*left = NULL, *right = NULL;
    node(int val){
      this->val = val;
    }
};

node*right_rotate(node*x, node*y){
  node*y_right = y->right;
  y->right = x;
  x->left = y_right;
  return y;
}
node*left_rotate(node*x, node*y){
  node*y_left = y->left;
  y->left = x;
  x->right = y_left;
  return y;
}

node*insert(node*root, int val){
  if(root == NULL)
    return new node(val);
  else if (root->val > val)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);

  if(root->right != NULL && root->right->color == 1 && (root->left == NULL|| root->left->color == 0)){
    root = left_rotate(root, root->right);
    swap(root->color, root->left->color);
  }
  else if(root->left != NULL && root->left->left != NULL && root->left->color == 1 && root->left->left->color ==1){
    root = right_rotate(root, root->left);
    swap(root->color, root->right->color);
  }
  else if(root->left != NULL and root->right != NULL && root->left->color == 1 && root->right->color == 1){
    root->left->color = 0;
    root->right->color = 0;
    root->color = !root->color;
  }
  return root;
}

void print_tree(node*root){
  if(root == NULL)
    return;
  print_tree(root->left);
  cout<<root->val<<"("<<root->color<<") ";
  print_tree(root->right);
}
void print_line(queue<node*>que, int n, int level){
  node*ele;
  int count = n-level;
  for(int i = 0;i<n-level;i++)
    cout<<" ";
  while(!que.empty()){
    ele = que.front();
    que.pop();
    if(ele->left)
      cout<<"/";
    cout<<"  ";
    if(ele->right)
      cout<<"\\";
    count++;
    if(count == n)
      cout<<"  ";
    
  }
}

void print_value(queue<node*>que, int n, int level){
  node*ele;
  int count = n-level;
  for(int i = 0;i<n-level;i++)
    cout<<" ";
  while(!que.empty()){
    ele = que.front();
    que.pop();
    cout<<ele->val<<"("<<ele->color<<") ";
    count++;
    if(count == n)
      cout<<"  ";
  }
}

void print_graphic(node*root, int n){
  if(root == NULL)
    return ;
  queue<node*>que;
  queue<node*>temp;
  node*ele;
  int count = 1, size, level = 0;
  que.push(root);
  while(!que.empty()){
    size = count;
    count = 0;
    temp = que;
    for(int i = 0; i < size ; i++)
    {
      ele = que.front();
      que.pop();
      if(ele->left){
        count++;
        que.push(ele->left);
      }
      if(ele->right){
        que.push(ele->right);
        count++;
      }
    }
    
    cout<<endl;
    n -= 1;
    print_value(temp, n, level);
    cout<<endl;
    level++;
    print_line(temp, n, level);
    
    
  }
}


int main(){
  int n, v;
  node*root = NULL;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>v;
    root = insert(root, v);
    root->color = 0;
  }
  print_tree(root);
  print_graphic(root, n);

  return 0;
}