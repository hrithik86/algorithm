/******************************************************************************

Factorial of a large number

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int mul(int n,int a[],int x){
    int i,carry=0;
    for(i=0;i<n;i++){
        int prod=(a[i]*x)+carry;
        a[i]=prod%10;
        carry=prod/10;
    }
    while(carry){
        a[n]=carry%10;
        carry=carry/10;
        n++;
    }
    return n;
}

int main()
{
    int n;
    cin>>n;
    int a[MAX];
    a[0]=1;
    int res_size=1;
    for(int i=2;i<=n;i++){
        res_size=mul(res_size,a,i);
    }
    for(int i=res_size-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
