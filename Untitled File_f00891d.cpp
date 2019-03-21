#include <iostream>
using namespace std;

int power(int a,int b){
    //base case
    if(b==0)
    return 1;
    //recursive case
    int res=a*power(a,b-1);
    return res;
}

int main()
{   int a,b;
    cin>>a>>b;
    int res= power(a,b);
    cout<<res;
    return 0;
}
