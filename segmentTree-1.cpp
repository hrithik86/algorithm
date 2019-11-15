//Segment Tree
//Compute sum within range
#include <iostream>
using namespace std;


/* Building Segment tree using dynamically created nodes:
class node{
public:
    int value;
    int s;
    int e;
    node*left;
    node*right;
    node(int d,int start,int end){
        value=d;
        int s=start;
        int e=end;
        left=NULL;
        right=NULL;
    }
};

node* buildSegment(int arr[],int start,int end){
    if(start==end){
        node *temp=new node(arr[start],start,end);
        return temp;
    }
    node*leftTree=buildSegment(arr,start,(start+end)/2);
    node*rightTree=buildSegment(arr,((start+end)/2) +1,end);
    node* temp=new node(leftTree->value+rightTree->value,start,end);
    temp->left=leftTree;
    temp->right=rightTree;
    return temp;
}

void print(node* root){
    if(root==NULL){
        return;
    }
    print(root->left) ;
    cout<<root->value<<" ";
    print(root->right);
} 


int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    node* root=NULL;
    root=buildSegment(arr,0,n-1);
    print(root);
    cout<<query(root,2,7);
    return 0;
}
*/

//Building Segment tree using array

void buildTree(int* arr,int*tree,int start,int end,int treeNodeIndex){
    if(start==end){
        tree[treeNodeIndex]=arr[start];
        return;
    }
    buildTree(arr,tree,start,(start+end)/2,2*treeNodeIndex);
    buildTree(arr,tree,((start+end)/2)+1,end,2*treeNodeIndex+1);
    tree[treeNodeIndex]=tree[2*treeNodeIndex]+tree[(2*treeNodeIndex)+1];
}

void updateTree(int*arr,int*tree,int start,int end,int treeNode,int idx,int value){
    if(start==end){
        arr[idx]=value;
        tree[treeNode]=value;
        return;
    }
    int mid=(start+end)/2;
    if(idx>mid){
        updateTree(arr,tree,mid+1,end,2*treeNode +1 ,idx,value);
    }
    else{
        updateTree(arr,tree,start,mid,2*treeNode ,idx,value);
    }
    tree[treeNode]=tree[2*treeNode]+tree[(2*treeNode)+1];
}

int query(int*tree,int start,int end,int treeNode,int left,int right){
    //completely outside range
    if( start>right || end<left ){
        return 0;
    }
    //completely inside range
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    //partially inside and partially ouside
    int mid=(start+end)/2;
    int ans1=query(tree,start,mid,2*treeNode,left,right);
    int ans2=query(tree,mid+1,end,2*treeNode+1,left,right);
    return ans1+ans2;
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int* tree=new int[2*n];
    buildTree(arr,tree,0,n-1,1);
    updateTree(arr,tree,0,n-1,1,2,10);
    int l=2;int r=4;
    cout<<"Sum between index 2 and 4(both inclusive)="<<query(tree,0,n-1,1,l,r)<<endl;
    for(int i=1;i<2*n;i++){
        cout<<tree[i]<<" ";
    }
    return 0;
}

