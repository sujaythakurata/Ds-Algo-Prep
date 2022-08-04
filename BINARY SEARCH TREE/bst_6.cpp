/*
  *AVL Tree | Set 1 (Insertion)
  *T.c -> O(h) h = height of the tree = O(logn)
  *S.c -> O(n) n = number of nodes
*/

#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int val, height=1;
    node*left = NULL, *right = NULL;
    node(int val){
      this->val = val;
    }
    int get_height(){
      int lheight = this->left == NULL?0:this->left->height;
      int rheight = this->right == NULL?0:this->right->height;
      return max(lheight, rheight);
    }
    int get_balance(){
      int lheight = this->left == NULL?0:this->left->height;
      int rheight = this->right == NULL?0:this->right->height;
      return lheight - rheight;
    }
};

node* leftrotate(node*root){
  node*y = root->right;
  node* y_left = y->left;
  y->left = root;
  root->right = y_left;
  y->height = 1 + y->get_height();
  root->height = 1 + root->get_height();
  return y;
}

node* rightrotate(node*root){
  node*y = root->left;
  node*y_right = y->right;
  y->right = root;
  root->left = y_right;
  y->height  = 1 + y->get_height();
  root->height = 1 + root->get_height();
  return y;
}

node* insert(node*root, int key){
  if(root == NULL)
    return new node(key);
  if(key > root->val)
    root->right = insert(root->right, key);
  else
    root->left = insert(root->left, key);
  
  root->height = 1 + root->get_height();
  int balance = root->get_balance();

  if(balance > 1 && key <= root->left->val)
    return rightrotate(root);
  if(balance < -1 && key > root->right->val)
    return leftrotate(root);
  if(balance > 1 && key > root->left->val){
    root->left = leftrotate(root->left);
    return rightrotate(root);
  }
  if(balance < -1 && key <= root->right->val){
    root->right = rightrotate(root->right);
    return leftrotate(root);
  }

  return root;
  

}


void print_tree(node*root){
  if(root == NULL)
    return;
  print_tree(root->left);
  cout<<root->val<<" ";
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
    cout<<ele->val<<" ";
    count++;
    if(count == n)
      cout<<"  ";
  }
}

void print_graphic(node*root, int n){
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
  }
  cout<<endl;
  print_tree(root);
  cout<<endl;
  print_graphic(root, n);


  return 0;
}