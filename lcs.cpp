/*
Longest Common Subsequence

Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2
*/
#include <bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int i,int j,int **dp){
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i+1][j+1]!=INT_MIN){
        return dp[i+1][j+1];
    }
    if(s1[i]==s2[j]){
        if(dp[i][j]==INT_MIN){
            dp[i][j]=lcs(s1,s2,i-1,j-1,dp);
        }
        return 1+dp[i][j];
    }
    else{
        if(dp[i+1][j]==INT_MIN){
            dp[i+1][j]=lcs(s1,s2,i,j-1,dp);
        }
        if(dp[i][j+1]==INT_MIN){
            dp[i][j+1]=lcs(s1,s2,i-1,j,dp);
        }
        return max( dp[i+1][j],
                    dp[i][j+1]
                );
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n1,n2;
	    string s1,s2;
	    cin>>n1>>n2;
	    cin>>s1>>s2;
	    int **dp=new int*[n1+1];
	    for(int i=0;i<=n1;i++){
	        dp[i]=new int[n2+1];
	        for(int j=0;j<=n2;j++){
	            dp[i][j]=INT_MIN;
	        }
	    }
	    cout<<lcs(s1,s2,n1-1,n2-1,dp)<<"\n";
	}
	return 0;
}