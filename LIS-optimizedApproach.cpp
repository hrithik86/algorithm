// Longest increasing subsequence in O(N*logN) time complexity
#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int a[])
{
    vector<int>v;
    v.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]>v.back()){
            v.push_back(a[i]);
        }
        else{
            int low=0,high=v.size()-1;
            int index=-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(v[mid]<a[i]){
                    low=mid+1;
                }
                else{
                    index=mid;
                    high=mid-1;
                }
            }
            if(index!=-1) v[index]=a[i];
        }
    }
    return v.size();
}
int main() {
    int a[]={5,8,3,7,9,1};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<longestSubsequence(n,a);
}
