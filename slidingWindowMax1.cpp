//Sliding Window Maximum (Maximum of all subarrays of size k)
//Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
#include <bits/stdc++.h>
using namespace std;

int max(queue<int>q){
    int n=q.size();
    int i=0,a[n];
    while(!q.empty()){
        a[i]=q.front();
        q.pop();
        i++;
    }
    sort(a,a+n);
    return a[n-1];
}

void kSubarrMax(int a[],int n,int k){
    queue<int>q;vector<int>v;
    if(n>=k){
        for(int i=0;i<k;i++){
            q.push(a[i]);
        }
    }
    else    return;
    for(int i=k;i<=n;i++){
        v.push_back(max(q));
        q.pop();
        q.push(a[i]);
    }
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    return;
}

int main()
{   
    int a[]={ 12, 1, 78, 90, 57, 89, 56 };
    int k=3;
    int n=sizeof(a)/sizeof(int);
    kSubarrMax(a,n,k);
    return 0;
}
