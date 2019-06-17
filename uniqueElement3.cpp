//Every element is occuring twice except for exactly 2 elements in an array. Print those 2 elements.  
#include <bits/stdc++.h>
using namespace std;

void findnumbers(int arr[],int n){
	int i,res,ans=0,pos=0;
	for(i=0;i<n;i++){
        ans=ans^arr[i];
    }
    res=ans;
    //ans is not zero, so atleast 1 set bit is present which is due to either the first unique number or the second but not both.
    while(ans>0){
        if(ans&1){
            break;
        }
        ans=ans>>1;
        pos++;
    }
    int mask=1<<pos;
    int num1=0;
    //cout<<pos;	this gives the position of 1 set bit from right
    for(i=0;i<n;i++){
    	if((arr[i]&mask)!=0){
    		num1=num1^arr[i];
    	}
    }
    int num2=0; 
    num2=num1^res;
    cout<<num2<<" "<<num1;
    return;
}

int main()
{
    int arr[]={6,1,3,5,1,3,7,6};
    int n=sizeof(arr)/sizeof(int);
    findnumbers(arr,n);
    return 0;
}
