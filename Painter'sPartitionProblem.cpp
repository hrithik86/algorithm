// The painter’s partition problem (Binary Search)
#include <bits/stdc++.h>
using namespace std;

bool possible(int arr[],int n,int k,int x){
    long long sum=0,reqd=1;
    for(int i=0;i<n;i++){
        if(arr[i]>x) return false;
        if(sum+arr[i]<=x){
            sum+=arr[i];
        }
        else{
            reqd++;
            sum=arr[i];
        }
    }
    if(reqd>k) return false;
    return true;
}
long long minTime(int arr[], int n, int k)
{
    long long high=0,low=0,ans=-1;
    for(int i=0;i<n;i++){
        high+=arr[i];
        if(arr[i]>low) low=arr[i];
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        //cout<<mid<<" ";
        if(possible(arr,n,k,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main() {
    int arr[]={10, 20, 30, 40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    cout<<minTime(arr,n,k);
}
