/*
https://www.geeksforgeeks.org/constant-time-range-add-operation-array/
Constant time range add operation on an array

Initial array is zero.
Q Queries:
Increase the array values by x in range [l,r].

Output: Final array after updations.

Input:
6 3 100
0 2
1 5
2 3

Output:
100 200 300 200 100 100 

*/

#include <iostream>
using namespace std;
int main() {
    int n,q,x;
    cin>>n>>q>>x;
    int a[n+1]={0};
    while(q--){
        int l,r;
        cin>>l>>r;
        a[l]=x;
        a[r+1]=-x;
    }
    for(int i=1;i<n;i++){
        a[i]=a[i]+a[i-1];
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
