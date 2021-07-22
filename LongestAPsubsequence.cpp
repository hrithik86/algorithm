// Leetcode: https://leetcode.com/problems/longest-arithmetic-subsequence/
// Longest Arithmetic Subsequence: DP 
// Time Complexity: O(N*N)
#include <bits/stdc++.h>
using namespace std;

int longestArithSeqLength(vector<int>& nums) {
    int n=nums.size();
    int ans=1;
    vector<unordered_map<int,int>>v(n);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int diff=nums[i]-nums[j];
            if(v[j].find(diff)==v[j].end()){
                v[i][diff]=2;
            }
            else{
                v[i][diff]=v[j][diff]+1;
            }
            ans=max(v[i][diff],ans);
        }
    }
    return ans;
}

int main() {
    vector<int>nums={9,4,7,2,10};
    cout<<longestArithSeqLength(nums);
    return 0;
}
