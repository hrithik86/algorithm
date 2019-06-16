//finding unique element in an array in which all other elements occur twice by XORing.
#include <iostream>
using namespace std;

int main()
{
    int arr[]={2,3,5,6,6,3,2};
    int n=sizeof(arr)/sizeof(int);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    cout<<ans;
    return 0;
}
