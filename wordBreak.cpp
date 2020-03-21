/******************************************************************************

WORD BREAK leetcode

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

    bool wb(int i,string s,unordered_map<string,bool>um){
        if(i>=s.size())
            return true;
        string str="";
        bool ans=false;
        for(int j=i;j<=s.size();j++){
            string a(1,s[j]);
            str+= a;
            if(um[str]==true){
                cout<<str<<" ";
                bool ansMila=wb(j+1,s,um);
                ans=ans or ansMila;
                if(ans) return true;
            }
        }
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>um;
        int n=wordDict.size();
        for(int i=0;i<n;i++){
            um[wordDict[i]]=true;
        }
        if(wb(0,s,um)) return true;
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
