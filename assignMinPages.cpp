#include <iostream>
using namespace std;

int minPages(int arr[],int m,int n,int start,int end){
    int i,mid,j,ans;
    while(start<=end){
        i=0;
        int s[m]={0};
        mid=(start+end)/2;
        for(j=0;j<m;j++){
            while(s[j]+arr[i]<=mid){
                s[j]=s[j]+arr[i];
                i++;
                if(i==n){
                    break;
                }
            }
        }
        if(i<n){
            start=mid+1;
        }
        else {
            end=mid-1;
            ans=mid;
        }
    }
    return ans;
}

int main()
{
    int m,n,i,sum=0;
    cin>>m>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        sum=sum+arr[i];
    }
    int start=0,end=sum;
    int ans=minPages(arr,m,n,start,end);
    cout<<endl;
    cout<<ans;
    return 0;
}
