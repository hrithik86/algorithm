//writing own strtok function
#include <bits/stdc++.h>
using namespace std;

char*myStrtok(char*str,char delim){
    int i;
    static char* input=NULL;
    if(str!=NULL){
        input=str;
    }
    if(input==NULL){
        return NULL;
    }
    char*output=new char[strlen(input)+1] ;
    for(i=0;input[i]!='\0';i++){
        if(input[i]!=delim){
            output[i]=input[i];
        }
        else{
            //Delim
            output[i]='\0';
            input=input+i+1;
            return output;
        } 
    }
    output[i]=NULL;
    input=NULL;
    return output;
}

int main()
{
    char str[100]="Hey, this is something new";
    char*token=myStrtok(str,' ');
    
    while(token!=NULL){
        cout<<token<<endl;
        token=myStrtok(NULL,' ');
    }
  
    return 0;
}
