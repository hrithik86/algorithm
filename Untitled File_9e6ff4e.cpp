//Replacing pi in a character string with 3.14 using recursion
#include <iostream>
using namespace std;

void replacePi(char *a,int i){
    if(a[i]=='\0')
        return;
    if((a[i]=='p')&&(a[i+1]=='i')){
        int j=i+2;
        while(a[j]!='\0'){
            j++;
        }
        while(j>=i+2){
            a[j+2]=a[j];
            j--;
        }
        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';
        replacePi(a,i+4);
    }
    else{
        replacePi(a,i+1);
    }
}

int main()
{
    char a[100];
    cin>>a;
    replacePi(a,0);
    cout<<a;
    return 0;
}
