/*Operations on Binary Tree
        1.Number of nodes
        2.Sum of nodes
        3.Update each node in the tree with the sum of its left-subtree and its right-subtree. 

Enter root data:1

Enter children of 1 - 2 3

Enter children of 2 - 4 5

Enter children of 3 - 6 -1

Enter children of 4 - -1 -1

Enter children of 5 - 7 8

Enter children of 6 - -1 -1

Enter children of 7 - -1 -1

Enter children of 8 - -1 -1
1
2 3
4 5 6
7 8

Number of nodes:8
Sum of nodes:36

35
24 6
4 15 6
7 8
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

//operator overloading
istream& operator>>(istream& is,node*&root){
    root=takeLevelInput();
    return is;
}
ostream& operator<<(ostream& os,node*root){
    levelOrderOutput(root);
    return os;
}

//Number of nodes in a BT
int noOfNodes(node*root){
    if(root==NULL){
        return 0;
    }
    return noOfNodes(root->left)+noOfNodes(root->right)+1;
}

//Sum of nodes in a BT
int sumNodes(node*root){
    if(root==NULL){
        return 0;
    }
    return sumNodes(root->left)+sumNodes(root->right)+root->data;
}

//changing nodes to the sum of their children
int updateTree(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    
    int x=root->data;
    root->data=updateTree(root->left)+updateTree(root->right);
    return root->data+x;
}

int main()
{
    node*root=NULL;
    cin>>root;
    cout<<root; 
    cout<<"\nNumber of nodes:"<<noOfNodes(root);
    cout<<"\nSum of nodes:"<<sumNodes(root);
    updateTree(root);
    cout<<endl;
    cout<<root;
    return 0;
}
