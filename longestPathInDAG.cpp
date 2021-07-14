// Longest Path in a Directed Acyclic Graph
// Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, 
// find the longest distances from s to all other vertices in the given graph.

// Longest Path (Code Studio)
#include <bits/stdc++.h>
using namespace std;

int farthestVertex(int edges[][2], int v, int e, int source) {
    int indegree[v]={0};
    list<int>l[v];
    for(int i=0;i<e;i++){
        int x=edges[i][0];
        int y=edges[i][1];
        l[x].push_back(y);
        indegree[y]++;
    }
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ordering;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ordering.push_back(node);
        for(auto it=l[node].begin();it!=l[node].end();it++){
            indegree[*it]--;
            if(indegree[*it]==0){
                q.push(*it);
            }
        }
    }
    int dist[v];
    for(int i=0;i<v;i++){
        dist[i]=INT_MIN;
    }
    dist[source]=0;
    for(int i=0;i<v;i++){
        int node=ordering[i];
        if(dist[node]==INT_MIN) continue;
        for(auto it=l[node].begin();it!=l[node].end();it++){
            if(dist[node]+1>dist[*it]){
                dist[*it]=dist[node]+1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<v;i++){
        ans=max(ans,dist[i]);
    }
    return ans;
}

int main() {
    int v=4,e=3;
    int edges[][2]={{0,1},{1,2},{2,3}};
    int source=1;
    cout<<farthestVertex(edges,v,e,source);
}
