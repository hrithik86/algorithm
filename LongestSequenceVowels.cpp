// Longest Ordered Subsequence of Vowels
// Fun With Vowels (Hackerearth)
#include<bits/stdc++.h>
using namespace std;
char vowels[]={'a','e','i','o','u'};

int findMaxLength(string s,int n,int **dp,int i=0,int last=0){
    if(i>=n) return 0;
    if(dp[i][last]!=INT_MIN) return dp[i][last];
    int inc=0,exc=0;
    // include
    if(s[i]==vowels[last]){
        return 1+findMaxLength(s,n,dp,i+1,last);
    }
    if(last<4 && s[i]==vowels[last+1]){
        inc=1+findMaxLength(s,n,dp,i+1,last+1);
    }
    // exclude
    exc=findMaxLength(s,n,dp,i+1,last);
    dp[i][last]=max(inc,exc);
    return dp[i][last];
}

void solve(){
    string s="aeiaaioooaauuaeiu";
    int n=s.size();
    int curr=0;
    for(int i=0;i<n;i++){
        if(s[i]==vowels[curr]){
            curr++;
        }
    }
    if(curr<5){
        cout<<0;
        return;
    }
    int**dp=new int*[n];
    for(int i=0;i<n;i++){
        dp[i]=new int[5];
        for(int j=0;j<5;j++){
            dp[i][j]=INT_MIN;
        }
    }
    cout<<findMaxLength(s,n,dp);
}

int main(){
    solve();
    return 0;
}