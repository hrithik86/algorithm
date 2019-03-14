//Program to print subsequences of a string using recursion
#include <iostream>
using namespace std;

void subsequences(char input[],char output[],int i=0,int j=0){
    //Base case
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    //Recurcive case
    //Include the ith character
    output[j]=input[i];
    subsequences(input,output,i+1,j+1);
    //Exclude the ith character
    subsequences(input,output,i+1,j);
}

int main()
{
    char input[]="abc";
    char output[10];
    subsequences(input,output);
    return 0;
}
