/******************************************************************************

Wildcard Matching - Leetcode
DP - Bottom Up Approach

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
        bool **dp=new bool*[s.size()+1];
        for(int i=0;i<=s.size();i++){
            dp[i]=new bool[p.size()+1];
            for(int j=0;j<=p.size();j++){
                dp[i][j]=false;
            }
        }
        ///////////////////////Base cases\\\\\\\\\\\\\\\\\\\\\\\\
        
        dp[0][0]=true; //both strings empty
        
        //first row
        for(int j=0;j<p.size();j++){
            if(p[j]=='*'){
                dp[0][j+1]=true;
            }
            else break;
        }
        
        ////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\
        
        for(int i=0;i<s.size();i++){
            for(int j=0;j<p.size();j++){
                if((s[i]!=p[j]) && (p[j]!='*' && p[j]!='?')){
                    dp[i+1][j+1]=false;
                }
                else if(s[i]==p[j] || p[j]=='?'){
                    dp[i+1][j+1]=dp[i][j];
                }
                else{
                    dp[i+1][j+1]=(dp[i][j+1] || dp[i+1][j]);
                }
            }
        }
        return dp[s.size()][p.size()];
    }

int main()
{
    string s,p;
    cin>>s>>p;
    if(isMatch(s,p)) cout<<"YES";
    else cout<<"NO";
    return 0;
    
}
