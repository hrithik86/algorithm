/*N Queen Problem*/

#include <iostream>
using namespace std;

bool canPlace(int board[][100],int i,int j,int n){
    //check for column
    for(int row =0;row<i;row++){
        if(board[row][j]==1){
            return false;
        }
    }
    //check for top left diagonal 
    int x=i,y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    //check for top right diagonal
    x=i;y=j;
    while(x>=0&&y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;y++;
    }
    return true;
}

bool solveNQueen(int board[][100],int n,int i=0){
    //Base case
    if(i==n){
        //print the board
        for(i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char ch=board[i][j]?'Q':'0';
                cout<<ch<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //try to place the queen at each position in the current row
    for(int j=0;j<n;j++){
        if(canPlace(board,i,j,n)){
            board[i][j]=1;
            bool queenRakhPayeKya=solveNQueen(board,n,i+1);
            if(queenRakhPayeKya==true){
                return true;
            }
            //Backtracking
            board[i][j]=0;
        }
    }
    return false;
}

int main()
{   int n,board[100][100]={0};
    cin>>n;
    solveNQueen(board,n);
    return 0;
}
