//Binary Search Tree Implementation
//various operations are performed on the BST:
    /*  1.Creating a BST
        2.Searching for an element
        3.finding Min & Max
    */

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

bool Search(node* root,int x) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == x) {
		return true;
	}
	else if(x <= root->data) {
		return Search(root->left,x);
	}
	else {
		return Search(root->right,x);
	}
}

int findMin(node*root){
    if(root==NULL){             //empty tree
        return -1;
    }
    if(root->left==NULL){
        return root->data;
    }
    return findMin(root->left);
}

int findMax(node*root){
    if(root==NULL){             //empty tree
        return -1;
    }
    if(root->right==NULL){
        return root->data;
    }
    return findMax(root->right);
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
	int number=19;
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
	int min=findMin(root);
	cout<<"\nMin:"<<min;
	int max=findMax(root);
	cout<<"\nMax:"<<max;
    return 0;
}
