// Longest commong substring
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr (string S1, string S2, int n, int m)
{
    int ans=0;
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=m;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S1[i-1]==S2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=0;
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main() {
    string s1="ABCDGH",s2="ACDGHR";
    int n=6,m=6;
    cout<<longestCommonSubstr(s1,s2,n,m);
}
