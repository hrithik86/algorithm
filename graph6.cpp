//DFS
//count group of 1s in a grid of 1s and 0s.
#include<bits/stdc++.h>
using namespace std;

void dfsHelper(int mat[][5],int i,int j,int row,int col,bool visited[]){
        visited[(i*col)+j]=true;
        //checking for left neighbour
        if(j-1>=0 && mat[i][j-1]==1 &&  !visited[(i*col)+j-1]){
            dfsHelper(mat,i,j-1,row,col,visited);
        }
        //checking for upper neighbour
        if(i-1>=0 && mat[i-1][j]==1 &&  !visited[((i-1)*col)+j]){
            dfsHelper(mat,i-1,j,row,col,visited);
        }
        //checking for right neighbour
        if(j+1<col && mat[i][j+1]==1 &&  !visited[(i*col)+j+1]){
            dfsHelper(mat,i,j+1,row,col,visited);
        }
        //checking for bottom neighbour
        if(i+1<row && mat[i+1][j]==1 &&  !visited[((i+1)*col)+j]){
            dfsHelper(mat,i+1,j,row,col,visited);
        }
}
int dfs(int mat[][5],int row,int col){
        int V=row*col;
        bool* visited=new bool[row*col];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visited[(i*col)+j] && mat[i][j]==1){
                    count++;
                    dfsHelper(mat,i,j,row,col,visited);
                }    
            }
        }
        return count;
}


int main()
{
    int mat[][5]={
        {0,1,0,0,1},
        {1,0,0,1,1},
        {0,1,1,1,1},
        {0,0,0,0,1}
    };
    cout<<dfs(mat,4,5);
    return 0;
}
