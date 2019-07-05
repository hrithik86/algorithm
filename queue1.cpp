//array implementation of queue
//insertion at rear and deletion at front
#include <iostream>
using namespace std;

class queue{
    int front=-1;
    int rear=-1;
    static const int maxSize=5;
    int a[maxSize];
public:
    void enqueue(int data){
        if(rear==maxSize-1){
            cout<<"Overflow"<<endl;     //full queue
            return;
        }
        else if(rear==-1){               //first insertion:both rear & front incremented
            front++;
        }
        rear++;
        a[rear]=data;
    }
    void dequeue(){
        if(front==-1){                  //empty queue
            cout<<"Underflow"<<endl;
            return;
        }
        else if(front==rear){           //only one element present
            front=-1;rear=-1;
        }
        else front++;
        cout<<"\nDeleted\n";
    }
    int Front(){
        return a[front];
    }
    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(rear==maxSize-1){
            return true;
        }
        return false;
    }
    void print(){
        if(!isEmpty()){
            cout<<"\nQueue: ";
            for(int i=front;i<=rear;i++){
                cout<<a[i]<<" ";
            }
        }
    }
};

int main()
{
    queue q;
    q.enqueue(5);q.print();
    q.enqueue(10);q.print();
    q.enqueue(20);q.print();
    q.enqueue(30);q.print();
    q.enqueue(40);q.print();
    while(!q.isEmpty()){
        q.dequeue();
    }
    q.enqueue(1);q.print();
    q.enqueue(2);q.print();
    return 0;
}
