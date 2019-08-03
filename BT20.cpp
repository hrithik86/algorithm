/*
    Given a binary tree, print all root-to-leaf paths
*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
public:
  int data;
  node*left;
  node*right;
  node(int d):data(d),left(NULL),right(NULL){
      
  }
};

//--------------------------UTILITY FUNCTIONS-------------------------------------
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
node* takeLevelInput(){
    node*root=NULL;
    cout<<"Enter root data:";
    int data;
    cin>>data;
    root=new node(data);
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*f=q.front();
        q.pop();
        int d1,d2;
        cout<<"\nEnter children of "<<f->data<<" - ";
        cin>>d1>>d2;
        if(d1!=-1){
            f->left=new node(d1);
            q.push(f->left);
        }
        if(d2!=-1){
            f->right=new node(d2);
            q.push(f->right);
        }
    }
    return root;
}
//--------------------------------------------------------------------------------------

void printStack(stack<int>s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    printStack(s);
    cout<<temp<<" ";
}

void root2leaf(node*root,stack<int>s){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        s.push(root->data);
        printStack(s);
        cout<<endl;
        return;
    }
    s.push(root->data);
    root2leaf(root->left,s);
    root2leaf(root->right,s);
    s.pop();
    return;
}

//operator overloading
istream& operator>>(istream& is,node*&root){
    root=takeLevelInput();
    return is;
}
ostream& operator<<(ostream& os,node*root){
    levelOrderOutput(root);
    return os;
}
int main()
{
    stack<int>s;
    node*root=NULL;
    cin>>root;
    cout<<root;
    cout<<"All the paths from root to leaf nodes:\n";
    root2leaf(root,s);
    return 0;
}
