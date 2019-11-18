//Segment Tree
//Lazy Propagation in Segment Tree
#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int*tree,int start,int end,int treeIndex){
    if(start==end){
        tree[treeIndex]=arr[start];
        return;
    }
    
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeIndex);
    buildTree(arr,tree,mid+1,end,2*treeIndex+1);
    tree[treeIndex]=min(tree[2*treeIndex],tree[2*treeIndex+1]);
    return;
}

void updateTree(int*tree,int *lazy,int low,int high,int startR,int endR,int currPos,int inc){
    if(low>high){
        return;
    }
    if(lazy[currPos]!=0){
        tree[currPos]+=lazy[currPos];
        if(low!=high){
            lazy[2*currPos]+=lazy[currPos];
            lazy[2*currPos+1]+=lazy[currPos];
        }
        lazy[currPos]=0;
    }
    //completely outside
    if(startR>high || endR<low){
        return;
    }
    //complete overlap
    if(startR<=low && high <=endR){
        tree[currPos]+=inc;
        if(low!=high){                  //not a leaf node
            lazy[2*currPos]+=inc;
            lazy[2*currPos+1]+=inc;
        }
        return;
    }
    //partial overlap
    int mid=(low+high)/2;
    updateTree(tree,lazy,low,mid,startR,endR,2*currPos,inc);
    updateTree(tree,lazy,mid+1,high,startR,endR,2*currPos+1,inc);
    tree[currPos]=min(tree[2*currPos],tree[2*currPos+1]);
    return;
}


int main()
{
    int arr[]={1,3,-2,4};
    int*tree=new int[12]{};
    buildTree(arr,tree,0,3,1);
    int*lazy=new int[12]{};
    updateTree(tree,lazy,0,3,0,3,1,3);
    updateTree(tree,lazy,0,3,0,1,1,2);
    for(int i=1;i<12;i++){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<12;i++){
        cout<<lazy[i]<<" ";
    }
    return 0;
}

