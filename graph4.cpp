//DFS
//(Depth first search)
#include<iostream>
#include<unordered_map>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include <climits>

using namespace std;
#define hashmap unordered_map<T,vector<T>>

template<typename T>
class Graph{
    int V;
    hashmap l;
public:
    Graph(){
        V=0;
    }
    void addEdge(T u,T v,bool bidir=true ){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
        V=l.size();
    }
    
    void dfsHelper(T src,unordered_map<T,bool>&v){
        v[src]=true;
        cout<<src<<" ";
        for(auto it=l[src].begin();it!=l[src].end();it++){
            if(!v[*it]){
                dfsHelper(*it,v);
            }
        }
    }
    
    void dfs(){
        unordered_map<T,bool>visited;
        for(auto it=l.begin();it!=l.end();it++){
            if(!visited[it->first]){
                dfsHelper(it->first,visited);
                cout<<endl;
            }
            
        }
        
    }
    
    void printAdjList(){
        for(auto i=l.begin();i!=l.end();i++){
            T current=i->first;
            cout<<current<<"->";
            
            for(auto j=0;j<l[current].size();j++){
                cout<<l[current][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("delhi","mumbai");
    g.addEdge("delhi","agra");
    g.addEdge("agra","mumbai");
    g.addEdge("agra","jaipur");
    g.addEdge("bhopal","jaipur");
    g.addEdge("andaman","nicobar");
    g.dfs();
    return 0;
}
