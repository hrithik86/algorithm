/*Greedy Algo
Black and white ball problem
there are n black and n white balls equally spaced in a line. 
We have to connect each black ball with some one white ball with a minimum total length of wire.

Greedy approach: We will match 1st black ball with the very first white ball occuring,
and continue to do so.
*/
#include <iostream>
#include<queue>
using namespace std;

int minLen(int a[],int n){
    int i,ans=0;
    queue<int>q;
    q.push(0);
    for(i=1;i<n;i++){
        if(a[i]==a[0]){
            q.push(i);
        }
        else{
            ans=ans+(i-q.front());
            q.pop();
        }
    }
    return ans;
}

int main()
{
    int a[]={1,0,1,1,0,0};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<minLen(a,n)<<endl;
    return 0;
}
