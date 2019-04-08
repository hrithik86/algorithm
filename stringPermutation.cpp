/*Permuatations of a string
 I/P:       ABC
 
 O/P:       ABC
            ACB
            BAC
            BCA
            CBA
            CAB
 
*/
#include <bits/stdc++.h>
using namespace std;
set<string> ss;

void findper(char input[100],char output[100],int i=0,int j=0){
    
    if(input[i]=='\0'){
        output[j]='\0';
        string s(output);
        ss.insert(s);
        // cout<<output<<endl;
        return;
    }

    for(int k=i;input[k]!='\0';k++){
        swap(input[i],input[k]);            //swap() is a built in function, use call by reference
        output[j]=input[i];
        findper(input,output,i+1,j+1);
        //backtracking - restoring original array
        swap(input[i],input[k]);
    }
    
    return;
}

int main()
{   char output[100];
    char input[100]="AABC";
    findper(input,output);
    for(auto it=ss.begin();it!=ss.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}

