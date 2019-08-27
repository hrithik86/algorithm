//Wine and maximum price
#include <iostream>
using namespace std;


//RECURSION : Time complexity O(2^n)
int maxProfit(int a[],int i,int j,int day){
    if(i==j){
        return a[i]*day;
    }
    int takeLeft=(day*a[i])+maxProfit(a,i+1,j,day+1);
    int takeRight=(day*a[j])+maxProfit(a,i,j-1,day+1);
    return max(takeLeft,takeRight);
}

// int maxProfitDP(int a[],int n){
//     int i,j,dp[100][100];
//     for(i=0;i<n;i++){
//         for(j=0;j<n;j++){
//             if(i==j){
//                 dp[i][j]=a[i]*n;
//             }
//         }
//     }
//     for(i=0;i<n;i++){
//         for(j=0;j<n;j++){
//             if(j>i){
//                 int day=n-j;
//                 dp[i][j]=max(((day*a[i])+dp[i+1][j]),((day*a[j])+dp[i][j-1]));
//             }
//         }
//     }
//     for(i=0;i<n;i++){
//         for(j=0;j<n;j++){
//             cout<<dp[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return dp[0][n-1] ;
// }

int main()
{
    int a[]={2, 4, 6, 2, 5};
    int n=sizeof(a)/sizeof(a[0]);
    int i=0,j=n-1,day=1;
    cout<<maxProfit(a,i,j,day)<<endl; 
    // cout<<maxProfitDP(a,n);
    return 0;
} 
