//LCM SUM (Euler's Totient Function)
//Given n, calculate and print the sum :
//LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
//where LCM(i,n) denotes the Least Common Multiple of the integers i and n.

#include <bits/stdc++.h>
using namespace std;
typedef long long vlong;
 
vlong res[1000010];
vlong phi[1000010];
 
void precal( vlong n ) {
    vlong i,j;
    // Calculate phi from 1 to n using sieve
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
 
 
 // Calculate partial result using sieve
 // For each divisor d of n, add phi(d)*d to result array
 for(vlong i=1;i<=n;i++){
    for ( vlong j = i; j <= n; j += i ) {
        res[j] += ( i * phi[i] );
    }
 }
}


int main()
{
    int n=2;
    precal(1000000);
	vlong ans = res[n] + 1;
        ans *= n;
        ans /= 2;
    
    cout<<ans;
    return 0;
}

