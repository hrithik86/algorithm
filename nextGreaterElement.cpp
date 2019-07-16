//next greater element problem
#include <bits/stdc++.h>
using namespace std;

void nextGreater(int a[],int n,stack<int>s){
    vector<int>v;int b[n];
    s.push(0);
    for(int i=1;i<n;i++){
        if(a[i]>a[s.top()]){
            while(!s.empty() && a[i]>a[s.top()]){
                b[s.top()]=a[i];
                s.pop();
            }
        }
        s.push(i);
    }
    while(!s.empty()){
        b[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++){
        cout<<" "<<b[i];
    }
    return;
} 

int main()
{
    stack<int>s;
    int a[]={3,4,20,6,15,2,1,7};
    int n=sizeof(a)/sizeof(int);
    nextGreater(a,n,s);
    return 0;
}
