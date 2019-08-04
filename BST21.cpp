//kth smallest element in a BST
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


vector<int> kthSmallest(node*root,vector<int>v){
    if(root==NULL){
        return v;
    }
    v=kthSmallest(root->left,v);
    v.push_back(root->data);
    v=kthSmallest(root->right,v);
    return v;
}

//operator overloading
ostream& operator<<(ostream& os,node*root){
    levelOrderOutput(root);
    return os;
}
int main()
{
    vector<int>v;
    node*root=NULL;
    root=insert(root,8);
    root=insert(root,4);
    root=insert(root,15);
    root=insert(root,2);
    root=insert(root,6);
    root=insert(root,10);
    root=insert(root,20);
    cout<<root<<endl;
    int k=3;
    v=kthSmallest(root,v);
    cout<<v[k-1];
    return 0;
}