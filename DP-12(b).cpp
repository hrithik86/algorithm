/*
Question Link: http://codeforces.com/contest/1389/problem/B
TOP DOWN APPROACH (Recursion+Memoization)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll move(ll index,ll z,ll last,ll k,ll n,ll a[],ll dp[][7][2]){
    if(index<0 || k<0 || index>=n){
        return 0;
    }
    if(dp[index+1][z+1][last]!=INT_MIN){
        return dp[index+1][z+1][last];
    }
    ll leftans=INT_MIN,rightans=INT_MIN;
    if(z>0 && last==0){
        if(dp[index][z][1]==INT_MIN){
            dp[index][z][1]=move(index-1,z-1,1,k-1,n,a,dp);
        }
        leftans=a[index]+dp[index][z][1];
    }
    if(dp[index+2][z+1][0]==INT_MIN){
        dp[index+2][z+1][0]=move(index+1,z,0,k-1,n,a,dp);
    }
    rightans=a[index]+dp[index+2][z+1][0];
    dp[index+1][z+1][last]= max(leftans,rightans);
    return dp[index+1][z+1][last];
}

void solve(){
    ll n,k,z;
    cin>>n>>k>>z;
    ll a[n];
    ll dp[n+2][7][2];
    for(ll i=0;i<n+2;i++){
        for(ll j=0;j<7;j++){
            for(ll x=0;x<2;x++){
                dp[i][j][x]=INT_MIN;
            }
        }
    }
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<move(0,z,0,k,n,a,dp);
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}
