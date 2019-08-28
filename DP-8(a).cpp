// Count number of paths to reach rightmost-bottommost cell from topmost-leftmost cell
// allowed movements:rightwards and downwards i.e.,from a given cell, 
// we are allowed to move to cells (i+1, j) and (i, j+1) only.
                        
#include <iostream>
using namespace std;

int waysToReachEnd(int m,int n){
    int dp[100][100];               //dp[i][j] represents number of ways yo reach index (i,j)
    //Base Case
    int i,j;
    for(i=0;i<m;i++){
        dp[i][0]=1;
    }
    for(j=0;j<n;j++){
        dp[0][j]=1;
    }
    
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    // for(i=0;i<m;i++){
    //     for(j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[m-1][n-1];
}

int main()
{
    int m=3,n=4;
    cout<<waysToReachEnd(m,n) ;    // m rows & n columns
    return 0;
}
