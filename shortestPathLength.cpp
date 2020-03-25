// Shortest path length using BFS in an undirected graph where each edge is of 1 unit.
/*
I/O:
8 10
0 1
0 3
1 2
3 4
3 7
4 5
4 6
4 7
5 6
6 7

O/P:
shortest length of 0 from 0:0
shortest length of 1 from 0:1
shortest length of 3 from 0:1
shortest length of 2 from 0:2
shortest length of 4 from 0:2
shortest length of 7 from 0:2
shortest length of 5 from 0:3
shortest length of 6 from 0:3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V,n;        //V=number of vertices, n=number of edges
    cin>>V>>n;
    vector<vector<int>>v(V);    
    for(int i=0;i<n;i++){       
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int>q;
    bool visited[V]={false};
    visited[0]=true;
    q.push(0);
    int lvl=0;
    while(!q.empty()){
        lvl++;
        int S=q.size();
        for(int i=0;i<S;i++){
            int curr=q.front();
            q.pop();
            for(int j=0;j<v[curr].size();j++){
                if(!visited[v[curr][j]]){
                    q.push(v[curr][j]);
                    visited[v[curr][j]]=true;
                }
            }
            cout<<"shortest length of "<<curr<<" from 0:"<<lvl-1<<"\n";
        }
    }
	return 0;
}