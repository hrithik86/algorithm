//Disjoint Set or Union Find (DSU)
#include <bits/stdc++.h>
using namespace std;

int findRoot(int node,int *parent){
    if(parent[node]==-1){
        return node;
    }
    int par=findRoot(parent[node],parent);
    parent[node]=par;
    return par;
}

void Union(int a,int b,int *parent){
    int c=findRoot(a,parent);
    int d=findRoot(b,parent);
    parent[c]=d;
}

int main()
{
    int V,E;
    cin>>V>>E;
    int *parent=new int[V];
    for(int i=0;i<V;i++){
        parent[i]=-1;
    }
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        Union(a,b,parent);
    }
    for(int i=0;i<V;i++){
        cout<<parent[i]<<" ";
    }
    return 0;
}
