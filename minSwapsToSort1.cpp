// Minimum number of swaps required to sort the array in strictly increasing order
// GFG Approach without hashmap
#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&nums){
    int n=nums.size();
    vector<pair<int,int>>sortednums;
    for(int i=0;i<n;i++) {
        sortednums.push_back({nums[i],i});
    }
    sort(sortednums.begin(),sortednums.end());
    int ans=0;
    bool vis[n]={false};
    for(int i=0;i<n;i++){
        int targetIndex=sortednums[i].second;
        if(targetIndex==i || vis[i]) continue;
        int index=i;
        int cnt=0;
        // cycle found
        while(!vis[index]){
            vis[index]=true;
            cnt++;
            index=sortednums[index].second;
        }
        ans+=(cnt-1);
    }
    return ans;
}
int main() {
    vector<int>num{4, 3, 2, 1};
    cout<<minSwaps(num);
}
