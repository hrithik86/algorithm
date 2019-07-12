//balanced parenthesis problem
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool check(char str[20],int n,stack<char>s){
    for(int i=0;i<n;i++){
        if(str[i]=='[' || str[i]=='(' || str[i]=='{'){
            s.push(str[i]);
        }
        else if(str[i]==']' || str[i]==')' || str[i]=='}'){
            if(s.empty()){
                return false;
            }
            if((s.top()=='[' && str[i]==']')||(s.top()=='(' && str[i]==')')||(s.top()=='{' && str[i]=='}')){
                s.pop();
            }
            else return false;
        }
    }
    if(!s.empty()){
        return false;
    }
    return true;
}


int main()
{   
    stack<char> s;
    char str[]="((())";
    int n=strlen(str);
    if(check(str,n,s)){
        cout<<"Balanced"<<endl;
    }
    else cout<<"Unbalanced"<<endl;
    return 0;
}
