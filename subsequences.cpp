//Program to print subsequences of a string using recursion
#include <bits/stdc++.h>
using namespace std;

void subsequences(char input[],char output[],vector<string> &vs,int i=0,int j=0){
    //Base case
    if(input[i]=='\0'){
        output[j]='\0';
        string s(output);			//char first needs to be converted into string then pushed into vector
		vs.push_back(output);    
//      cout<<output<<endl;
        return;
    }
    //Recurcive case
    //Include the ith character
    output[j]=input[i];
    subsequences(input,output,vs,i+1,j+1);
    //Exclude the ith character
    subsequences(input,output,vs,i+1,j);
}

int main()
{	vector<string> vs;
    char input[]="abc";
    char output[10];
    subsequences(input,output,vs);
    sort(vs.begin(),vs.end());
    for(int i=0;i<vs.size();i++)
    cout<<vs[i]<<endl;
    return 0;
}
