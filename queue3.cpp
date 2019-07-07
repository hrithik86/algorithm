//linked list implementation of queue
#include <iostream>
using namespace std;

struct node{
    int data;
    node*link;
};

class queue{
    node*front=NULL;
    node*rear=NULL;
public:
    void enqueue(int d){
        node*temp=new node();
        temp->data=d;
        if(isEmpty()){      
            front = temp;
            rear=temp;
            temp->link=NULL;
            return;
        }
        rear->link=temp;
        rear=temp;
        temp->link=NULL;
    }
    void dequeue(){
        if(isEmpty()){                      
            cout<<"Underflow"<<endl;
            return;
        }
        else if(front==rear){
            front=NULL;
            rear=NULL;
        }
        node*temp=front;
        front=front->link;
        delete (temp);
    }
    void print(){
        node*temp=front;
        cout<<"\nQueue: ";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->link;
        }
    }
    bool isEmpty(){
        if(front==NULL && rear==NULL){
            return true;
        }
        return false;
    }
    int Front(){
        return front->data;
    }
};

int main()
{
    queue q;
    // if(q.isEmpty()){
    //     cout<<"empty";
    // }
    q.enqueue(1);q.print();
    q.enqueue(2);q.print();
    q.enqueue(3);q.print();
    q.dequeue();q.print();
    q.enqueue(4);q.print();
    q.enqueue(5);q.print();
    q.enqueue(6);q.print();
    // if(q.isEmpty()){
    //     cout<<"empty";
    // }
    return 0;
}
