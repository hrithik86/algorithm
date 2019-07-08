//reverse a stack using recursion

#include <bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int >&s,int no){
    if(s.empty()){
        s.push(no);
        return;
    }
    int t=s.top();
    s.pop();
    pushAtBottom(s,no);
    s.push(t);
}

void reverse(stack <int >&s){
    //base case
    if(s.size()==0){
        return;
    }
    //rec case
    int top=s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s,top);
}

void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}

int main()
{
    stack<int> s;
    for(int i=1;i<=5;i++){
        s.push(i);
    }
    reverse(s);
    print(s);
    return 0;
}
