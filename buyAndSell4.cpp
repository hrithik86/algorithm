// Best Time to Buy and Sell Stock IV: Leetcode
// Reference: Pepcoding
#include <bits/stdc++.h>
using namespace std;

// O(n*n*k) approach
int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    if(n==0) return 0;
    int **dp=new int*[k+1];
    for(int i=0;i<=k;i++){
        dp[i]=new int[n];
        for(int j=0;j<n;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<n;j++){
            int mx=0;
            for(int pd=0;pd<j;pd++){
                mx=max(mx,dp[i-1][pd]+prices[j]-prices[pd]);
            }
            dp[i][j]=max(dp[i][j-1],mx);
        }
    }
    return dp[k][n-1];
}

// O(n*k) approach: Optimized version of the above approach
int maxProfitOptimized(int k, vector<int>& prices) {
    int n=prices.size();
    if(n==0) return 0;
    int **dp=new int*[k+1];
    for(int i=0;i<=k;i++){
        dp[i]=new int[n];
        for(int j=0;j<n;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    for(int i=1;i<=k;i++){
        int mx=INT_MIN;
        for(int j=1;j<n;j++){
            mx=max(mx,dp[i-1][j-1]-prices[j-1]);
            dp[i][j]=max(dp[i][j-1],mx+prices[j]);
        }
    }
    return dp[k][n-1];
}

int main() {
    vector<int>v{3,2,6,5,0,3};
    int k=2;
    cout<<maxProfit(k,v)<<" ";
    cout<<maxProfitOptimized(k,v);
    return 0;
}
