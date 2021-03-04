// Kth smallest element in O(n) using randomized Quick Sort

#include <bits/stdc++.h>
using namespace std;

int partition(int a[],int low,int high){
    int s=low;
    for(int i=low;i<high;i++){
        if(a[i]<a[high]){
            swap(a[i],a[s]);
            s++;
        }    
    }
    swap(a[s],a[high]);
    return s;
}

// Choosing a random pivot element
int RandomPartition(int a[],int low,int high){
    int n=high-low+1;
    int pivot=rand()%n;
    swap(a[low+pivot],a[high]);
    return partition(a,low,high);
}

int quicksort(int a[],int low,int high,int k){
    if(low>high) return INT_MAX;
    int index=RandomPartition(a,low,high);
    if(index>k){
        return quicksort(a,low,index-1,k);
    }
    else if(index<k){
        return quicksort(a,index+1,high,k);
    }
    else return a[index];
}

int main() {
    int a[]={5,6,8,3,1};
    int  n=sizeof(a)/sizeof(a[0]);
    int k=2;
    cout<<quicksort(a,0,n-1,k-1);
}
