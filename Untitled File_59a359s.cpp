//fibonacci series using recursion with memoization
#include <iostream>
using namespace std;
int F[50];

int fs(int n){
    
    int res;
    if(F[n]!=-1){
        return F[n];
    }
    else{
        F[n]=fs(n-1)+fs(n-2);
        return F[n];    
    }
}

int main()
{   for(int i=0;i<50;i++){
        F[i]=-1;
    }
    F[0]=0;F[1]=1;
    int n,res;
    cin>>n;
    res=fs(n);
    cout<<res;
    return 0;
}
