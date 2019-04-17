//Kadane's algo

#include <iostream>
using namespace std;

void maxSubarraySum(int arr[10],int cs,int ms,int n,int i=0){
    //base case
    if(i==n){
        cout<<ms;
        return;
    }
    //recursive case
    cs=cs+arr[i];
    if(cs<0){
        cs=0;
    }
    if(cs>ms){
        ms=cs;
    }
    maxSubarraySum(arr,cs,ms,n,i+1);    
    
    
    return;
}

int main()
{
    int arr[10]={1,-2,3,4,-1,6,7,-5,8,-10};int cs=0,ms=0;
    int n=sizeof(arr)/sizeof(int);
    maxSubarraySum(arr,cs,ms,n);
    return 0;
}
