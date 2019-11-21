/*
Queens Way Out

The Queen is trapped at the top of a square matrix. To get out of the square matrix, she has to pass through exactly one cell of each row. The way out is through any one of the cells of last row.
The movement of the queen is restricted. If the queen is on A[i][j], she can go to A[i+1][j] or A[i+1][j-1] or A[i+1][j+1].
There is a cost associated with each cell. The queen needs to get out of the matrix, through a path such that she is traversing through exactly one cell in each row and the cost accrued by her should be minimum.
She needs your help in knowing the minimum cost through all possible paths.

I/P:
3
1 2 3
4 5 6
7 8 9

O/P:
12
*/

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
#define ll long long int


int minCost(int **cost,int n){
    int i,j;
    int **tc=new int*[n];
    for(i=0;i<n;i++){
        tc[i]=new int[n];
    }
    //initialize the first thro
    for(j=0;j<n;j++){
        tc[0][j]=cost[0][j];
    }
    for(i=1;i<n;i++){
        for(j=0;j<n;j++){
            if(j==0){
                tc[i][j]=cost[i][j]+min(tc[i-1][j],tc[i-1][j+1]);
            }
            else if(j==n-1){
                tc[i][j]=cost[i][j]+min(tc[i-1][j],tc[i-1][j-1]);
            }
            else
                tc[i][j]=cost[i][j]+min(tc[i-1][j],min(tc[i-1][j-1],tc[i-1][j+1]));
        }
    }
    // for(i=0;i<n;i++){
    //     for(j=0;j<n;j++){
    //         cout<<tc[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int ans=INT_MAX;
    for(j=0;j<n;j++){
        ans=min(ans,tc[n-1][j]);
    }
    return ans;
}

int main()
{
    fast;
    int n;
    cin>>n;
    int **a=new int*[n];
    for(int i=0;i<n;i++){
        a[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<minCost(a,n);
    return 0;
}