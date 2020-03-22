#include <bits/stdc++.h>
using namespace std;

 bool wb(int i,string s,unordered_map<string,bool>um,int *dp){
        if(i>=s.size())
            return true;
        if(dp[i]!=INT_MAX){
            return dp[i];
        }
        string str="";
        
        dp[i]=0;
        for(int j=i;j<=s.size();j++){
            string a(1,s[j]);
            str+= a;
            if(um[str]==true){
                if(dp[j+1]==INT_MAX){
                    dp[j+1]=wb(j+1,s,um,dp);        
                }
                dp[i]=dp[i] or dp[j+1];
                if(dp[i]) return true;
            }
        }
        return dp[i];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>um;
        int n=wordDict.size();
        for(int i=0;i<n;i++){
            um[wordDict[i]]=true;
        }
        int *dp=new int[s.size()+1];
        for(int i=0;i<=s.size();i++){
            dp[i]=INT_MAX;
        }
        if(wb(0,s,um,dp)) return true;
        else return false;
    }

int main()
{   
    string s,a;
    cin>>s;
    int n;
    cin>>n;
    vector<string>v;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    if(wordBreak(s,v)){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    return 0;
}