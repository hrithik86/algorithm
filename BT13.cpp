/*Operations on binary tree
        1.Mirror Image of a Tree
        2.Balanced tree or not
        A balanced tree is one in which for each node the difference b/w its subtrees is not more than 1

I/P:1 2 3 4 5 6 7 8 -1 -1 -1 -1 -1 -1 9 -1 -1 -1 -1
O/P:    
        8 4 5 2 6 9 7 3 1 
        9 7 6 3 5 8 4 2 1
        Balanced
*/


#include <iostream>
#include <math.h>
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

int height(node*root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}


void mirror(node*root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left,root->right);
    return;
}

pair<int,bool> isBalanced(node*root){
    if(root==NULL){
        return make_pair(0,true);
    }
    pair<int,bool> left=isBalanced(root->left);
    pair<int,bool> right=isBalanced(root->right);
    int height=max(left.first,right.first)+1;
    if(abs(left.first-right.first)<=1 && left.second && right.second){
        return make_pair(height,true);
    }
    else{
        return make_pair(height,false);
    }
}

void postOrder(node*root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
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
    node*root=NULL;
    cin>>root;
    cout<<endl;
    postOrder(root);
    mirror(root);
    cout<<endl;
    postOrder(root);
    bool isB=isBalanced(root).second;
    if(isB){
        cout<<"Balanced";
    }
    else cout<<"Not balanced";
    return 0;
}
