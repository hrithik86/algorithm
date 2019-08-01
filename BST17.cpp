//converting a BST to a linked list
#include <iostream>
#include <queue>
using namespace std;

class node{
public:
  int data;
  node*left;
  node*right;
};

void levelOrderOutput(node*root){
    if(root==NULL){
        return;
    }
    queue<node*>Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        node*current=Q.front();
        Q.pop();
        if(current==NULL){
            cout<<endl;
            if(!Q.empty()){
                Q.push(NULL); 
            }
        }
        else{
            cout<<current->data<<" ";
            if(current->left!=NULL) Q.push(current->left);
            if(current->right!=NULL) Q.push(current->right);
    
        }
    }
}

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

//operator overloading
ostream& operator<<(ostream& os,node*root){
    levelOrderOutput(root);
    return os;
}

class LL{
    public:
        node*head;
        node* tail;
};

LL tree2LL(node*root){
    LL l;
    if(root==NULL){
        l.head=NULL;
        l.tail=NULL;
        return l;
    }
    else if(root->left==NULL && root->right==NULL){
        l.head=root;
        l.tail=root;
        return l;
    }
    else if(root->left!=NULL && root->right==NULL){
        LL leftLL=tree2LL(root->left);
        leftLL.tail->right=root;
        l.tail=root;
        l.head=leftLL.head;
    }
    else if(root->left==NULL && root->right!=NULL){
        LL rightLL=tree2LL(root->right);
        root->right=rightLL.head;
        l.head=root;
        l.tail=rightLL.tail;
    }
    else{
        LL leftLL=tree2LL(root->left);
        LL rightLL=tree2LL(root->right);
        leftLL.tail->right=root;
        root->right=rightLL.head;
        l.head=leftLL.head;
        l.tail=rightLL.tail;
    }
    return l;
}

int main()
{
    node*root=NULL;
    root=insert(root,8);
    root=insert(root,6);
    root=insert(root,9);
    root=insert(root,6);
    root=insert(root,5);
    root=insert(root,7);
    root=insert(root,11);
    root=insert(root,10);
    cout<<root<<endl;
    LL mylist=tree2LL(root);
    node*temp=mylist.head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    return 0;
}
