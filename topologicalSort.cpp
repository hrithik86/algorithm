//Graph
//Topological Sort
    //Conditions for topological sort:
        // D - Directed
        // A - Acyclic
        // G - Graph
#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>>*l;
public:
    Graph(int v){
        V=v;
        l=new list<pair<int,int>>[V];
    }
    void addEdge(int u,int v,int wt,bool bidir=true){
        l[u].push_back(make_pair(v,wt));
        if(bidir){
            l[v].push_back(make_pair(u,wt));
        }
    }
    void topologicalSort(){
        int *indegree=new int[V]{0};
        //iterate over all edges
        for(int i=0;i<V;i++){
            for(auto it=l[i].begin();it!=l[i].end();it++){
                indegree[it->first]++;
            }    
        }
        queue<int >q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f=q.front();
            cout<<f<<" ";
            q.pop();
            for(auto it=l[f].begin();it!=l[f].end();it++){
                indegree[it->first]--;
                if(indegree[it->first]==0){
                    q.push(it->first);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,2,1,false);
    g.addEdge(0,3,1,false);
    g.addEdge(1,2,1,false);
    g.addEdge(2,3,1,false);
    g.addEdge(3,4,1,false);
    g.addEdge(3,5,1,false);
    g.addEdge(2,5,1,false);
    g.addEdge(4,5,1,false);
    g.topologicalSort();
    return 0;
}
