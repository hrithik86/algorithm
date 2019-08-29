/*DP
    Number of ways to reach index (i,j)
*/
#include <iostream>
using namespace std;

void knightToDest(int m,int n){
    int i,j,dp[100][100]={0};
    dp[0][0]=1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i-1>=0 && j-2>=0){
                dp[i][j]+=dp[i-1][j-2];
            }
            if(i-2>=0 && j-1>=0){
                dp[i][j]+=dp[i-2][j-1];
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rookToDest(int m,int n){
    //base case
    int i,j,dp[100][100]={0};
    dp[0][0]=1;
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            for(int k=0;k<i;k++){
                dp[i][j]+=dp[k][j];
            }
            for(int k=0;k<j;k++){
                dp[i][j]+=dp[i][k];
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

void advancedRook(int m,int n){             //can move like bishop also(diagonally)
    //base case
    int i,j,dp[100][100]={0};
    dp[0][0]=1;
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            int x=i-1,y=j-1;
            for(int k=0;k<i;k++){
                dp[i][j]+=dp[k][j];
            }
            for(int k=0;k<j;k++){
                dp[i][j]+=dp[i][k];
            }
            //for diagonal moves
            while(x>=0 && y>=0){
                dp[i][j]+=dp[x][y];
                x--;y--;
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"Ways for a Knight to reach (i,j) index:\n";
    knightToDest(4,4);
    cout<<"\nWays for a Rook to reach (i,j) index:\n";
    rookToDest(4,4);
    cout<<"\nWays for a Advanced Rook(can also move diagonally) to reach (i,j) index:\n";
    advancedRook(4,4);
    return 0;
}
