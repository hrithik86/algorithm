/******************************************************************************

Total Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//Simple approach : O(n^2)
int totalHammingDistance1(vector<int>nums){
    int ans=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            ans+=__builtin_popcount(nums[i] ^ nums[j]);
        }
    }
    return ans;
}


//Efficient approach
int totalHammingDistance(vector<int> nums) {
        if(nums.size()<=1) return 0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int ans=0;
        int maxBitPosition=1+log2(maxi);
        while(maxBitPosition--){
            int count1=0,count0=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]&1){
                    count1++;
                }
                else count0++;
                nums[i]>>=1;
            }
            ans+=(count1*count0);
        }
        return ans;
    }

int main()
{
    int n;
    cin>>n;
    int x;
    vector<int>v;
    for(int i=0;i<n;i++){ 
        cin>>x;
        v.push_back(x);
    }
    cout<<totalHammingDistance(v);
    cout<<totalHammingDistance1(v);
    return 0;
}
