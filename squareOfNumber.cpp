// Calculate square of a number without using *, / and pow()
// gfg: https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
#include <bits/stdc++.h>
using namespace std;

// O(Log n) time complexity
int square(int n){
    if(n==0 || n==1) return n;
    int x=n>>1;
    if(n&1){
        return (square(x)<<2)+(x<<2)+1;
    }
    else{
        return square(x)<<2;
    }
}

// O(Log n) time complexity
int square1(int n){
    int ans=0;
    int num=n;
    int x=0;
    while(num>0){
        if(num&1){
            ans+=(n<<x);
        }
        x++;
        num=num>>1;
    }
    return ans;
}

int main() {
    for(int i=10;i<=15;i++){
        cout<<i<<" : "<<square(i)<<" , "<<square1(i)<<"\n";
    }
}
