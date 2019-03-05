//fibonacci series using recursion
#include <iostream>
using namespace std;

int fs(int n){
    int res;
        if(n==0||n==1){
        return n;
    }
    else{
        res=fs(n-1)+fs(n-2);
        return res;    
    }
}

int main()
{   int n,res;
    cin>>n;
    res=fs(n);
    cout<<res;
    return 0;
}
