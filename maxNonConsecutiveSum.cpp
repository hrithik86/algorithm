// Maximum subsequence sum such that no three are consecutive: DP
// https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/

#include <bits/stdc++.h>
using namespace std;

int maxSumUtil(int a[],int n,int *dp,int i=0){
    if(i>=n) return 0;
    if(i==n-1) return a[n-1];
    if(i==n-2) return a[n-1]+a[n-2];
    if(i==n-3) return max(a[n-1]+a[n-2],max(a[n-2]+a[n-3],a[n-3]+a[n-1]));

    if(dp[i]!=INT_MIN) return dp[i];
    
    // take a[i]
    int inc1=a[i]+a[i+1]+maxSumUtil(a,n,dp,i+3);
    int inc2=a[i]+maxSumUtil(a,n,dp,i+2);

    // do not take a[i]
    int exc=maxSumUtil(a,n,dp,i+1);
    dp[i]=max(exc,max(inc1,inc2));
    return dp[i];
}

int maxSum(int a[],int n,int i=0){
    if(i>=n) return 0;
    if(i==n-1) return a[n-1];
    if(i==n-2) return a[n-1]+a[n-2];
    
    // take a[i]
    int inc1=a[i]+a[i+1]+maxSum(a,n,i+3);
    int inc2=a[i]+maxSum(a,n,i+2);

    // do not take a[i]
    int exc=maxSum(a,n,i+1);
    return max(exc,max(inc1,inc2));
}

int maxSumDP(int a[],int n){
    int *dp=new int[n];
    for(int i=0;i<n;i++) dp[i]=INT_MIN;
    return maxSumUtil(a,n,dp);
}

int main() {
    int a[]={6, 3, 3, 2};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<maxSumDP(a,n);
}
