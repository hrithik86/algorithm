/*
Weighted Job Scheduling in O(n Log n) time
Given N jobs where every job is represented by following three elements of it.

Start Time
Finish Time
Profit or Value Associated

Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200

Sample Output
250

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct job{
	ll s;
    ll e;
    ll pro;
};


bool compare(job a1,job a2){
    if(a1.e<a2.e){
        return true;
    }
    return false;
}

ll search(job a[],ll index){
        ll mid,high=index-1,low=0;
        while(low<=high){
            mid=(low+high)/2;
            if(a[mid].e<=a[index].s){
                if(a[mid+1].e<=a[index].s){
                    low=mid+1;
                }
                else{
                    return mid;
                }
            }
            else{
                high=mid-1;
            }
        }
    return -1;
}

int main()
{
    ll n;
    cin>>n;
    job a[n];
	for(ll i=0;i<n;i++){
    	ll x,y,z;
        cin>>x>>y>>z;
        a[i].s=x;
        a[i].e=y;
        a[i].pro=z;
    }    
    sort(a,a+n,compare);
    ll dp[n];
    dp[0]=a[0].pro;
    for(ll i=1;i<n;i++){
        //including this job
        ll inc=a[i].pro;
		ll ans=search(a,i);
        if(ans!=-1){
            inc+=dp[ans];
        }
        //excluding this job
        ll exc=dp[i-1];
        dp[i]=max(inc,exc);
    }
    ll ans=dp[n-1];
    cout<<ans<<"\n";
    return 0;
}