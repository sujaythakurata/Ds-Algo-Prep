/*
	*Clone a Binary Tree with Random Pointers
	*T.c -> O(n)
	*S.c -> O(1)

*/

#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	struct node *left=NULL, *right=NULL, *random=NULL;

};

void printTree(node*root){
	if(root == NULL)
		return;
	printTree(root->left);
	printTree(root->right);
	int val = -1;
	if(root->random != NULL)
		val = root->random->val;
	cout<<"["<<root->val<<" , "<<val<<"]"<<" ";
}

node* cloneTree(node * root, unordered_map<node*, node*>&hashmap){
	
	if(root == NULL)
		return NULL;
	struct node*c = new node;
	c->val = root->val;
	hashmap[root] = c;
	c->left = cloneTree(root->left, hashmap);
	c->right = cloneTree(root->right, hashmap);
	
	return c;

}

void cloneRandom(node*root, node*clone, unordered_map<node*, node*>hashmap){
	
	if(root == NULL)
		return;
	clone->random = hashmap[root->random];
	cloneRandom(root->left, clone->left, hashmap);
	cloneRandom(root->right, clone->right, hashmap);

}

int main(){
	unordered_map<node*, node*>hashmap;
	struct node *clone;
	struct node*root = new node;
	root->val = 1;
	root->left = new node;
	root->right = new node;
	root->left->val = 2;
	root->right->val = 3;
	root->left->left = new node;
	root->left->right = new node;
	root->left->left->val= 4;
	root->left->right->val = 5;
	root->random = root->left->right;
	root->left->left->random = root;
	root->left->right->random = root->right;
	printTree(root);
	cout<<endl;
	
	
	clone = cloneTree(root, hashmap);
	cloneRandom(root, clone, hashmap);
	
	printTree(clone);

	return 0;
}
