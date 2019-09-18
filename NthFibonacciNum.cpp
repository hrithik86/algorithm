//Nth fibonacci number in log(n) time
#include <iostream>
using namespace std;
void multiply(int A[2][2],int M[2][2]){
    int A00=A[0][0]*M[0][0]+A[0][1]*M[1][0];
    int A01=A[0][0]*M[0][1]+A[0][1]*M[1][1];
    int A10=A[1][0]*M[0][0]+A[1][1]*M[1][0];
    int A11=A[1][0]*M[0][1]+A[1][1]*M[1][1];
    A[0][0]=A00;
    A[0][1]=A01;
    A[1][0]=A10;
    A[1][1]=A11;
}
void power(int A[2][2],int k){
    if(k==0 || k==1){
        return;
    }
    power(A,k/2);
    
    //Multiplying A^n/2 with 
    multiply(A,A);
    if((k&1)){
        int M[2][2]={{1,1},{1,0}};
        multiply(A,M);
    }
}
int fib(int n){
    int A[2][2]={
        {1,1},
        {1,0}
    };
    if(n==0){
        return 0;
    }
    power(A,n-1);
    return A[0][0];
}
int main()
{
    for(int i=0;i<=10;i++)
    cout<<fib(i)<<" ";
    return 0;
}
