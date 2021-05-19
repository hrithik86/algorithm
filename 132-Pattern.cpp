// https://leetcode.com/problems/132-pattern/
#include <bits/stdc++.h>
using namespace std;

// O(n) approach by constructing prefix minimum element  
// array for ith index and previousGreater element using
//  stack for jth index and iterating for k
bool find132pattern(vector<int>& nums) {
    int n=nums.size();
    int minElement[n];
    minElement[0]=nums[0];
    for(int i=1;i<n;i++) 
        minElement[i]=min(minElement[i-1],nums[i]);
    int previousGreater[n];
    for(int i=0;i<n;i++) previousGreater[i]=-1;
    stack<int>s;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            s.push(i);
            continue;
        }
        if(nums[i]<=nums[s.top()]){
            s.push(i);
        }
        else{
            while(!s.empty() && nums[s.top()]<nums[i]){
                int index=s.top();
                s.pop();
                previousGreater[index]=i;
            }
            s.push(i);
        }
    }
    for(int k=n-1;k>=2;k--){
        int j=previousGreater[k];
        if(j==-1 || j==0) continue;
        int iValue=minElement[j-1];
        if(iValue<nums[k] && nums[k]<nums[j]) return true;
    }
    return false;
}
int main() {
    vector<int>v{3,1,4,2};
    cout<<find132pattern(v);
}
