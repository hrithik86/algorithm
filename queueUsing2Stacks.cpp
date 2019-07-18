//Implementing Queue using 2 stacks

#include <iostream>
#include <stack>
using namespace std;

class Queue{
    stack<int>s1;
    stack<int>s2;
public:
    void push(int data){
        s1.push(data);
    }
    int pop(){
        if(s1.empty()){
            cout<<"Underflow"<<endl;
            return -1;
        }
        while(!s1.empty()){
            int t=s1.top();
            s1.pop();
            s2.push(t);
        }
        int x= s2.top();
        s2.pop();
        while(!s2.empty()){
            int t=s2.top();
            s2.pop();
            s1.push(t);
        }
        return x;
    }
    int back(){
        return s1.top();
    }
};


int main()
{
    Queue q;
    for(int i=1;i<=3;i++)
        q.push(i);

    cout<<q.pop();
    cout<<q.pop();
    return 0;
}
