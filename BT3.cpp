//BT
//Various operations are performed
    //  1.Level Order Traversal
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

void levelOrder(node*root){
    if(root==NULL){
        return;
    }
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty()){
        node*current=Q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
    }
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
	levelOrder(root);
    return 0;
}