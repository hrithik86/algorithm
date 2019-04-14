//Sudoku Solver

#include <bits/stdc++.h>
using namespace std;

void print(int matrix[][10],int n){
    for( int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
    cout<<endl;
    }
}

bool canPlace(int matrix[][10],int i,int j,int num,int n){
    
    //checking for columns
    for(int k=0;k<9;k++){
        if(matrix[k][j]==num){
            return false;
        }
    }
    //checking for rows
    for(int k=0;k<9;k++){
        if(matrix[i][k]==num){
            return false;
        }
    }
    //checking the subgrid
    int rn=sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;
    for(int x=sx;x<sx+rn;x++){
        for(int y=sy;y<sy+rn;y++){
            if(matrix[x][y]==num){
                return false;
            }
        }
    }
    
    return true;
}

bool solveSudoku(int matrix[][10],int i,int j,int n){
    //base case
    if(i==n){
        //print the matrix
        print(matrix,n);
        return true;
    }
    if(j==n){
        return solveSudoku(matrix,i+1,0,n);
    }
    //skip the already filled numbers(the blue cells)
    if(matrix[i][j]!=0){
        return solveSudoku(matrix,i,j+1,n);
    }
    //white cell
    for(int no=1;no<=n;no++){
        if(canPlace(matrix,i,j,no,n)){
            matrix[i][j]=no;
            bool solveHuiKya=solveSudoku(matrix,i,j+1,n);
            if(solveHuiKya){
                return true;
            }
            //backtracking
            matrix[i][j]=0;
        }
    }
    return false;
}

int main()
{   int n=9;
    int matrix[10][10]=
                    {   
                        {5,3,0,0,7,0,0,0,0},
                        {6,0,0,1,9,5,0,0,0},
                        {0,9,8,0,0,0,0,6,0},
                        {8,0,0,0,6,0,0,0,3},
                        {4,0,0,8,0,3,0,0,1},
                        {7,0,0,0,2,0,0,0,6},
                        {0,6,0,0,0,0,2,8,0},
                        {0,0,0,4,1,9,0,0,5},
                        {0,0,0,0,8,0,0,7,9}
                    };
    print(matrix,n);
    cout<<endl;
    solveSudoku(matrix,0,0,n);
    
    return 0;
}
