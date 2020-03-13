/*
EDIT DISTANCE
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.

Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1 <= T <= 50
1 <= P <= 100
1 <= Q <= 100

Example:
Input:
1
4 5
geek gesek

Output:
1

Explanation:
Testcase 1: One operation is required to make 2 strings same i.e. removing 's' from str2.
*/

#include <bits/stdc++.h>
using namespace std;


int minCost(string s1,string s2,int i,int j,int **dp){
    if(i==-1 && j==-1){
        return 0;
    }
    if(j==-1){
        return i+1;
    }
    if(i==-1){
        return j+1;
    }
    if(dp[i+1][j+1]!=INT_MAX){
        return dp[i+1][j+1];
    }
    if(s1[i]==s2[j]){
        if(dp[i][j]==INT_MAX){
            dp[i][j]=minCost(s1,s2,i-1,j-1,dp);
        }
        return dp[i][j];
    }
    else{
        if(dp[i][j]==INT_MAX){
            dp[i][j]= minCost(s1,s2,i-1,j-1,dp);
        }
        if(dp[i][j+1]==INT_MAX){
            dp[i][j+1]= minCost(s1,s2,i-1,j,dp);
        }
        if(dp[i+1][j]==INT_MAX){
            dp[i+1][j]= minCost(s1,s2,i,j-1,dp);
        }
        return 1+min(dp[i][j],
                    min(dp[i][j+1],dp[i+1][j])
                    );
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string s1,s2;
	    cin>>s1>>s2;
	    int **dp=new int*[n+1];
	    for(int i=0;i<=n;i++){
	        dp[i]=new int[m+1];
	        for(int j=0;j<=m;j++){
	            dp[i][j]=INT_MAX;
	        }
	    }
	    cout<<minCost(s1,s2,n-1,m-1,dp)<<"\n";
	}
	return 0;
}