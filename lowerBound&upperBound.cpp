//Binary Search
//finding upper bound and lower bound of an element in a sorted array
#include <iostream>
using namespace std;

int upperBound(int arr[],int n,int num){
    int ub,s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]>num){
            e=mid-1;
        }
        else if(arr[mid]<num){
            s=mid+1;
        }
        else if(arr[mid]==num){
            ub=mid;
            s=mid+1;
        }    
    }
    return ub;
}

int lowerBound(int arr[],int n,int num){
    int lb,s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]>num){
            e=mid-1;
        }
        else if(arr[mid]<num){
            s=mid+1;
        }
        else if(arr[mid]==num){
            lb=mid;
            e=mid-1;
        }    
    }
    return lb;
}

int main()
{
    int arr[]={1,3,3,3,4,5,5,5};
    int n=sizeof(arr)/sizeof(int);
    int num=5;
    int ans=lowerBound(arr,n,num);
    cout<<"Lower Bound:"<<ans<<endl;
    int ans1=upperBound(arr,n,num);
    cout<<"Upper Bound:"<<ans1;
    return 0;
}
