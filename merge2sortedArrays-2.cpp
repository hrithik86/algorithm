// Merge two sorted array without extra space: O((n+m)*log(n+m))
// Reference: Youtube: Striver(take U forward)
#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[],int arr2[],int n,int m){
    bool breakCondition=false;
    for(int gap=ceil((n+m)/2);gap>=1;gap=ceil(gap*1.0/2*1.0)){
        if(gap==1){
            breakCondition=true;
        }
        int i=0,j=gap;
        bool inFirst=false;

        // Both i and j in first array
        while(i<n && j<n){
            inFirst=true;
            if(arr1[i]>arr1[j]){
                swap(arr1[i],arr1[j]);
            }
            i++;j++;
        }

        // Now, j is in second array and i is in first array
        if(inFirst) j=0;
        else j=gap-n;

        while(i<n && j<m){
            if(arr1[i]>arr2[j]){
                swap(arr1[i],arr2[j]);
            }
            i++;j++;
        }

        // In third array
        i=0;
        while(i<m && j<m){
            if(arr2[i]>arr2[j]){
                swap(arr2[i],arr2[j]);
            }
            i++;j++;
        }
        // cout<<gap<<" : ";
        // for(int I=0;I<n;I++) cout<<arr1[I]<<" ";
        // for(int I=0;I<m;I++) cout<<arr2[I]<<" ";
        // cout<<"\n";
        if(breakCondition) break;
    }
}

int main() {
    int arr1[]={7, 9, 9, 10, 11, 11, 13, 14 ,17, 19};
    int arr2[]={1, 1, 4, 5, 8, 11, 13, 16, 19, 19};
    int n=10;
    int m=10;
    merge(arr1,arr2,n,m);
}
