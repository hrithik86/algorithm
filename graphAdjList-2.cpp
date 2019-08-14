//Graph Implementation:Adjacency List-2
//using hashing
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
    
    void bfs(T src,T dest){
        unordered_map<T,bool>visited;
        unordered_map<T,int>distance;
        unordered_map<T,T>parent;
        for(auto it=l.begin();it!=l.end();it++){
            distance[it->first]=INT_MAX;
        }
        queue<T>q;
        q.push(src);
        visited[src]=true;
        distance[src]=0;
        parent[src]=src;
        while(!q.empty()){
            T f=q.front();
            cout<<f<<endl;
            q.pop();
            for(int i=0;i<l[f].size();i++){ 
                if(!visited[l[f][i]]){
                    distance[l[f][i]]=distance[f]+1;
                    parent[l[f][i]]=f;
                    q.push(l[f][i]);
                    visited[l[f][i]]=true;
                }
            }
        }
        ///print the distance
        cout<<"distance from "<<src<<endl;
        for(auto it=l.begin();it!=l.end();it++){
            cout<<it->first<<" - "<<distance[it->first]<<endl;
        }
        //path from src to dest
        cout<<"path from src to dest"<<endl;
        T temp;
        temp=dest;
        while(temp!=src){
            cout<<temp<<"<----";
            temp=parent[temp];
            
        }
        cout<<src<<endl;
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
    g.addEdge("delhi","agra");
    g.addEdge("delhi","mumbai");
    g.addEdge("jaipur","bhopal");
    g.addEdge("agra","jaipur");
    g.addEdge("mumbai","agra");
    g.printAdjList();
    g.bfs("bhopal","mumbai");
    return 0;
}
