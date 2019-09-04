//finding prime nos. between 1 to n
//Sieve of Eratosthenes

#include <iostream>
using namespace std;

//O(n*n) approach
bool checkPrime1(int num){
    int countFactors=0;
    for(int i=1;i<=num;i++){
        if(num%i==0){
            countFactors++;
        }
    }
    if(countFactors==2)
        return true;
    return false;
}
void printPrime1(int n){
    int count=0;
    for(int i=2;i<=n;i++){
        if(checkPrime1(i)){
            count++;
            cout<<i<<" ";
        }
    }
    cout<<"\nCount="<<count<<endl;
}

//O(n * root n) approach
bool checkPrime2(int num){
    int countFactors=0;
    for(int i=1;i*i<=num;i++){
        if(num%i==0){
            if(i*i==num){
                countFactors+=1;
            }
            else
                countFactors+=2;
        }
    }
    if(countFactors==2)
        return true;
    return false;
}
void printPrime2(int n){
    int count=0;
    for(int i=2;i<=n;i++){
        if(checkPrime2(i)){
            count++;
            cout<<i<<" ";
        }
    }
    cout<<"\nCount="<<count<<endl;
}

//Sieve of Eratosthenes(best approach)
void sieveOfEratosthenes(int n){
    int count=0;
    bool *arr=new bool[n+1];
    arr[0]=arr[1]=false;
    for(int i=2;i<=n;i++){
        arr[i]=true;
    }
    for(int i=2;i*i<=n;i++){
        if(!arr[i]){
            continue;
        }
        for(int j=i*i;j<=n;j=j+i){
            arr[j]=false;
        }
    }
    for(int i=0;i<=n;i++){
        if(arr[i]){
            cout<<i<<" ";
            count++;
        }
    }
    cout<<"\nCount="<<count<<endl;
}


int main()
{
    int n=100;
    printPrime1(n);
    printPrime2(n);
    sieveOfEratosthenes(n);
    return 0;
}
