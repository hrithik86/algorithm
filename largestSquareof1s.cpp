/*
Largest square of 1s formed in a matrix
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n and m,n is the number of rows and m is the number of columns.
The second line of each test case contains array C[n][m] in row major form.

Output:

Print maximum size square sub-matrix.

Constraints:

1 ≤ T ≤ 100
1 ≤ n,m ≤ 50
0 ≤ C[n][m] ≤ 1

Example:

Input:
3
5 6
0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1
2 2
1 1 1 1
2 2
0 0 0 0

Output:
3
2
0
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int mat[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>mat[i][j];
	        }
	    }
	    int dp[n][m];
	    for(int j=0;j<m;j++){
	        dp[0][j]=mat[0][j];
	    }
	    for(int i=0;i<n;i++){
	        dp[i][0]=mat[i][0];
	    }
	    for(int i=1;i<n;i++){
	        for(int j=1;j<m;j++){
	            if(mat[i][j]==1){
	               dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1; 
	            }
	            else dp[i][j]=0;
	        }
	    }
	    int maxSize=INT_MIN;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            maxSize=max(maxSize,dp[i][j]);
	        }
	    }
	    cout<<maxSize<<"\n";
	}
	return 0;
}