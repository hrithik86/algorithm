//Segment Tree
//Max pair sum
/*
I/P: 
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5

O/P:
7
9
11
12
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
    int maximum;
    int secMax;
};

void buildTree(int *arr,node*tree,int treeIndex,int start,int end){
    if(start==end){
        tree[treeIndex].maximum=arr[start];
        tree[treeIndex].secMax=INT_MIN;
        return;
    }
    
    int mid=(start+end)/2;
    buildTree(arr,tree,2*treeIndex,start,mid);
    buildTree(arr,tree,2*treeIndex+1,mid+1,end);
    node left=tree[2*treeIndex];
    node right=tree[2*treeIndex+1];
    tree[treeIndex].maximum=max(left.maximum,right.maximum);
    tree[treeIndex].secMax=min(max(left.maximum,right.secMax),max(right.maximum,left.secMax));
    return;
}

void updateTree(int *arr,node *tree,int start,int end,int treeNode,int idx,int value){
    if(start==end){
        arr[idx]=value;
        tree[treeNode].maximum=value;
        tree[treeNode].secMax=INT_MIN;
        return;
    }
    int mid=(start+end)/2;
    if(mid>idx){
        updateTree(arr,tree,start,mid,2*treeNode,idx,value);
    }
    else{
        updateTree(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    }
    node left=tree[2*treeNode];
    node right=tree[2*treeNode+1];
    tree[treeNode].maximum=max(left.maximum,right.maximum);
    tree[treeNode].secMax=min(max(left.maximum,right.secMax),max(right.maximum,left.secMax));
    return;
}

pair<int,int> query(node*tree,int start,int end,int treeNode,int left,int right){
    //completely outside range
    if(start>right || end<left){
        return make_pair(INT_MIN,INT_MIN);        
    }
    //completely inside
    else if(start>=left && end<=right){
        return make_pair(tree[treeNode].maximum,tree[treeNode].secMax);        
    }
    //partially inside partially outside
    int mid=(start+end)/2;
    pair<int,int> ans1=query(tree,start,mid,2*treeNode,left,right);
    pair<int,int> ans2=query(tree,mid+1,end,2*treeNode+1,left,right);
    return make_pair(max(ans1.first,ans2.first),min(max(ans1.first,ans2.second),max(ans2.first,ans1.second)));
}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node* tree=new node[3*n];
    buildTree(arr,tree,1,0,n-1);
    int t;
    cin>>t;
    while(t--){
        char c;
        int a,b;
        cin>>c>>a>>b;
        if(c=='Q'){             //query
            pair<int,int> ans=query(tree,0,n-1,1,a-1,b-1);
            cout<<ans.first+ans.second<<endl;
        }
        else{
            updateTree(arr,tree,0,n-1,1,a-1,b);
        }
    }
    return 0;
}

