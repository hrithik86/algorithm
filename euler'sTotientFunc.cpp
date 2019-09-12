//Number Theory-2
//Euler's Totient Function
#include <iostream>
using namespace std;
void eulerPhi(int n){
    int phi[n+1],i,j;
    for(i=1;i<=n;i++){
        phi[i]=i;
    }
    for(i=2;i<=n;i++){
        if(phi[i]==i){          //prime
            phi[i]=i-1;
            for(j=i+i;j<=n;j=j+i){
                phi[j]=(phi[j]*(i-1))/i;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<phi[i]<<" ";
}
int main()
{   
    eulerPhi(10);
    return 0;
}
