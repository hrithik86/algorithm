/*
Shortest distance between two cells in a matrix or grid
Given a matrix of N*M order. Find the shortest distance from a source cell to a destination cell, traversing through limited cells only. Also you can move only up, down, left and right. If found output the distance else -1.
s represents ‘source’
d represents ‘destination’
* represents cell you can travel
0 represents cell you can not travel
This problem is meant for single source and destination.

Examples:

Input : {'0', '*', '0', 's'},
        {'*', '0', '*', '*'},
        {'0', '*', '*', '*'},
        {'d', '*', '*', '*'}
Output : 6

Input :  {'0', '*', '0', 's'},
         {'*', '0', '*', '*'},
         {'0', '*', '*', '*'},
         {'d', '0', '0', '0'}
Output :  -1
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    char grid[4][4] = { { '0', '*', '0', 's' }, 
                        { '*', '0', '*', '*' }, 
                        { '0', '*', '*', '*' }, 
                        { 'd', '*', '*', '*' } };
    
    int rows[]={-1,0,1,0};
    int cols[]={0,1,0,-1};
    queue<pair<int,int>>q;
    bool visited[4][4]={false};
    visited[0][3]=true;
    q.push(make_pair(0,3));
    int lvl=0,ans=INT_MAX;
    while(!q.empty()){
        lvl++;
        int S=q.size();
        for(int i=0;i<S;i++){
            pair<int,int>curr=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int I=curr.first+rows[k];
                int J=curr.second+cols[k];
                if(0<=I && I<4 && J>=0 && J<4 && grid[I][J]!='0' && !visited[I][J]){
                    q.push(make_pair(I,J));
                    visited[I][J]=true;
                    if(grid[I][J]=='d'){
                        ans=lvl;
                        break;
                    }
                }
            }
            // if(grid[curr.first][curr.second]=='d'){
            //     ans=lvl;
            //     break;
            // }
        }
    }
    if(ans!=INT_MAX) cout<<ans;
    else cout<<-1;
	return 0;
}