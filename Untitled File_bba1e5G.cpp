//factorial of a number using recursion

#include <iostream>
using namespace std;

int fact(int n){
    int res;
    if(n==1){
        return 1; 
    }
    else{
        res=n*fact(n-1);
        return res;
    }
}

int main()
{   int n;
    cin>>n;
    int res=fact(n);
    cout<<res;
    return 0;
}
