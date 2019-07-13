//redundant parenthesis problem
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool check(char str[20],int n,stack<char>s){
    for(int i=0;i<n;i++){
        if(str[i]==']'){
            int i=0;
            while(s.top()!='['){
                s.pop();
                i++;
            }
            s.pop();
            if(i==0) return false;
        }
        else if(str[i]==')'){
            int i=0;
            while(s.top()!='('){
                s.pop();
                i++;
            }
            s.pop();
            if(i==0) return false;
        }
        else if(str[i]=='}'){
            int i=0;
            while(s.top()!='{'){
                s.pop();
                i++;
            }
            s.pop();
            if(i==0) return false;
        }
        else s.push(str[i]);
    }
    return true;
}


int main()
{   
    stack<char> s;
    char str[]="((a+b)+[(c+d)])";
    int n=strlen(str);
    if(check(str,n,s)){
        cout<<"Not Redundant"<<endl;
    }
    else cout<<"Redundant"<<endl;
    return 0;
}
