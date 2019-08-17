//DFS
//Journey to the moon(hackerrank problem)
//https://www.hackerrank.com/challenges/journey-to-the-moon/problem
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
    void dfsHelper(int i,bool visited[],int &count){
        count++;
        visited[i]=true;
        // cout<<i<<" ";
        for(auto it=l[i].begin();it!=l[i].end();it++){
            if(!visited[*it]){
                dfsHelper(*it,visited,count);
            }
        }
    }
    int dfsMoon(){
        bool* visited=new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        int total_ways=V*(V-1)/2;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                int count=0;
                dfsHelper(i,visited,count);
                total_ways-=(count*(count-1)/2);
            }
        }
        return total_ways;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(0,4);
    cout<<"Total ways:"<<g.dfsMoon();
    return 0;
}
