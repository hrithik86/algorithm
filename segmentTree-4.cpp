/*
Segment Tree
Range Maximum query Node update
https://www.geeksforgeeks.org/segment-tree-set-2-range-maximum-query-node-update/

I/P:
5 
2 4 0 7 9

O/P:
4 7 10 10
*/

#include <bits/stdc++.h>
using namespace std;

void buildTree(int start,int end,int treeIndex,int a[],int tree[]){
    if(start==end){
        tree[treeIndex]=a[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(start,mid,2*treeIndex+1,a,tree);
    buildTree(mid+1,end,2*treeIndex+2,a,tree);
    tree[treeIndex]=max(tree[2*treeIndex+1],tree[2*treeIndex+2]);
}

int getMax(int left,int right,int start,int end,int a[],int tree[],int treeIndex=0){
    if(left<=start && end<=right){
        return tree[treeIndex];
    }
    if(end<left || start>right){
        return INT_MIN;
    }
    int mid=(start+end)/2;
    if(right<=mid){
        return getMax(left,right,start,mid,a,tree,2*treeIndex+1);
    }
    else if(left>mid){
        return getMax(left,right,mid+1,end,a,tree,2*treeIndex+2);
    }
    return max(getMax(left,right,start,mid,a,tree,2*treeIndex+1),getMax(left,right,mid+1,end,a,tree,2*treeIndex+2));
}

void update(int index,int val,int start,int end,int a[],int tree[],int treeIndex=0){
    if(start==end){
        a[index]=val;
        tree[treeIndex]=val;
        return;
    }
    int mid=(start+end)/2;
    if(index<=mid){
        update(index,val,start,mid,a,tree,2*treeIndex+1);
    }
    else update(index,val,mid+1,end,a,tree,2*treeIndex+2);
    tree[treeIndex]=max(tree[2*treeIndex+1],tree[2*treeIndex+2]);
}

int main() {
    int n;
    cin>>n;
    int quantity[n];
    for(int i=0;i<n;i++){
        cin>>quantity[i];
    }
    int *tree=new int[4*n];
    buildTree(0,n-1,0,quantity,tree);
    // for(int i=0;i<4*n;i++){
    //     cout<<tree[i]<<" ";
    // }
    cout<<getMax(0,1,0,n-1,quantity,tree)<<" ";
    cout<<getMax(1,3,0,n-1,quantity,tree)<<" ";
    
    update(2,10,0,n-1,quantity,tree);
    
    cout<<getMax(2,2,0,n-1,quantity,tree)<<" ";
    cout<<getMax(1,4,0,n-1,quantity,tree)<<" ";
}