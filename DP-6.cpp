/*DP
Determine the minimum number of operations to reach 1 from n if only 3 operations are allowed:
    1. Divide by 2(if divisible)
    2. Divide by 3(if divisible)
    3. Minus 1

I/P: 10
O/P: 3

Greedy appraoch:10->5->4->2->1
DP:             10->9->3->1

*/

#include <bits/stdc++.h>
using namespace std;

int waysToOne(int n){
    if(n==1){
        return 0;
    }
    int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
    if(n & 1==0){           //n is even
        op2=waysToOne(n/2);
    }
    if(n % 3==0){           //n is even
        op3=waysToOne(n/3);
    }
    op1=waysToOne(n-1);
    return min(op1,min(op2,op3))+1;
}

void waysToOneDP(int n){
    int*dp=new int[n]{0};
    for(int i=2;i<=n;i++){
        dp[i]=INT_MAX;
        if(i%2==0){
            dp[i]=min(dp[i],dp[i/2]+1);
        }
        if(i%3==0){
            dp[i]=min(dp[i],dp[i/3]+1);
        }
        dp[i]=min(dp[i],dp[i-1]+1);
    }
    cout<< dp[n];
}

int main()
{
    cout<<waysToOne(10)<<endl;
    waysToOneDP(10);
    return 0;
}
