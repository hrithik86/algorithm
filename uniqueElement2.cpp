//Every element is occuring thrice except for one element 
#include <bits/stdc++.h>
using namespace std;

void findnumbers(int arr[],int n){
    int sum[4]={0},j,i,num;
    for(i=0;i<n;i++){
        j=0;
        num=arr[i];
        while(num>0){
            if(num&1){
                sum[j]++;
            }
            num=num>>1;
            j++;
        }
    }
    int req=0;
    std::reverse(std::begin(sum), std::end(sum)); 
    for(i=0;i<4;i++){
        sum[i]=sum[i]%3;
        req=req+(sum[i]*pow(2,i));
    }
    cout<<req;
    
}

int main()
{
    int arr[]={1,1,1,2,3,3,3,2,2,6,8,8,8};
    int n=sizeof(arr)/sizeof(int);
    findnumbers(arr,n);
    return 0;
}
