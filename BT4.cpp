//BT
//Various operations are performed
    //  1.Preorder traversal
    //  2.Inorder traversal
    //  3.Postorder traversal
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

void preOrder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node*root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node*root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
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
	cout<<"Preorder:";
	preOrder(root);
	cout<<"\nInorder:";
	inOrder(root);
	cout<<"\nPostorder:";
	postOrder(root);
    return 0;
}