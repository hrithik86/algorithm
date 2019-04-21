#include <iostream>
#include <string.h>
using namespace std;

void reverse(char str[],int len,int i=0){
    char temp;
    if(i>=len/2){
        puts(str);
        return;
    }
    temp=str[i];
    str[i]=str[len-i];
    str[len-i]=temp;
    reverse(str,len,i+1);
    return;
}

int main()
{
    char str[]="margorp emosewa";
    int len=strlen(str);
    reverse(str,len-1);
    return 0;
}
