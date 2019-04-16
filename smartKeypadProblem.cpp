#include <bits/stdc++.h>
using namespace std;

void print(char s[10][10],int num[],char output[50],int n,int i=0,int j=0){
    //base case
    if(i==n){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    //skipping the numbers 1 and 0
    if(num[i]==1||num[i]==0){
        print(s,num,output,n,i+1,j);
    }
    for(int k=0;k<int(strlen(s[num[i]-1]));k++){
        output[j]=s[num[i]-1][k];
        print(s,num,output,n,i+1,j+1);
    }
    return;
}

int main()
{   char output[50];int n=4;
    int num[]={1,0,2,3};
    char s[10][10]={
        "",         //      1
        "ABC",      //      2
        "DEF",      //      3
        "GHI",      //      4
        "JKL",      //      5
        "MNO",      //      6
        "PQRS",     //      7
        "TUV",      //      8
        "WXYZ",     //      9  
    };
    print(s,num,output,n);
    return 0;
}
