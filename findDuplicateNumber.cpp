// Find Duplicate Number in O(N) time O(1) space
// Leetcode
#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(1)
/*
    Since the numbers are [1:N], so we use the array indices for storing the
    visited state of each number, only the duplicate will be visited twice.
    For each number we goto its index position and multiply by -1. In case
    of duplicate it will be multiplied twice and the number will be +ve.
*/
int indexSolution(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        
        // mark as visited
        nums[index] *= -1;
        // incase of duplicate, this will become +ve 
        if(nums[index] > 0)
            return abs(nums[i]);
    }    
    return -1;
}
int main() {
    vector<int>nums{2,2,2,2};
    cout<<indexSolution(nums)<<" ";
    vector<int>nums1{3,4,1,4,2};
    cout<<indexSolution(nums1);
    return 0;
}
