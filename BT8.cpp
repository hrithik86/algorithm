//Implementation of Binary Tree
#include <iostream>
#include <queue>
using namespace std;

class node{
public:
  int data;
  node*left;
  node*right;
  node(int d):data(d),left(NULL),right(NULL){
      
  }
};

void print(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"->";
    if(root->left){
        cout<<root->left->data<<",";
    }
    if(root->right){
        cout<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}

node*takeInput(){
    int data;
    cin>>data;
    node*n=NULL;
    if(data!=-1){
        n=new node(data);
        n->left=takeInput();
        n->right=takeInput();
    }
    return n;
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

//operator overloading
istream& operator>>(istream& is,node*&root){
    root=takeLevelInput();
    return is;
}
ostream& operator<<(ostream& os,node*root){
    print(root);
    return os;
}

int main()
{
    node*root=NULL;
    cin>>root;
    cout<<root; 
    return 0;
}

