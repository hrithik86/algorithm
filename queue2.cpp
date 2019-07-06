//cirular queue
//array implementation of queue (in case of circular array)

#include <iostream>
using namespace std;

class queue{
    int front=-1;
    int rear=-1;
    static const int N=5;
    int a[N];
public:
    void enqueue(int data){
        if((rear+1)%N==front){
            cout<<"Overflow"<<endl;     //full queue
            return;
        }
        else if(rear==-1){               //first insertion:both rear & front incremented
            front=(front+1)%N;
        }
        rear=(rear+1)%N;
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
        else front=(front+1)%N;
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
        if((rear+1)%N==front){
            return true;
        }
        return false;
    }
    void print() 
    { 
        if (front == -1) 
        { 
            cout<<"\nQueue is Empty"; 
            return; 
        } 
        cout<<"\nCircular Queue: "; 
        if (rear >= front) 
        { 
            for (int i = front; i <= rear; i++) 
                cout<<a[i]<<" "; 
        } 
        else
        { 
            for (int i = front; i < N; i++) 
                cout<<a[i]<<" "; 
      
            for (int i = 0; i <= rear; i++) 
                cout<<a[i]<<" "; 
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
    q.dequeue();q.print();
    q.enqueue(40);q.print();
    return 0;
}
