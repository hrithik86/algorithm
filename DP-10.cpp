//DP
//Longest common subsequence(LCS)
#include <iostream>
#include <stack>
using namespace std;

//==============================RECURSION========================================
int lcsRec(string s1,string s2,int i,int j){
    if(i<0 || j<0){
        return 0;
    }
    int ans;
    if(s1[i]==s2[j]){
        ans=1+lcsRec(s1,s2,i-1,j-1);
    }
    else{
        ans=max(lcsRec(s1,s2,i,j-1),lcsRec(s1,s2,i-1,j));
    }
    return ans;
}
//==============================================================================


//============================= DP =============================================
void lcsDP(string s1,string s2){
    stack<char>s;
    int n1=s1.size();
    int n2=s2.size();
    int i,j,dp[20][20];
    for(i=0;i<=n1;i++){
        for(j=0;j<=n2;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    for(i=1;i<=n1;i++){
        for(j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    i=n1;j=n2;
    while(i>=0 && j>=0){
        if(s1[i-1]==s2[j-1]){
            s.push(s1[i-1]);
            i=i-1;
            j=j-1;
        }
        else {
            if(dp[i-1][j]==dp[i][j]){
                i=i-1;
            }
            else{
                j=j-1;
            }
        }
    }
    cout<<"\nLength of LCS = "<<dp[n1][n2]<<endl;
    cout<<"LCS:";
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}

//==============================================================================

int main()
{
    string str1="apple";
    string str2="apen";
    // int i=str1.size()-1;
    // int j=str2.size()-1;
    // cout<<"Length of LCS is "<<lcsRec(str1,str2,i,j)<<endl;
    
    string str3 = "AGGTAB";  
    string str4 = "GXTXAYB";
    // i=str3.size()-1;
    // j=str4.size()-1;
    // cout<<"Length of LCS is "<<lcsRec(str3,str4,i,j)<<endl;
    
    lcsDP(str2,str1);
    cout<<endl;
    lcsDP(str3,str4);
    return 0;
}
