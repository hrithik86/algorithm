/*Operations on Binary Tree
    1.Printing nodes in the given range
    2.Printing nodes at a certain level
    3.Printing nodes at a distace k from the root node
*/       

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

void print(node*root,int k1,int k2){
    if(root==NULL){
        return;
    }
    print(root->left,k1,k2);
    print(root->right,k1,k2);
    if(root->data>=k1 && root->data<=k2){
        cout<<root->data<<" ";
    }
}

void printLevel(node*root,int level,int currLevel=1){
    if(root==NULL){
        return;
    }
    if(currLevel==level){
        cout<<root->data<<" ";
    }
    printLevel(root->left,level,currLevel+1);
    printLevel(root->right,level,currLevel+1);
}

void printKDistant(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
    }
    printKDistant(root->left,k-1);
    printKDistant(root->right,k-1);
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
    cout<<root; 
    cout<<endl;
    int k1=3,k2=7;
    cout<<"Values between range "<<k1<<" & "<<k2<<" are:";
    print(root,k1,k2);
    cout<<endl;
    int k=2;
    cout<<"Nodes at level "<<k<<" are:";
    printLevel(root,k);
    cout<<endl;
    cout<<"Nodes at a distance "<<k<<" from root nodes are:";
    printKDistant(root,k);
    return 0;
}
