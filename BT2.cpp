//BST
//Various operations are performed
    //  1.height of a binary tree
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
int findHeight(node*root){
    if(root==NULL){
        return -1;
    }
    int leftSide=findHeight(root->left);
    int rightSide=findHeight(root->right);
    return max(leftSide,rightSide)+1;
}

int main()
{
    node*root=NULL;
    root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	cout<<"Height:"<<findHeight(root);
    return 0;
}