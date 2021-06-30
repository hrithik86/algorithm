// Longest valid Parentheses
#include <bits/stdc++.h>
using namespace std;

int maxLength(string S){
    stack<int>st;
    int n=S.size();
    if(n==0) return 0;
    bool isRemoved[n];
    for(int i=0;i<n;i++){
        isRemoved[i]=false;
    }
    for(int i=0;i<n;i++){
        if(st.empty() || S[i]=='('){
            st.push(i);
            continue;
        }
        if(S[st.top()]=='(') st.pop();
        else st.push(i);
    }
    while(!st.empty()){
        isRemoved[st.top()]=true;
        st.pop();
    }
    int ans=0,cnt=0;
    for(int i=0;i<n;i++){
        if(isRemoved[i]){
            ans=max(ans,cnt);
            cnt=0;
        }
        else cnt++;
    }
    ans=max(ans,cnt);
    return ans;
}

int main() {
    string s=")()())";
    cout<<maxLength(s);
}
