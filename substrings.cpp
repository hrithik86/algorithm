#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[]="abcdef";char str1[100];int k,i,j,m;
    int len=strlen(str);
    for(i=0;i<len;i++){
        for(j=i;j<len;j++){
            m=0;
            for(k=i;k<=j;k++){
                str1[m]=str[k];
                m++;
            }
            str1[m]='\0';
            cout<<str1<<endl;
        }
    }
    return 0;
}
