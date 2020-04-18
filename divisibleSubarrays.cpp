/*
Divisible Subarrays

You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.

Input Format
The first line contains the number of test cases T. First line of each test case contains an integer N denoting the number of elements. Second line of each test case contains N integers, a1, a2, a3….aN, where ai denotes the ith element of the array.

Constraints
1<=T<=10
1<=N<=10^5
|ai|<=10^9

Output Format
Output a single integer denoting the number of good sub-arrays.

Sample Input
2
5
1 1 1 1 1
5
5 5 5 5 5
Sample Output
1
15
Explanation
In first test case, there is only one sub-array [1, 1, 1, 1, 1], such that 1+1+1+1+1=5, which is divisible by N=5
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		ll pre[n];
		pre[0]=a[0];
		for(ll i=1;i<n;i++){
			pre[i]=a[i]+pre[i-1];
		}
		for(ll i=0;i<n;i++){
			pre[i]%=n;
			pre[i]=(pre[i]+n)%n;
		}
		ll freq[n];
		for(ll i=0;i<n;i++) freq[i]=0;
		for(ll i=0;i<n;i++){
			freq[pre[i]]+=1;
		}
		ll ans=0;
		freq[0]++;
		for(ll i=0;i<n;i++){
			if(freq[i]>=2){
				if(freq[i]&1){
					ans+=(freq[i]*((freq[i]-1)/2));
				}
				else
					ans+=((freq[i]/2)*(freq[i]-1));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}