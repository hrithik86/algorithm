/*Operations on binary tree
        1.max sum of a BT(either we can include the parent node or its children but not both(parent & children))
        
I/P:  1 13 5 11 2 7 -25 -1 -1 17 -1 -1 100 -1 -1 -1 -1 -1 -1
O/P:  135
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

pair<int,int> maxSum(node*root){
    if(root==NULL){
        return make_pair(0,0);
    }
    pair<int,int> left=maxSum(root->left);
    pair<int,int> right=maxSum(root->right);
    int inc=root->data+left.second+right.second;
    int exc=max(left.first,left.second)+max(right.first,right.second);
    return make_pair(inc,exc);
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
    pair<int,int>ans=maxSum(root);
    cout<<max(ans.first,ans.second)<<endl;
    return 0;
}
