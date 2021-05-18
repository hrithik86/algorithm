// https://www.spoj.com/problems/EKO/
// Binary Search Problem
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll numOfTreesCut(ll a[],ll n,ll mid){
    ll ans=0;
    for(int i=0;i<n;i++){
        if(a[i]<=mid) continue;
        ans+=a[i]-mid;
    }
    return ans;
}

int main() {
    ll n,m;
    cin>>n>>m;
    ll a[n];
    ll low=0,high=INT_MIN;
    for(ll i=0;i<n;i++){ 
        cin>>a[i];
        high=max(high,a[i]);
    }
    ll ans=0;
    while(low<=high){
        ll mid=low+(high-low)/2;
        ll x=numOfTreesCut(a,n,mid);
        if(x>=m){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<<ans;
}
