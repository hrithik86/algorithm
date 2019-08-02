//converting a sorted array to a balanced BST
//time complexity: O(n)
//space complexity: O(log n)        //see the call stack, max log n calls are there in the stack
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
node* buildTree(int in[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    node*root=createNewNode(in[mid]);
    root->left=buildTree(in,start,mid-1);
    root->right=buildTree(in,mid+1,end);
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

//operator overloading
ostream& operator<<(ostream& os,node*root){
    levelOrderOutput(root);
    return os;
}
int main()
{
    node*root=NULL;
    int in[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(in)/sizeof(in[0]);
    root=buildTree(in,0,n-1);
    cout<<root;
    cout<<endl;
    inOrder(root);
    return 0;
}
