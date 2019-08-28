/*Count number of ways to reach destination in a Maze
Given a maze with obstacles, count number of paths to reach rightmost-bottommost cell from topmost-leftmost cell. 
A cell in given maze has value -1 if it is a blockage or dead end, else 0.
From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only.*/
                        
#include <iostream>
using namespace std;

int countPaths(int maze[][4],int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        if(maze[i][0]==-1){
            break;    
        }
        maze[i][0]=1;
    }
    for(j=0;j<n;j++){
        if(maze[0][j]==-1){
            break;    
        }
        maze[0][j]=1;
    }
    
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            if(maze[i][j]!=-1){
                if(maze[i-1][j]!=-1)
                    maze[i][j]+=maze[i-1][j];
                if(maze[i][j-1]!=-1)
                    maze[i][j]+=maze[i][j-1];    
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    return maze[m-1][n-1];
}

int main()
{
    int maze[4][4] =  {{0,  0, 0, 0}, 
                       {0, -1, 0, 0}, 
                       {-1, 0, 0, 0}, 
                       {0,  0, 0, 0}}; 
    cout << countPaths(maze,4,4); 
    return 0;
}
