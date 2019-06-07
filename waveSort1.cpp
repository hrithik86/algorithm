//Wave Sort Method 1
#include <iostream>
using namespace std;

int main()
{   
    int n ,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) {
        if(i&1){
            if(a[i-1]<a[i]){
                swap(a[i-1],a[i]);
            }
            
        }
        else{
            if(a[i-1]>a[i]){
            swap(a[i-1],a[i]);
            }
        }
    }
    for(i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
