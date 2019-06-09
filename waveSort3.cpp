//Wave Sort: Method 3(most efficient)
#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int n ,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i=i+2){
        if(i>0 && a[i-1]>a[i]){
            swap(a[i-1],a[i]);
        }
        if(i<n-1 && a[i+1]>a[i]){
            swap(a[i+1],a[i]);
        }
    }
    for(i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
