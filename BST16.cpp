/*Operations on binary tree
        1.find BST elements in range k1 and k2
*/       

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

void inRange(node*root,int lowerBound,int upperBound){
    if(root==NULL){
        return;
    }
    //case 1:   lying between the range
    if(upperBound>= root->data && lowerBound<=root->data){
        cout<<root->data<<" ";
        inRange(root->left,lowerBound,upperBound);
        inRange(root->right,lowerBound,upperBound);
    }
    //case 2:   greater tha the range
    else if(root->data>upperBound){
        inRange(root->left,lowerBound,upperBound);
    }
    //case 3: less than the range
    else{
        inRange(root->right,lowerBound,upperBound);
    }
    return;
}

//operator overloading
ostream& operator<<(ostream& os,node*root){
    levelOrderOutput(root);
    return os;
}

int main()
{
    node*root=NULL;
    root=insert(root,10);
	root=insert(root,5);
	root=insert(root,50);
	root=insert(root,1);
	root=insert(root,40);
	root=insert(root,100);
    cout<<root<<endl;
    cout<<"BST elements in range:";
    inRange(root,5,45);
    return 0;
}
