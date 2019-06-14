//rotating a n*n image by 90 degrees CW in place
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j, a[][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int n=sqrt(sizeof(a)/sizeof(int));
    //transposing the matrix
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            swap(a[i][j],a[j][i]);
        }
    }
    //reversing each row
    for(i=0;i<n;i++){
        for(j=0;j<n/2;j++){
            swap(a[i][j],a[i][n-1-j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
   
    return 0;
}
