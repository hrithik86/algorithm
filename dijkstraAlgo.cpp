//dijkstra algo
//Weighted graph
//      ->Shortest path from src to all other nodes

//Note: set is used since it stores the items in the sorted order

#include <iostream>
#include <list>
#include <set>
#include <climits>
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
    void dijkstra(int src){
        int *dist=new int[V];
        for(int i=0;i<V;i++){
            dist[i]=INT_MAX;
        }
        dist[src]=0;
        set<pair<int ,int>>s;           //1st item in pair represents the dist from src,2nd item is the node 
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto it=s.begin();
            int parent=it->second;
            int parentDist=it->first;
            s.erase(it);
            for(auto j=l[parent].begin();j!=l[parent].end();j++){
                if(parentDist+ j->second < dist[j->first]){
                    int oldDist=dist[j->first];
                    auto f=s.find(make_pair(oldDist,j->first));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[j->first]=parentDist+ j->second;
                    s.insert(make_pair(dist[j->first],j->first));
                    
                }
            }
        }
        for(int i=0;i<V;i++){
            cout<<i<<" == "<<dist[i]<<endl;
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,1,1);
    g.addEdge(0,4,6);
    g.addEdge(1,4,3);
    g.addEdge(1,2,4);
    g.addEdge(4,2,1);
    g.addEdge(2,3,3);
    g.addEdge(4,5,7);
    g.addEdge(3,5,2);
    g.dijkstra(0);
    return 0;
}
