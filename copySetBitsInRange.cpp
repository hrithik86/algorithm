// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/bit-manipulation/copy-set-bits-in-a-range-official/ojquestion
/* Input: a=10, b=13, l=2, r=3
Output: 15
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void copySetBits(){
    ll a,b,l,r;
    cin>>a>>b>>l>>r;
    ll mask1=1<<(r-l+1);
    mask1--;
    mask1=mask1<<(l-1);
    ll mask2=(a&mask1);
    b=(b|mask2);
    cout<<b;
}

int main(){
    copySetBits();
    return 0;
}