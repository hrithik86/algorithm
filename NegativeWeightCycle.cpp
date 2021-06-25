// Negative Weight Cycle (using Bellman Ford Algorithm)
// TC: O(V*E)
#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int n, vector<vector<int>>edges,int dist[]){
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    int src=0;
    dist[src]=0;
    int m=edges.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if(dist[u]==INT_MAX) continue;
            if(dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
}

// Returns 1 if graph contains negative weight cycle
int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    int dist[n];
    
    // Single source shortest path Algorithm
    bellmanFord(n,edges,dist);
    
    // Relax the edges one more time to check
    // for negative edges
    for(int j=0;j<edges.size();j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int wt=edges[j][2];
        if(dist[u]==INT_MAX) continue;

        // If the distance further reduces, then
        // there is a negative edge
        if(dist[u]+wt<dist[v]){
            return 1;
        }
    }
    return 0;
}

int main() {
    int n = 3; 
    vector<vector<int>>edges{{0,1,-1},{1,2,-2},{2,0,-3}};
    cout<<isNegativeWeightCycle(n,edges);
    return 0;
}
