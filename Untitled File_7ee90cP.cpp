//a^b using recursion
#include <iostream>
using namespace std;

int power(int a,int b){
   if(b==0){
       return 1;
   }
   int smallpower=power(a,b/2);
   if(b&1){                             //conditon for odd power
       return a*smallpower*smallpower;
   }
   else
        return smallpower*smallpower;    
}

int main()
{   int a,b,res;
    cin>>a>>b;
    res=power(a,b);
    cout<<res;
    return 0;
}
