//Euclid's Algorithm: 
//To find gcd of 2 numbers

#include <iostream>
using namespace std;

int gcd(int n1,int n2){         //n1>n2
    if(n2==0){                  //gcd(n,0)=n
        return n1;
    }
    return gcd(n2,n1%n2);
}

int main()
{
    int a,b;
    cin>>a>>b;
    int x=(a>=b)?(gcd(a,b)):(gcd(b,a));
    cout<<x;
    return 0;
}
