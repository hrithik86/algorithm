//Delete a node from BST

#include <iostream>
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

//Function to find minimum in a tree. 
node* findMin(node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

node* Delete(node*root,int data){
    if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			node *temp = findMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

void inOrder(node*root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
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
	inOrder(root);
    root=Delete(root,10);
    cout<<"\nAfter deletion:";
    inOrder(root);
    return 0;
}
