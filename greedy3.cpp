//Greedy Algo
//Biased standings(SPOJ problem)
//https://www.spoj.com/problems/BAISED/

#include <bits/stdc++.h>
using namespace std;
#define ll long long


//O(nlog n) approach
// int main()
// {
//     ll t;
//     cin>>t;
//     while(t--){
//         vector<ll>v;
//         ll n,i,ans=0;
//         cin>>n;
//         for(i=0;i<n;i++){
//             string str;ll num;
//             cin>>str>>num;
//             v.push_back(num);
//         }
//         sort(v.begin(),v.end());
//         for(i=0;i<v.size();i++){
//             ans=ans+(abs(v[i]-i-1));
//         }
//         cout<<ans<<"\n";
//     }
//     return 0;
// }

//O(n) approach
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,i,ans=0;
        cin>>n;
        ll a[n+1]={0};
        for(i=0;i<n;i++){
            string str;ll num;
            cin>>str>>num;
            a[num]++;
        }
        ll rank =1;
        for(i=1;i<=n;i++){
            while(a[i]!=0){
                ans=ans+(abs(rank-i));
                rank++;
                a[i]--;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
