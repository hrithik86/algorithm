// Maximum Sum Path in Two Arrays
#include <bits/stdc++.h>
using namespace std;

int max_path_sum(int A[], int B[], int n, int m)
{
    int sum1=0;
    int sum2=0;
    int ans=0;
    int i=0,j=0;
    while(i<n && j<m){
        if(A[i]>B[j]){
            sum2+=B[j];
            j++;
        }
        else if(A[i]<B[j]){
            sum1+=A[i];
            i++;
        }
        else{
            ans+=max(sum1,sum2)+A[i];
            i++;j++;
            sum1=0;
            sum2=0;
        }
    }
    while(i<n){
        sum1+=A[i];
        i++;
    }
    while(j<m){
        sum2+=B[j];
        j++;
    }
    ans+=max(sum1,sum2);
    return ans;
}

int main() {
    int A[]={2, 3, 7, 10, 12};
    int B[]={1, 5, 7, 8};
    int n=sizeof(A)/sizeof(A[0]);
    int m=sizeof(B)/sizeof(B[0]);
    cout<<max_path_sum(A,B,n,m);
}
