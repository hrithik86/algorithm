//Inorder successor in a BST
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

node* search(node*root,int data){
    if(root==NULL)  return NULL;
    else if(root->data>data){
        return search(root->left,data);
    }
    else if(root->data<data){
        return search(root->right,data);
    }
    else return root;
}

node* getSuccessor(node*root,int data){
    node*curr=search(root,data);
    if(curr==NULL){
        return NULL;
    }
    //case 1: node has right subtree
    if(curr->right!=NULL){
        node*temp=findMin(curr->right);
        return temp;
    }
    //case 2: no right subtree
    else{
        node*successor=NULL;
        node*ancestor=root;
        while(ancestor!=curr){
            if(ancestor->data>curr->data){
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else{
                ancestor=ancestor->right;
            }
        }
        return successor;
    }
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
    node*successor=getSuccessor(root,15);
    cout<<successor->data;
    cout<<"\n";
    return 0;
}
