/*
https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
DP problem: Rod cutting problem
I/P:
8
3   5   8   9  10  17  17  20
O/P:
24
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll getMaxProfit(ll n,ll a[],ll dp[]){
    if(n==0) return 0;
    if(n==1) return a[n];
    if(dp[n]!=INT_MIN){
        return dp[n];
    }
    for(ll i=1;i<=n;i++){
        if(dp[n-i]==INT_MIN){
            dp[n-i]=getMaxProfit(n-i,a,dp);
        }
        dp[n]=max(dp[n],a[i]+dp[n-i]);
    }
    return dp[n];
}

void solve(){
    ll n;
    cin>>n;
    ll a[n+1];
    ll dp[n+2];
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<=n+1;i++){
        dp[i]=INT_MIN;
    }
    cout<<getMaxProfit(n,a,dp)<<"\n";
}

int main() {
    solve();
}
