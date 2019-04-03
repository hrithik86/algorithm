/* The numebers are mapped as
 1 - A
 2 - B
 3 - C
 .
 .
 26 - Z
print all the possible combinations for given a integer. 
*/
#include <iostream>
using namespace std;

int i,j;

void printStrings(char input[],char output[],int i=0,int j=0){
    //base case
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    //Rec case- 2 options: 2 calls
    int digit=input[i]-'0';
    char ch=digit+64;
    output[j]=ch;
    printStrings(input,output,i+1,j+1);
    //2nd case taking 2 characters
    if(input[i+1]!='\0'){
        int secondDigit=input[i+1]-'0';
        int no=digit*10+secondDigit;
        if(no<=26){
            ch=64+no;
            output[j]=ch;
            printStrings(input,output,i+2,j+1);
        }
    }
}

int main()
{   char output[100];
    char input[100]="123";
    printStrings(input,output,i,j);
    return 0;
}
