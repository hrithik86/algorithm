/*
Check whether a given graph is Bipartite or not
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
    cin>>v>>e;
    list<int> *l=new list<int>[v];
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        l[a].push_back(b);
        l[b].push_back(a);
    }
    int *visited=new int[v];
    for(int i=0;i<v;i++){
        visited[i]=-1;                  //-1 :not visted,1 :color A, 0 :color B
    }
    visited[0]=1;
    queue<int >q;
    q.push(0);
    bool ans=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto it=l[curr].begin();it!=l[curr].end();it++){
            if(visited[*it]==-1){
                visited[*it]=1-visited[curr];
                q.push(*it);
            }
            else if(visited[*it]==visited[curr]){
                ans=false;
                break;
            }
        }
    }
    for(int i=0;i<v;i++) cout<<visited[i]<<" ";
    if(ans)
        cout<<"It is bipartite";
    else cout<<"It is not bipartite";
    return 0;
}
