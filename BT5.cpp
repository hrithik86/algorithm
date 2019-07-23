//BT
//check if a binary tree is a binary search tree or not
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node*left;
    node*right;
};

node* createNewNode(int x){
    node*temp=new node();
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node* insert(node*root,int x){
    if(root==NULL){
        root=createNewNode(x);
    }
    else if(x>root->data){
        root->right=insert(root->right,x);
    }
    else 
        root->left=insert(root->left,x);
    return root;
}

bool isBinarySearchTree(node*root,int min_value=INT_MIN,int max_value=INT_MAX){
    if(root==NULL)  return true;
    if( root->data>min_value && root->data<max_value && 
        isBinarySearchTree(root->left,min_value,root->data) &&
        isBinarySearchTree(root->right,root->data,max_value))
        return true;
    else return false;
}

int main()
{
    node*root=NULL;
    root=insert(root,20);
	root=insert(root,15);
	root=insert(root,25);
	root=insert(root,10);
	root=insert(root,17);
	root=insert(root,22);
	root=insert(root,30);
	root=insert(root,8);
	root=insert(root,11);
	root=insert(root,24);
	root=insert(root,23);
    if(isBinarySearchTree(root)){
        cout<<"Its a Binary Search tree";
    }
    else cout<<"its not a binary search tree";
    return 0;
}