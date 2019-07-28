/*Operations on binary tree
        1.diameter of a binary tree
        
Enter root data:1

Enter children of 1 - 2 4

Enter children of 2 - 3 -1

Enter children of 4 - 7 5

Enter children of 3 - -1 -1

Enter children of 7 - -1 -1

Enter children of 5 - -1 6

Enter children of 6 - -1 -1
1
2 4
3 7 5
6
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

int height(node*root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

int diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int op1=height(root->left)+height(root->right);
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}

class Pair{
    public:
        int height;
        int dia;
};
Pair fastDiameter(node*root){
    Pair p;
    if(root==NULL){
        p.height=0;
        p.dia=0;
        return p;
    }
    Pair left=fastDiameter(root->left);
    Pair right=fastDiameter(root->right);
    int op1=left.height+right.height;
    int op2=left.dia;
    int op3=right.dia;
    p.dia=max(op1,max(op2,op3));
    p.height=1+max(left.height,right.height);
    return p;
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
    cout<<"\ndiameter:"<<diameter(root);
    cout<<"\ndiameter:"<<fastDiameter(root).dia<<endl;
    return 0;
}
