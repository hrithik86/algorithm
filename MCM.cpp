#include <bits/stdc++.h>
using namespace std;

//Recursive
int mcm(int a[],int i,int j){
    if(i==j) return 0;
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int mul=mcm(a,i,k)+mcm(a,k+1,j)+(a[i-1]*a[j]*a[k]);
        if(mul<ans){
            ans=mul;
        }
    }
    return ans;
}

//Top Down
int mcmTopDown(int a[],int i,int j,int **dp){
    if(i==j) return 0;
    if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }
    for(int k=i;k<j;k++){
        if(dp[i][k]==INT_MAX){
            dp[i][k]=mcmTopDown(a,i,k,dp);
        }
        if(dp[k+1][j]==INT_MAX){
            dp[k+1][j]=mcmTopDown(a,k+1,j,dp);
        }
        int mul=dp[i][k]+dp[k+1][j]+(a[i-1]*a[j]*a[k]);
        dp[i][j]=min(dp[i][j],mul);
    }
    return dp[i][j];
}

int main() {
    int a[]={1, 2, 3, 4, 3};
    int n=sizeof(a)/sizeof(a[0]);
    int **dp=new int*[n];
    for(int i=0;i<n;i++){
        dp[i]=new int[n];
        for(int j=0;j<n;j++){
            dp[i][j]=INT_MAX;
        }
    }
    cout<<mcm(a,1,n-1)<<"\n";
    cout<<mcmTopDown(a,1,n-1,dp)<<"\n";
    
}
