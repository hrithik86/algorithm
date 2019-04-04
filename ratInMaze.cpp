/*Rat in a Maze problem 
The rat can only move in 2 directions:
rightwards
and downwards 
*/
#include <iostream>
using namespace std;

bool ratInMaze(char maze[][10],int sol[][10],int i,int j,int m,int n){
    //base case
    if(i==m && j==n){
        sol[i][j]=1;
        //Printing the solution
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                cout<<sol[i][j]<< " ";
            }
        cout<<endl;
        }
        return true;
    }
    //recursive case
    //assuming the path goes through the current cell
    sol[i][j]=1;
    if(maze[i][j+1]!='X' && j+1<=n){
        bool rastaMila=ratInMaze(maze,sol,i,j+1,m,n);
        if(rastaMila == true){
            return true;
        }
    }
    if(maze[i+1][j]!='X' && i+1<=m){
        bool rastaMila=ratInMaze(maze,sol,i+1,j,m,n);
        if(rastaMila == true){
            return true;
        }
    }
    //Backtracking
    sol[i][j]=0;
    return false;
}

int main()
{
    char maze[10][10]={
        "OOOOXX",
        "OOXXOX",
        "XOOOXO",
        "OOXOOO"
    };
    int sol[10][10]={0};
    int m=3,n=5;        //destination co-ordinates
    ratInMaze(maze,sol,0,0,m,n);
    return 0;
}
