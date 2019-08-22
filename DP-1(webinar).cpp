//DP-1(Webinar)
//Fibonacii number
#include <bits/stdc++.h>
using namespace std;
#define um map<int,int>

//top Down Approach (Recursion with memoization)
int fib(int n,um &mp){
    if(n==1){
        mp[1]=1;
        return 1;    
    }
    if(n==0){
        mp[0]=0;
        return 0;    
    }
    else{
        map<int, int>::iterator it ;
        it = mp.find(n);
        if(it == mp.end()){
            mp[n]=fib(n-1,mp)+fib(n-2,mp);
        } 
        return mp[n];
    }
}

//Bottom Up Approach (Iterative approach)
int fibBottomUp(int n){
    int *dp=new int[n];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
    um mp;
    for(int i=0;i<10;i++){
        cout<<fib(i,mp)<<endl;    
    }
    cout<<endl;
    cout<<fibBottomUp(5);
    return 0;
}
