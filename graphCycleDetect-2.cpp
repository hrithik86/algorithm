//DFS
//Detect Cycle in a Directed Graph
#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    //pointer to a array of lists
    list<int>*l;
public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }
    void addEdge(int u, int v,bool bidir=false){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }
    bool dfsHelper(int i,bool visited[],bool recStack[]){
        visited[i]=true;
        recStack[i]=true;
        for(auto it=l[i].begin();it!=l[i].end();it++){
            if(!visited[*it]){
                if(dfsHelper(*it,visited,recStack)){
                    return true;    
                }  
            }
            else if(recStack[*it]){
                return true;
            }
        }
        recStack[i]=false;
        return false;
    }
    bool dfs(){
        bool* visited=new bool[V];
        bool* recStack=new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
            recStack[i]=false;
        }
        for(int i=0;i<V;i++){
            if(!visited[i]){
                return dfsHelper(i,visited,recStack);
            }
        }
    }
};

int main()
{
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    if(g.dfs()){
        cout<<"Cyclic\n";    
    }
    else cout<<"Not Cyclic\n";
    return 0;
}
