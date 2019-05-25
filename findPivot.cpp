//binary Search
//Pivot element in sorted and rotated array
#include <iostream>
using namespace std;

void pivotPt(int arr[],int s,int e,int midindex,int res){
    midindex=(s+e)/2;
    if(s>=e){
        cout<<"Pivoting at index:"<<res;
        return;
    }
    if(arr[midindex]>arr[midindex+1]){
        res=midindex;
    }
    if(arr[midindex]<arr[midindex-1]){
        res=midindex-1;
    }
    if(arr[midindex]>arr[s]){
        s=midindex+1;
    }
    else if(arr[midindex]<arr[e]){
        e=midindex-1;
    }
    pivotPt(arr,s,e,midindex,res);
}

int main()
{   
    int arr[]={5,6,7,8,9,10,11,1,2,3};
    int n=sizeof(arr)/sizeof(int);
    int res,midindex,s=0,e=n-1;
    pivotPt(arr,s,e,midindex,res);
    return 0;
}
