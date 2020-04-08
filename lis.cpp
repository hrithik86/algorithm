/*
Longest Increasing Subsequence(LIS)
DP- problem
Top Down Approach(Recursion + Memoization)
*/

#include <bits/stdc++.h>
using namespace std;

int lis(int i,int *a,int n,int top,int **dp){
    if(i==n+1){
        return 0;
    }
    if(dp[i][top]!=INT_MIN){
        return dp[i][top];
    }
    if(a[i]>a[top]){
        if(dp[i+1][i]==INT_MIN)
            dp[i+1][i]=1+lis(i+1,a,n,i,dp);
    }
    if(dp[i+1][top]==INT_MIN)
        dp[i+1][top]=lis(i+1,a,n,top,dp);
    
    dp[i][top]=max(dp[i+1][i],dp[i+1][top]);
    return dp[i][top];
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int *a=new int[n+1];
	    a[0]=INT_MIN;
	    for(int i=1;i<=n;i++){
	        cin>>a[i];
	    }
	    int **dp=new int*[n+2];
	    for(int i=0;i<=n+1;i++){
	        dp[i]=new int[n+2];
	        for(int j=0;j<=n+1;j++){
	            dp[i][j]=INT_MIN;
	        }
	    }
	    cout<<lis(1,a,n,0,dp)<<"\n";
	}
	return 0;
}