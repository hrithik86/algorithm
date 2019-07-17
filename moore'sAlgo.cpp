//majority element
//Using Moore’s Voting Algorithm
#include <bits/stdc++.h>
using namespace std;

int findCandidate(int a[],int n){
    int count=1,maj_index=0;
    for(int i=1;i<n;i++){
        if(a[i]==a[maj_index])  
            count++;
        else    
            count--;
        if(count==0){
            maj_index=i;
            count=1;
        }
    }
    return a[maj_index];
} 

bool isMajority(int a[],int n,int cand){
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]==cand)
            count++;
    }
    return (count>n/2)?true:false;
}

int main()
{
    int a[]={1, 1, 2, 1, 3, 5, 1};
    int n=sizeof(a)/sizeof(int);
    int cand=findCandidate(a,n);
    if(isMajority(a,n,cand)){
        cout<<cand<<endl;
    }
    else    cout<<"no majority element";
    return 0;
}
