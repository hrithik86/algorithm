//Modular Exponentiation(Iteratively)
#include <iostream>
#define ll long long
using namespace std;

int power(int a,int b,int M){
    ll ans=1;
    while(b!=0){
        if(b&1){
            ans=(ans*a)%M;
        }
        a=(a*a)%M;
        b=b>>1;
    }
    return int(ans);
}

int main()
{
    cout<<power(3,4,5);
    return 0;
}
