// DP- Longest Increasing Subsequence 
#include <iostream>
#include <climits>
using namespace std;

int lis(int a[],int n){
    int *dp=new int[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }    
    }
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(dp[i]>max){
            max=dp[i];
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    return max;
}
int main()
{
    int a[]={10, 22, 9, 33, 21, 50, 41, 60};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<lis(a,n);
    return 0;
}
