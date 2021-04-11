// Merge 2 sorted array without extra space: O(n*m) time complexity

#include <bits/stdc++.h>
using namespace std;

void insertion(int arr2[],int j,int m){
    while(j<m-1 && arr2[j]>arr2[j+1]){
        swap(arr2[j],arr2[j+1]);
        j++;
    }
}

//Function to merge the arrays.
void mergeArray(int arr1[], int arr2[], int n, int m) 
{ 
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(arr1[i]>arr2[j]){
            swap(arr1[i],arr2[j]);
            insertion(arr2,j,m);
        }
        i++;
    }
} 

int main() {
    int arr1[] = { 1, 3, 5, 7 };
    int arr2[] = { 0, 2, 6, 8, 9 };
    int n = 4, m = 5;
    mergeArray(arr1, arr2, n, m);
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    for(int i=0;i<m;i++) cout<<arr2[i]<<" ";
    return 0;
}
