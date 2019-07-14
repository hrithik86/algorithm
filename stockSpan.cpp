//stock span problem
#include <bits/stdc++.h>
using namespace std;

void stockSpan(int a[],int n,stack<int>s){
    //pushing index of the 1st element
    vector<int>span;
    s.push(0);
    span.push_back(1);
    for(int i=1;i<n;i++){
        while(!s.empty() && a[s.top()] <= a[i]) 
            s.pop();
        if(s.empty()){
            span.push_back(i+1);
        }
        else    span.push_back(i-s.top());
        s.push(i);
    }
    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
    return;
} 

int main()
{
    stack<int>s;
    int a[]={1,5,17,2,6,3,9,4};
    int n=sizeof(a)/sizeof(int);
    stockSpan(a,n,s);
    return 0;
}
