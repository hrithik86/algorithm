/******************************************************************************
Wildcard Matching Problem - Leetcode
TOP DOWN SOLUTION

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

    bool find(string s,string p,int i,int j,int **dp){
        //base cases
        if(i==-1 && j==-1){
            return true;
        }
        if(j<0 && i>=0){
            return false;
        }
        if(i<0 && j>=0){
            //2 cases
            for(int m=0;m<=j;m++){
                if((p[m]>=97 && p[m]<=122) || p[m]=='?'){
                    return false;
                }
            }
            return true;
        }

        if((s[i]!=p[j]) && (p[j]!='*' && p[j]!='?')){
            return false;
        }
        else if(s[i]==p[j]){
            if(dp[i][j]==INT_MAX){
                dp[i][j]=find(s,p,i-1,j-1,dp);
            }
            return dp[i][j];
        }
        else if(p[j]=='?'){
            if(dp[i][j]==INT_MAX){
                dp[i][j]=find(s,p,i-1,j-1,dp);
            }
            return dp[i][j];
        }
        else{
            if(dp[i][j+1]==INT_MAX){
                dp[i][j+1]=find(s,p,i-1,j,dp);
            }
            if(dp[i+1][j]==INT_MAX){
                dp[i+1][j]=find(s,p,i,j-1,dp);
            }
            return (dp[i][j+1] || dp[i+1][j]);
        }
    }
    bool isMatch(string s, string p) {
        int **dp=new int*[s.size()+1];
        for(int i=0;i<=s.size();i++){
            dp[i]=new int[p.size()+1];
            for(int j=0;j<=p.size();j++){
                dp[i][j]=INT_MAX;
            }
        }
        return find(s,p,s.size()-1,p.size()-1,dp);
    }

int main()
{
    string s,p;
    cin>>s>>p;
    if(isMatch(s,p)){
        cout<<"true";
    }
    else cout<<"false";
    return 0;
}
