/*
Find the smallest positive number missing from an unsorted array
O(n) time and O(1) extra space solution */
#include <bits/stdc++.h>
using namespace std;

int segregate(int a[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(a[i]<=0){
            swap(a[i],a[j]);
            j++;
        }
    }
    return j;
}

int findMissingNumber(int a[],int n){
    for(int i=0;i<n;i++){
        if(abs(a[i])-1<n && a[abs(a[i])-1]>0){
            a[abs(a[i])-1]=-a[abs(a[i])-1];
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]>0){
            return i+1;
        }
    }
    return n+1;
}

int findMissing(int a[],int n){
    int seg=segregate(a,n);
    return findMissingNumber(a+seg,n-seg);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findMissing(arr,n);
}
