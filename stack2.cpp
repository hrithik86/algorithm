//linked list implementation of stacks
#include <iostream>
using namespace std;

struct node{
    int data;
    node*link;
};

class Stack{
    node*top=NULL;
public:
    void push(int x){
        node*temp=new node();
        temp->data=x;
        temp->link=top;
        top=temp;
    }
    void pop(){
        if(top==NULL){
            return;
        }
        node*temp=top;
        top=temp->link;
        delete temp;
    }
    int Top(){
        return top->data;
    }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        return false;
    }
    void print(){
        node*temp=top;
        cout<<"Linked list is: ";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->link;
        }
        cout<<endl;
    }
};

int main()
{
    Stack s;
    s.pop();
    s.push(10);s.print();
    s.push(8);s.print();
    s.pop();
    s.push(9);s.print();
    s.push(4);s.print();
    s.push(5);s.print();
    s.push(5);s.print();
    return 0;
}
