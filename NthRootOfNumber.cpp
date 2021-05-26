// Nth root of a number with precision using Binary Search
// Reference: Striver Youtube Video
#include <bits/stdc++.h>
using namespace std;

double multiply(double number,double x){
    double ans=1;
    for(int i=0;i<x;i++){
        ans*=number;
    }   
    return ans;
}

void nthRoot(double n,double x){
    double low=1;
    double high=n;
    double eps=1e-6;
    while((high-low)>eps){
        double mid=low+(high-low)/2.0;
        if(multiply(mid,x)>n){
            high=mid;
        }
        else low=mid;
    }
    cout<<(low+high)/2.0;
}

int main() {
    int n=64,x=3;
    nthRoot(n,x);
}
