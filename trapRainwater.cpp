#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,sum=0;vector<int >right,left;
    int arr[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int size=sizeof(arr)/sizeof(int);
    int max=arr[0];
    right.push_back(max);
    for(i=1;i<size;i++){
        if(arr[i]>max){
            right.push_back(arr[i]);
            max=arr[i];
        }
        else{
            right.push_back(max);
        }
    }
    max=arr[size-1];
    left.push_back(max);
    for(i=size-2;i>=0;i--){
        if(arr[i]>max){
            left.push_back(arr[i]);
            max=arr[i];
        }
        else{
            left.push_back(max);
        }
    }
    reverse(left.begin(),left.end());
    // for(i=0;i<size;i++){
    //     cout<<right[i]<<" ";
    // }
    // cout<<endl;
    // for(i=0;i<size;i++){
    //     cout<<left[i]<<" ";
    // }
    // cout<<endl;
    for(i=0;i<size;i++){
        sum=sum+(min(right[i],left[i]))-arr[i];
    }
    cout<<sum;
    return 0;
}
