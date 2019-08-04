/*check if 2 trees are identical or not
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

bool isIdentical(node*root1,node*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1!=NULL && root2!=NULL){
        if(root1->data==root2->data && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right)){
            return true;
        }
    }
    return false;
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
    node*root1=NULL;
    cin>>root1;
    node*root2=NULL;
    cin>>root2;
    cout<<root1;
    cout<<root2;
    if(isIdentical(root1,root2))
        cout<<"identical";
    else cout<<"not identical";
    return 0;
}
