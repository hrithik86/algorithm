//Graph Implementation:Adjacency List-1

#include <iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>*l;
public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }
    void addEdge(int u,int v,bool bidir=true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }
    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(auto it=l[i].begin();it!=l[i].end();it++){
                cout<<*it<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
    g.addEdge(2,3);
    g.printAdjList();
    return 0;
}
