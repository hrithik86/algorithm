//finding subsequences of a string by masking bits 
#include <bits/stdc++.h>
using namespace std;

void mask(char input[],int n){
    int i=0;
    for(;n>0;n=n>>1){
        if(n&1){        // if n is odd
            cout<<input[i];
        }
        i++;
    }
    cout<<endl;
    return ;
}

int main()
{
    char input[100]="abc";
    cin>>input;
    int n=strlen(input);
    for(int i=0;i<(1<<n);i++){          // (a<<b) gives a*(2^b) 
        mask(input,i);
    }
    return 0;
}
