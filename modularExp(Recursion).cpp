//Modular Exponentiation(Recursively)
#include <iostream>
#define ll long long
using namespace std;

int power(int x,int n,int M){
    ll ans;
    if(x==0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(n&1){        //odd condition
        ll smallpower=power(x,n-1,M);
        ans=x%M;
        ans=(ans*smallpower)%M;
    }
    else{
        ll smallpower=power(x,n/2,M);
        ans=(smallpower*smallpower)%M;
    }
    return int((ans+M)%M);
}

int main()
{
    cout<<power(2,5,5);
    return 0;
}
