// Palindrome Partitioning 2: Leetcode
// Video Reference: Pepcoding
// O(n*n) Time complexity
#include <bits/stdc++.h>
using namespace std;

int palindromeUtil(string str,int *dp,bool **isPalindrome,int low=0){
    int n=str.size();
    if(low==n) return 0;
    if(dp[low]!=-1) return dp[low];
    int ans=INT_MAX;
    for(int i=low;i<n;i++){
        if(isPalindrome[low][i]){
            ans=min(ans,1+palindromeUtil(str,dp,isPalindrome,i+1));
        }
    }
    dp[low]=ans;
    return dp[low];
}

int minCut(string str) {
    int n=str.size();
    int *dp=new int[n];
    for(int i=0;i<n;i++) 
        dp[i]=-1;
    
    // isPalindrome[i][j] denotes whether 
    // str[i...j] is palindrome or not
    bool **isPalindrome=new bool*[n];
    for(int i=0;i<n;i++){
        isPalindrome[i]=new bool[n];
        for(int j=0;j<n;j++){
            if(i>j) continue;
            if(i==j)
                isPalindrome[i][j]=true;
            if(abs(j-i)==1){
                if(str[i]==str[j])
                    isPalindrome[i][j]=true;
                else isPalindrome[i][j]=false;
            }
        }
    }
    
    // For a string str[i...j] to be a 
    // palindrome, str[i]=str[j] and 
    // str[i+1...j-1] should be a palindrome
    // Diagonally fill the matrix
    for(int gap=2;gap<n;gap++){
        for(int i=0;i<n-gap;i++){
            int j=gap+i;
            if(isPalindrome[i+1][j-1] && str[i]==str[j])
                isPalindrome[i][j]=true;
            else isPalindrome[i][j]=false;
        }    
    }

    return palindromeUtil(str,dp,isPalindrome)-1;
}

int main() {
    string s="aab";
    cout<<minCut(s);
    return 0;
}
