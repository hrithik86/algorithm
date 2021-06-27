// Majority element (all 3 questions)
// Video reference: Striver YT
#include <bits/stdc++.h>
using namespace std;

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.
// Leetcode
void majorityElement1(vector<int>& nums) {
    int n=nums.size();
    int ele=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(nums[i]==ele) cnt++;
        else if(cnt==0){
            ele=nums[i];
            cnt=1;
        }
        else cnt--;
    }
    cout<< ele<<"\n";
}

// Given an integer array of size n, find all elements that appear more 
// than ⌊ n/3 ⌋ times.
// Leetcode
void majorityElement2(vector<int>& nums) {
    // [...|...|...]
    // There are at max 2 majority elements 
    int n=nums.size();
    int ele1=-1,ele2=-1;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==ele1) cnt1++;
        else if(nums[i]==ele2) cnt2++;
        else if(cnt1==0){
            ele1=nums[i];
            cnt1=1;
        }
        else if(cnt2==0){
            ele2=nums[i];
            cnt2=1;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    
    vector<int>ans;
    // Checking Part
    cnt1=0;cnt2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==ele1) cnt1++;
        else if(nums[i]==ele2) cnt2++;
    }
    if(cnt1>n/3) ans.push_back(ele1);
    if(cnt2>n/3) ans.push_back(ele2);
    for(auto x:ans) cout<<x<<" ";
    cout<<"\n";
}

// You are given an array ‘ARR’ and another integer number ‘K’. 
// Your task is to find the all elements of ‘ARR’ which occur more than or equals
// to ‘N/K’ times in ‘ARR’ and ‘N’ is the length of array ‘ARR’.
// Codestudio
void majorityElement3(vector<int> &arr, int n, int k) {
	vector<int>ans;
    int ele[k];
    int cnt[k];
    for(int i=0;i<k;i++){
        ele[i]=-1;
        cnt[i]=0;
    }
    for(int i=0;i<n;i++){
        bool found=false;
        for(int j=0;j<k;j++){
            if(arr[i]==ele[j]){
                cnt[j]++;
                found=true;
                break;
            }
        }
        if(found) continue;
        for(int l=0;l<k;l++){
            if(cnt[l]==0){
                ele[l]=arr[i];
                cnt[l]=1;
                found=true;
                break;
            }
        }
        if(found) continue;
        for(int l=0;l<k;l++){
         	cnt[l]--;   
        }
    }
    for(int i=0;i<k;i++){
        int x=ele[i];
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]==x) cnt++;
        }
        if(cnt>=n/k) ans.push_back(x);
    }
    for(auto x:ans) cout<<x<<" ";
    cout<<"\n";
}

int main() {
    vector<int>v1{2, 2, 1, 1, 1, 2, 2};
    majorityElement1(v1);

    vector<int>v2{3, 2, 3};
    majorityElement2(v2);

    vector<int>v3{1, 1, 2, 1, 2, 4, 3, 4};
    majorityElement3(v3,v3.size(),4);
}
