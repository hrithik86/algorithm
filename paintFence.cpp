// Paint the fence: DP
#include <bits/stdc++.h>
using namespace std;

int numWays(int n, int k) {
    long long same[n+1]={0};
    long long diff[n+1]={0};
    if(n==1) return k;
    same[2]=k;
    diff[2]=k*(k-1); 
    for(int i=3;i<=n;i++){
        same[i]=diff[i-1];
        diff[i]=(same[i-1]+diff[i-1])*(k-1);
    }
    return (same[n]+diff[n]);
}
int main() {
    int n=3,k=2;
    cout<<numWays(n,k);
    return 0;
}
