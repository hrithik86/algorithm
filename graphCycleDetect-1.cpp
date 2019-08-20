//DFS
//Detect cycle in an undirected graph
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
    void addEdge(int u, int v,bool bidir=true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }
    bool dfsHelper(int i,bool visited[],int parent=-1){
        visited[i]=true;
        for(auto it=l[i].begin();it!=l[i].end();it++){

            if(!visited[*it]){
                if(dfsHelper(*it,visited,i)){
                    return true;    
                }  
            }
            else if(*it!=parent){
                return true;
            }
        }
        return false;
    }
    bool dfs(){
        bool* visited=new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        for(int i=0;i<V;i++){
            if(!visited[i]){
                return dfsHelper(i,visited);
            }
        }
    }
};

int main()
{
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    if(g1.dfs()){
        cout<<"Cyclic\n";    
    }
    else cout<<"Not Cyclic\n";
    Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    if(g2.dfs()){
        cout<<"Cyclic\n";    
    }
    else cout<<"Not Cyclic\n";
    return 0;
}
