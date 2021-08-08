// Leetcode: 128. Longest Consecutive Sequence 
// O(N) TC
// Reference: Take U forward (Striver)
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.size()==0) return 0;
    unordered_map<int,int>um;
    int ans=1;
    for(auto x:nums) um[x]++;
    for(auto x:nums){
        if(um.find(x-1)==um.end()){
            int start=x;
            while(um.find(start)!=um.end()){
                start++;
            }
            ans=max(ans,start-x);
        }
    }
    return ans;
}

int main() {
    vector<int>nums{100,4,200,1,3,2};
    cout<<longestConsecutive(nums);
}
