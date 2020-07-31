/*
Question Link: http://codeforces.com/contest/1389/problem/B
RECURSIVE APPROACH (gives TLE)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll move(ll index,ll z,ll last,ll k,ll n,ll a[]){
    if(index<0 || k<0 || index>=n){
        return 0;
    }
    ll leftans=INT_MIN,rightans=INT_MIN;
    if(z>0 && last==0){
        leftans=a[index]+move(index-1,z-1,1,k-1,n,a);
    }
    rightans=a[index]+move(index+1,z,0,k-1,n,a);
    return max(leftans,rightans);
}

void solve(){
    ll n,k,z;
    cin>>n>>k>>z;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<move(0,z,0,k,n,a);
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
}
