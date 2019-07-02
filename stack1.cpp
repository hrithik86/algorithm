//array implementation of stacks
#include <iostream>
using namespace std;

class Stack{
    int A[5];
    int top=-1;
public:
    void push(int x){
        if(top==4){
            cout<<"\nOverflow"<<endl;
            return;
        }
        top++;
        A[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"\nUnderflow"<<endl;
            return;
        }
        top--;
    }
    int Top(){
        return A[top];
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    void print(){
        cout<<"\nstack: ";
        for(int i=0;i<=top;i++){
            cout<<A[i]<<" ";
        }
    }
};

int main()
{
    Stack s;
    s.pop();
    s.push(10);s.print();
    s.push(8);s.print();
    s.push(9);s.print();
    s.push(4);s.print();
    s.push(5);s.print();
    s.push(5);s.print();
    return 0;
}
