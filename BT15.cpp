/*Operations on binary tree
    1.Construct Tree from given Inorder and Preorder traversals
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

void printInorder(node* node)  
{  
    if (node == NULL)  
        return;  
  
    /* first recur on left child */
    printInorder(node->left);  
  
    /* then print the data of node */
    cout<<node->data<<" ";  
  
    /* now recur on right child */
    printInorder(node->right);  
}  

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


int search(int in[],int inS,int inE,int data){
    int flag;
    for(int i=inS;i<=inE;i++){
        if(in[i]==data){
            flag=i;
            break;
        }
    }
    return flag;
}

node* buildTree(int in[],int pre[],int inS,int inE){
    static int preIndex=0 ;
    if(inS>inE){
        return NULL;
    }    
    node* tNode=new node();
    tNode->data=pre[preIndex];
    preIndex++;
    if(inS==inE){
        return tNode;
    }
    int searchIndex=search(in,inS,inE,tNode->data);
    tNode->left=buildTree(in,pre,inS,searchIndex-1);
    tNode->right=buildTree(in,pre,searchIndex+1,inE);
    return tNode;
}

//operator overloading

ostream& operator<<(ostream& os,node*root){
    levelOrderOutput(root);
    return os;
}

int main()
{   
    node*root=NULL;
    int in[]={4, 2, 5, 1, 3};
    int pre[]={1, 2, 4, 5, 3};
    int n=sizeof(in)/sizeof(in[0]);
    root=buildTree(in,pre,0,n-1);
    cout<<root;
    // printInorder(root);  
    return 0;
}
