//pairs that sum to X 
//solving by sliding window approach or two pointer approach
#include <bits/stdc++.h>
using namespace std;

void findPairs(int arr[],int n,int sum){
    int s=0,l=n-1;
    while(s<l){
        if(arr[s]+arr[l]<sum){
            s++;
        }
        else if(arr[s]+arr[l]>sum){
            l--;
        }
        else{
            cout<<arr[s]<<" "<<arr[l]<<endl;
            s++;
            l--;
        }
    }
    return;
}

int main()
{
    int arr[]={-3,2,0,1,3,6,5,7,8};
    int n=sizeof(arr)/sizeof(int);
    int sum=7;
    sort(arr,arr+n);
    findPairs(arr,n,sum);
    return 0;
}
